#!/usr/bin/env python3

from lib import createCmakeFile, autoGenerateBindings


def main():
    autoGenerateBindings()
    createCmakeFile()


if __name__ == '__main__':
    main()
