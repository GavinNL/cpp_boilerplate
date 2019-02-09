#!/bin/bash

if [ "$1" == "mingw" ]; then
CONAN_SETTINGS_COMPILER=gcc
CONAN_SETTINGS_COMPILER_VERSION=8.1
CONAN_SETTINGS_ARCH=x86_64
CMAKE_GENERATOR='Unix Makefiles'
elif [ "$1" == "vs" ]; then
CONAN_SETTINGS_COMPILER='Visual Studio'
CONAN_SETTINGS_COMPILER_VERSION=15
CONAN_SETTINGS_ARCH=x86_64
CMAKE_GENERATOR='Visual Studio 15 2017 Win64'
elif [ "$1" == "gcc" ]; then
CONAN_SETTINGS_COMPILER='gcc'
CONAN_SETTINGS_COMPILER_VERSION=7.3
CONAN_SETTINGS_ARCH=x86_64
CMAKE_GENERATOR='Unix Makefiles'
else
echo "Missing first paremter. Please select mingw, vs or gcc"
exit 1
fi
BUILD_CONFIG=Release

if [ -f "../conanfile.txt" ]; then
conan install .. --build missing -s compiler="$CONAN_SETTINGS_COMPILER" -s compiler.version=$CONAN_SETTINGS_COMPILER_VERSION -s arch=$CONAN_SETTINGS_ARCH
fi

cmake -D BUILD_SHARED_LIBS:BOOL=TRUE -D CPPBOILERPLATE_BUILD_TESTS:BOOL=TRUE -G "$CMAKE_GENERATOR"  ..
cmake --build . --config $BUILD_CONFIG

