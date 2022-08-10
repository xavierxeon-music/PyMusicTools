#!/usr/bin/env python3

class Meta:

    def __init__(self, content, name, parent):

        self._name = name.replace('::', '')
        self._className = name
        self._varName = name.lower().replace("::", "_")
        self._parent = parent
        self._namespace = str()

        self._enums = list()
        self._functions = list()
        self._subMeta = list()

        self._parse(content)

        self._enums = [self._cleanEnum(line) for line in self._enums]
        self._functions = [self._cleanFunction(line) for line in self._functions]

    def _parse(self, content):

        iterator = iter(content)
        for line in iterator:
            if 'PYCLASS' in line:
                line = line.strip()
                line = line.replace('PYCLASS', '')
                line = line.replace('(', '')
                line = line.replace(')', '')
                line = line.strip()
                self._className = line
            elif 'PYNAMESPCE' in line:
                line = line.strip()
                line = line.replace('PYNAMESPCE', '')
                line = line.replace('(', '')
                line = line.replace(')', '')
                line = line.strip()
                self._namespace = line
            elif 'pyexport struct' in line:
                name = line
                name = name.replace('pyexport', '')
                name = name.replace('struct', '')
                name = name.strip()

                bracketCounter = 0
                while True:
                    subContent = next(iterator)
                    line += subContent
                    if '{' in subContent:
                        bracketCounter += 1
                    if '}' in subContent:
                        bracketCounter -= 1
                    if 0 == bracketCounter:
                        break

                openIndex = line.find('{')
                closeIndex = line.rfind('}')
                line = line[openIndex + 1: closeIndex]
                subMeta = Meta(line.split("\n"), f'{self._className}::{name}', self._varName)
                self._subMeta.append(subMeta)
            elif 'pyexport enum' in line:
                line = line.strip()
                while True:
                    subContent = next(iterator)
                    subContent = subContent.strip()
                    line += subContent
                    if ';' in subContent:
                        break
                self._enums.append(line)
            elif 'pyexport' in line:
                line = line.strip()
                self._functions.append(line)

    def _cleanEnum(self, line):

        openIndex = line.find('{')
        closeIndex = line.find('}')

        def clean(data, delimeter):
            index = data.find(delimeter)
            if index >= 0:
                data = data[:index]
            data = data.strip()
            return data

        content = line[openIndex + 1: closeIndex]
        content = content.split(',')
        content = [clean(data, '=') for data in content]
        content = [clean(data, '//') for data in content]
        content = [data for data in content if data]

        name = line[:openIndex]
        name = name.replace('pyexport', '')
        name = name.replace('enum', '')
        name = name.replace('class', '')
        name = clean(name, ':')

        return {'name': name, 'values': content}

    def _cleanFunction(self, line):

        openIndex = line.find('(')
        name = line[:openIndex]
        name = name.strip()

        spaceIndex = name.rfind(' ')
        name = name[spaceIndex:]
        name = name.strip()

        isStatic = ('static' in line)
        constructorName = self._className
        index = self._className.rfind('::')
        if index >= 0:
            constructorName = constructorName[index+2:]
        isConstructor = (name == constructorName)

        return {'name': name, 'static': isStatic, 'constructor': isConstructor}

    def compileConstructor(self):

        content = list()
        content.append(f'pybind11::class_<{self._className}> {self._varName}({self._parent}, "{self._name}");')

        args = str()
        for entry in self._functions:
            funcName = entry['name']
            if not entry['constructor']:
                continue
            break

        content.append(f'{self._varName}.def(pybind11::init<{args}>());')
        content.append('')

        for entry in self._subMeta:
            for subContent in entry.compileConstructor():
                content.append(subContent)

        return content

    def compileOther(self):

        content = list()

        for entry in self._enums:
            eName = entry['name']
            eVarName = eName.lower().replace("::", "_")
            content.append(f'pybind11::enum_<{self._className}::{eName}> {eVarName}({self._varName}, "{self._namespace + eName}");')
            for value in entry['values']:
                content.append(f'{eVarName}.value("{value}", {self._className}::{eName}::{value});')
            content.append(f'{eVarName}.export_values();')
            content.append('')

        for entry in self._subMeta:
            for subContent in entry.compileOther():
                content.append(subContent)

        for entry in self._functions:
            funcName = entry['name']
            if entry['constructor']:
                continue
            if entry['static']:
                content.append(f'{self._varName}.def_static("{funcName}", &{self._className}::{funcName});')
            else:
                content.append(f'{self._varName}.def("{funcName}", &{self._className}::{funcName});')

        return content
