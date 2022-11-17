#!/usr/bin/env

import os

from .meta import Meta

_scriptPath = os.path.realpath(__file__)
_scriptPath = os.path.dirname(_scriptPath)
basePath = os.path.abspath(_scriptPath + '/../')


class FileSearch:

    def __init__(self, includePath):

        pass


def _compileCppHeaderDict():

    headers = dict()

    includePath = basePath + '/MusicTools/Include'

    def checkFile(fileName):
        with open(fileName, 'r') as testfile:
            for line in testfile.readlines():
                if 'pyexport' in line:
                    return True
        return False

    def addHeaderFiles(path):
        for entry in os.scandir(path):
            if entry.is_dir():
                addHeaderFiles(entry.path)
                continue
            if entry.is_file() and not entry.name.endswith('.h'):
                continue
            if not checkFile(entry.path):
                continue

            path = os.path.dirname(entry.path)
            path = path.replace(includePath + '/', '')

            name = entry.name
            name = name.replace('.h', '')

            headers[name] = path

    addHeaderFiles(includePath)
    if 'MusicTools' in headers:
        del headers['MusicTools']

    return headers


def _update(name, path):

    headerFileName = basePath + '/MusicTools/Include/' + path + '/' + name + '.h'
    # print(headerFileName)

    content = list()
    with open(headerFileName, 'r') as infile:
        for line in infile.readlines():
            commentIndex = line.find('//')
            if 0 <= commentIndex:
                line = line[:commentIndex]
            line = line.strip()
            if line:
                content.append(line)

    meta = Meta(content, None, None)

    bindingFileName = basePath + '/python_bindings/' + path + '/py_' + name + '.cpp'
    os.makedirs(basePath + '/python_bindings/' + path, exist_ok=True)
    if not os.path.exists(bindingFileName):
        _createSkeleton(bindingFileName, name, path, meta.compileConstructor())

    preContent = str()
    postContent = str()

    preMode = True
    postMode = False
    with open(bindingFileName, 'r') as infile:
        for line in infile.readlines():
            if '// autogen end' in line:
                postMode = True

            if preMode:
                preContent += line
            elif postMode:
                postContent += line

            if '// autogen start' in line:
                preMode = False

    with open(bindingFileName, 'w') as outfile:
        outfile.write(preContent)
        for line in meta.compileOther():
            outfile.write('   ' + line + '\n')
        outfile.write(postContent)


def _createSkeleton(bindingFileName, name, path, content):

    with open(bindingFileName, 'w') as outfile:

        outfile.write('#include <pybind11/pybind11.h>\n')
        outfile.write('#include <pybind11/stl.h>\n')
        outfile.write('\n')
        outfile.write(f'#include <{path}/{name}.h>\n')
        outfile.write('\n')

        outfile.write(f'void init_{name}(pybind11::module_& module)\n')
        outfile.write('{\n')

        for line in content:
            outfile.write('   ' + line + '\n')
        outfile.write('\n')

        outfile.write('   // autogen start\n')
        outfile.write('   // autogen end\n')
        outfile.write('}\n')
        outfile.write('\n')


def _updateModelHeaderAndSource():

    sources = list()
    sourcePath = basePath + '/python_bindings'

    def addSourceFiles(path):
        for entry in os.scandir(path):
            if entry.is_dir():
                addSourceFiles(entry.path)
                continue
            if entry.is_file() and not entry.name.endswith('.cpp'):
                continue

            name = entry.name
            if not name.startswith('py_'):
                continue

            name = name.replace('py_', '')
            name = name.replace('.cpp', '')
            if 'MusicTools' == name:
                continue

            sources.append(name)

    addSourceFiles(sourcePath)
    sources.sort()

    with open(sourcePath + '/py_MusicTools.h', 'w') as outfile:
        for name in sources:
            outfile.write(f'extern void init_{name}(pybind11::module_& module);\n')

    with open(sourcePath + '/py_MusicTools.cpp', 'w') as outfile:
        outfile.write('#include <pybind11/pybind11.h>\n')
        outfile.write('\n')
        outfile.write('#ifndef MusicToolsH\n')
        outfile.write('#define MusicToolsH\n')
        outfile.write('#include "py_MusicTools.h"\n')
        outfile.write('#endif // NOT MusicToolsH\n')
        outfile.write('\n')
        outfile.write('PYBIND11_MODULE(musictools, module)\n')
        outfile.write('{\n')
        for name in sources:
            outfile.write(f'   init_{name}(module);\n')
        outfile.write('}\n')
        outfile.write('\n')


def autoGenerateBindings():

    headers = _compileCppHeaderDict()
    for name, path in headers.items():
        _update(name, path)

    _updateModelHeaderAndSource()
