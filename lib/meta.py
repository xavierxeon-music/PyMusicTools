#!/usr/bin/env python3

def clean(data, frontRemoval, endDelimeter):
    for remove in frontRemoval:
        data = data.replace(remove, '')
    index = data.find(endDelimeter)
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

    def __init__(self, content, name, parent):

        self.name = name
        self.parent = parent

        self.pyName = name.lower().replace('::', '_') if name else None
        self.cppName = name

        self.isNamespace = False

        if parent:
            if parent.pyName:
                self.pyName = parent.pyName + '_' + self.pyName
            if parent.cppName:
                self.cppName = parent.cppName + '::' + self.cppName
            if parent.isNamespace:
                self.name = parent.name + self.name

        self._subMeta = list()

        self._enums = list()
        self._functions = list()
        self._properties = list()

        self._parse(content)

    def _parse(self, content):

        iterator = iter(content)
        for line in iterator:

            if 'pyexport namespace' in line:
                name = clean(line, ['pyexport', 'namespace'], ':')
                subContent = parseSubContent(iterator)
                subMeta = Meta(subContent, name, self)
                subMeta.isNamespace = True
                self._subMeta.append(subMeta)
            elif 'pyexport class' in line:
                name = clean(line, ['pyexport', 'class'], ': public')
                subContent = parseSubContent(iterator)
                subMeta = Meta(subContent, name, self)
                self._subMeta.append(subMeta)
            elif 'pyexport struct' in line:
                name = clean(line, ['pyexport', 'struct'], ':')
                subContent = parseSubContent(iterator)
                subMeta = Meta(subContent, name, self)
                self._subMeta.append(subMeta)
            elif 'pyexport enum' in line:
                name = clean(line, ['pyexport', 'enum', 'class'], ':')
                subContent = parseSubContent(iterator)
                lineDict = self._createEnumDict(name, subContent)
                self._enums.append(lineDict)
            elif 'pyexport' in line:
                line = line.strip()
                openIndex = line.find('(')
                if 0 >= openIndex:
                    lineDict = self._createPropertyDict(line)
                    self._properties.append(lineDict)
                else:
                    lineDict = self._createFunctionDict(line)
                    self._functions.append(lineDict)

    def _createEnumDict(self, name, subContent):

        subContent = [clean(data, [], '=') for data in subContent]
        subContent = [clean(data, [], ',') for data in subContent]
        subContent = [data for data in subContent if data]

        return {'name': name, 'values': subContent}

    def _createFunctionDict(self, line):

        openIndex = line.find('(')
        name = line[:openIndex]
        name = name.strip()

        spaceIndex = name.rfind(' ')
        name = name[spaceIndex:]
        name = name.strip()

        isStatic = ('static' in line)
        if self.name:
            constructorName = self.name
            index = constructorName.rfind('::')
            if index >= 0:
                constructorName = constructorName[index+2:]
            isConstructor = (name == constructorName)
        else:
            isConstructor = False

        def removeLast(data):
            spaceIndex = data.rfind(' ')
            if 0 <= spaceIndex:
                data = data[:spaceIndex]
            return data

        arguments = str()
        if isConstructor:
            closeIndex = line.rfind(')')
            argsContent = line[openIndex + 1: closeIndex].strip()
            if argsContent:
                argsContent = argsContent.split(',')
                argsContent = [clean(data, [], '=') for data in argsContent]
                argsContent = [removeLast(data) for data in argsContent]
                arguments = ','.join(argsContent)

        return {'name': name, 'static': isStatic, 'constructor': isConstructor, 'arguments': arguments}

    def _createPropertyDict(self, line):

        openIndex = line.find(';')
        name = line[:openIndex]

        equalIndex = line.rfind('=')
        if 0 <= equalIndex:
            name = name[:equalIndex]

        name = name.strip()

        spaceIndex = name.rfind(' ')
        name = name[spaceIndex:]
        name = name.strip()

        isStatic = ('static' in line)
        isConst = ('const' in line)

        return {'name': name, 'static': isStatic, 'const': isConst}

    def compileConstructor(self):

        content = list()

        if self.name and not self.isNamespace:
            pyParent = self.parent.pyName if self.parent and not self.parent.isNamespace else None
            if not pyParent:
                pyParent = 'module'

            name = self.name.replace('::', '')
            content.append(f'pybind11::class_<{self.cppName}> {self.pyName}({pyParent}, "{name}");')

            arguments = str()
            for entry in self._functions:
                funcName = entry['name']
                if not entry['constructor']:
                    continue
                arguments = entry['arguments']

            content.append(f'{self.pyName}.def(pybind11::init<{arguments}>());')
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
            pyParent = self.parent.pyName if self.parent else None
            if not pyParent:
                pyParent = 'module'
            content.append(f'pybind11::enum_<{self.cppName}::{eName}> {eVarName}({pyParent}, "{self.name + eName}");')
            for value in entry['values']:
                content.append(f'{eVarName}.value("{value}", {self.cppName}::{eName}::{value});')
            content.append(f'{eVarName}.export_values();')
            content.append('')

        for entry in self._subMeta:
            for subContent in entry.compileOther():
                content.append(subContent)

        for entry in self._properties:
            propertyName = entry['name']
            if entry['static']:
                if entry['const']:
                    content.append(f'{self.pyName}.def_readonly_static("{propertyName}", &{self.cppName}::{propertyName});')
                else:
                    content.append(f'{self.pyName}.def_readwrite_static("{propertyName}", &{self.cppName}::{propertyName});')
            else:
                if entry['const']:
                    content.append(f'{self.pyName}.def_readonly("{propertyName}", &{self.cppName}::{propertyName});')
                else:
                    content.append(f'{self.pyName}.def_readwrite("{propertyName}", &{self.cppName}::{propertyName});')

        if self._properties:
            content.append('')

        for entry in self._functions:
            funcName = entry['name']
            if entry['constructor']:
                continue
            if entry['static']:
                content.append(f'{self.pyName}.def_static("{funcName}", &{self.cppName}::{funcName});')
            else:
                content.append(f'{self.pyName}.def("{funcName}", &{self.cppName}::{funcName});')

        return content
