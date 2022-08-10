#!/usr/bin/env python3

import platform
import os

_scriptPath = os.path.realpath(__file__)
_scriptPath = os.path.dirname(_scriptPath)
basePath = os.path.abspath(_scriptPath + '/../')

musicToolsDir = basePath + '/MusicTools'


def _compileCppSourceList():

    sources = ['AbstractEffect.cpp', 'AbstractOscilator.cpp', 'AbstractSoundSource.cpp', 'Maths.cpp', 'Note.cpp', 'Spectrum.cpp']
    sources = [musicToolsDir + '/' + entry for entry in sources]

    def addSourceFiles(path):
        for entry in os.scandir(path):
            if entry.is_dir():
                addSourceFiles(entry.path)
                continue
            if entry.is_file() and not entry.name.endswith('.cpp'):
                continue
            path = entry.path
            sources.append(path)

    addSourceFiles(basePath + '/python_bindings')

    return sources


def createCmakeFile():

    includeDirs = [musicToolsDir, musicToolsDir + '/Include', musicToolsDir + '/RememberDummy']

    with open(basePath + '/CMakeLists.txt', 'w') as cmakefile:
        cmakefile.write('cmake_minimum_required(VERSION 3.18)\n')
        cmakefile.write('project(musictools VERSION 1.0)\n')
        cmakefile.write('set(CMAKE_CXX_STANDARD 11)\n')
        cmakefile.write('set(CMAKE_CXX_STANDARD_REQUIRED True)\n')
        cmakefile.write('\n')

        cmakefile.write('find_package(pybind11 REQUIRED)\n')
        cmakefile.write('\n')

        cmakefile.write('add_compile_definitions(NON_DAISY_DEVICE PYBIND11_DETAILED_ERROR_MESSAGES)\n')
        cmakefile.write('\n')

        cmakefile.write('pybind11_add_module(musictools \n')
        for source in _compileCppSourceList():
            cmakefile.write('   ' + source + '\n')
        cmakefile.write(')\n')
        cmakefile.write('\n')

        cmakefile.write('target_include_directories(musictools PUBLIC \n')
        for dir in includeDirs:
            cmakefile.write('   ' + dir + '\n')
        cmakefile.write(')\n')
        cmakefile.write('\n')
