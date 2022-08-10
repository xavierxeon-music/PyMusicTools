#!/usr/bin/env

import os

from .meta import Meta

_scriptPath = os.path.realpath(__file__)
_scriptPath = os.path.dirname(_scriptPath)
basePath = os.path.abspath(_scriptPath + '/../')


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
    with open(headerFileName, 'r') as infile:
        content = infile.readlines()
    meta = Meta(content, name, 'module')

    bindingFileName = basePath + '/python_bindings/' + path + '/py_' + name + '.cpp'
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


def autoGenerateBindings():
    headers = _compileCppHeaderDict()
    for name, path in headers.items():
        _update(name, path)