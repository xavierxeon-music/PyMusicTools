#!/usr/bin/env python3

def cleanBack(data, delimeter):
    index = data.find(delimeter)
    if index >= 0:
        data = data[:index]
    data = data.strip()
    return data


def parseSubContent(iterator):

    subContent = list()
    bracketCounter = 0
    while True:
        line = next(iterator)
        subContent.append(line)
        if '{' in line:
            bracketCounter += 1
        if '}' in line:
            bracketCounter -= 1
        if 0 == bracketCounter:
            break

    if subContent[0].startswith('{'):
        subContent = subContent[1:]
    if subContent[-1].startswith('}'):
        subContent = subContent[:-1]

    return subContent


class Meta:

    def __init__(self, content,  name, cppParent, pyParent):

        self._name = name if name else str()
        self._cppParent = cppParent
        self._pyParent = pyParent

        self._enums = list()
        self._functions = list()
        self._properties = list()
        self._subMeta = list()

        self._parse(content)

    def _parse(self, content):

        iterator = iter(content)
        for line in iterator:

            def createSubMeta(marker):
                name = line
                name = name.replace('pyexport', '')
                name = name.replace(marker, '')
                name = cleanBack(name, ':')

                subContent = parseSubContent(iterator)

                subCppParent = f'{self._cppParent}::{name}' if self._cppParent else name
                subMeta = Meta(subContent, name, subCppParent, self._pyParent + '_' + name.lower())
                self._subMeta.append(subMeta)

            if 'pyexport namespace' in line:
                createSubMeta('namespace')
            elif 'pyexport class' in line:
                createSubMeta('class')
            elif 'pyexport struct' in line:
                createSubMeta('struct')
            """
            elif 'pyexport enum' in line:
                name = line
                name = name.replace('pyexport', '')
                name = name.replace('enum', '')
                name = name.replace('class', '')
                name = cleanBack(name, ':')

                subContent = parseSubContent(iterator)

                lineDict = self._complileEnumDict(name, subContent)
                self._enums.append(lineDict)
            elif 'pyexport' in line:
                line = line.strip()
                openIndex = line.find('(')
                if 0 >= openIndex:
                    lineDict = self._compilePropertyDict(line)
                    self._properties.append(lineDict)
                else:
                    lineDict = self._complileFunctionDict(line)
                    self._functions.append(lineDict)
            """

    def _complileEnumDict(self, name, subContent):

        subContent = [cleanBack(data, '=') for data in subContent]
        subContent = [cleanBack(data, ',') for data in subContent]
        subContent = [data for data in subContent if data]

        return {'name': name, 'values': subContent}

    def _complileFunctionDict(self, line):

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

    def _compilePropertyDict(self, line):

        openIndex = line.find(';')
        name = line[:openIndex]

        equalIndex = line.rfind('=')
        if 0 <= equalIndex:
            name = name[:equalIndex]

        name = name.strip()

        spaceIndex = name.rfind(' ')
        name = name[spaceIndex:]
        name = name.strip()

        return {'name': name}

    def compileConstructor(self):

        content = list()
        print(self._name, self._cppParent, self._pyParent)
        if self._name != '':
            pyName = self._pyParent + '_' + self._name
            fullCppName = f'{self._cppParent}::{self._name}' if self._cppParent else self._name
            content.append(f'pybind11::class_<{fullCppName}> {pyName}({self._pyParent}, "{self._name}");')

            args = str()
            for entry in self._functions:
                funcName = entry['name']
                if not entry['constructor']:
                    continue
                break

            content.append(f'{pyName}.def(pybind11::init<{args}>());')
            content.append('')

        for entry in self._subMeta:
            for subContent in entry.compileConstructor():
                content.append(subContent)

        return content

    def compileOther(self):

        content = list()
        """
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
                if content[-1:] != '' and subContent == '':
                    continue
                content.append(subContent)
            content.append('')

        for entry in self._properties:
            propertyName = entry['name']
            content.append(f'{self._varName}.def_readwrite("{propertyName}", &{self._className}::{propertyName});')

        if self._properties:
            content.append('')

        for entry in self._functions:
            funcName = entry['name']
            if entry['constructor']:
                continue
            if entry['static']:
                content.append(f'{self._varName}.def_static("{funcName}", &{self._className}::{funcName});')
            else:
                content.append(f'{self._varName}.def("{funcName}", &{self._className}::{funcName});')
        """
        return content
