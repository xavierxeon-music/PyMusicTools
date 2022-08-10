#!/usr/bin/env python3

import sys

from setuptools import setup

from lib import createCmakeFile, CMakeExtension, CMakeBuild


createCmakeFile()

setup(
    name='musictools',
    version='2.1',
    author="Ralf Waspe",
    author_email="rwaspe@me.com",
    description='Music Tools from PatchesOfDaisy',
    install_requires='pybind11',
    license='MIT',
    ext_modules=[CMakeExtension("musictools")],
    cmdclass={"build_ext": CMakeBuild},
    zip_safe=False,
    python_requires=">=3.6"
)
