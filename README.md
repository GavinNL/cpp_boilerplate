# cpp_boilerplate

Master:
[![Build Status](https://travis-ci.org/GavinNL/cpp_boilerplate.svg?branch=master)](https://travis-ci.org/GavinNL/cpp_boilerplate)
[![Build status](https://ci.appveyor.com/api/projects/status/0tsak73ak5c2mhbu/branch/master?svg=true)](https://ci.appveyor.com/project/GavinNL/cpp-boilerplate/branch/master)
[![codecov](https://codecov.io/gh/GavinNL/cpp_boilerplate/branch/master/graph/badge.svg)](https://codecov.io/gh/GavinNL/cpp_boilerplate)
![Codacy branch grade](https://img.shields.io/codacy/grade/4fe50de6102e4d678bacdd292c949310/master.svg)

Dev:
[![Build Status](https://travis-ci.org/GavinNL/cpp_boilerplate.svg?branch=dev)](https://travis-ci.org/GavinNL/cpp_boilerplate)
[![Build status](https://ci.appveyor.com/api/projects/status/0tsak73ak5c2mhbu/branch/dev?svg=true)](https://ci.appveyor.com/project/GavinNL/cpp-boilerplate/branch/dev)
[![codecov](https://codecov.io/gh/GavinNL/cpp_boilerplate/branch/dev/graph/badge.svg)](https://codecov.io/gh/GavinNL/cpp_boilerplate)
![Codacy branch grade](https://img.shields.io/codacy/grade/4fe50de6102e4d678bacdd292c949310/dev.svg)

This repo is a boilerplate for your C++ projects. This includes Continious Integration scripts for travis-ci, appveyor and gitlab.

# Quick Start

1. First clone the repo and get initialize it so that you can start developing
your own library/application

  ```
  git clone https://github.com/GavinNL/cpp_boilerplate my_cpp_project

  cd my_cpp_project

  # This renames all occurances of CPPBOILERPLATE in the Cmake files to
  # MYCPPPROJECT. You should use something unique and all CAPS
  sh ./rename_library MYCPPPROJECT

  # Optional: delete the git directory so you don't get the history
  rm -rf .git

  # Re-initialize your git repo
  git init

  # Test the build system
  mkdir build
  cd build
  conan install --build missing ..
  cmake ..
  cmake --build .

  ```

2. Edit (or delete) the `conanfile.txt` file with the dependencies you wish to
use for your library/application

3. Update the links to the travis-ci/appveyor/codecov badges in the README.md file

4. Start developing your project (See Source Code File Structure)

# Features
 *  Multiple library modules
 *  Unit testing template
 *  Conan Package Manager Integration
 *  Continuous Integration with [Travis-CI](https://travis-ci.org) and [Appveyor](https://ci.appveyor.com/)
 *  Code Coverage with gcov and [codecov.io](https://codecov.io)
 *  Code Quality with [codacy](https://app.codacy.com)



## Source Code File Structure.

| Path      | Description  |
|-----------|-------------------------------------------------------------------------------------------------------------------------------------------------------------|
| include/  | Header files for your project. This folder is added as an include path to your project. If your header is `include/MYLIBRARY/mylibheader.h` Your source code should include header using: `#include<MYLIBRARY/mylibheader.h>` |
| src/      | Source code for your library. All `.cpp` files should be stored here. Each folder is compiled into a separate library (either shared or static). Eg: `src/mylib/` is compiled into `libmylib.a` or `libmylib.so` |
| examples/ | Source code for your executables. Each sub folder is compiled into an executable and linked with all libraries in the `src/` folder. |
| test/src/ | All unit tests. Each unit test starts with `unit-`. Unit tests are automatically compiled an executed when Travis CI executes the build  |

## Third Party Dependencies

Dependencies are handled through the Conan Package Manager. During Continuous Integration, the `conanfile.txt` is read and the dependencies are installed.

If you have the [Conan Package Manager](http://conan.io) installed, you can download all dependencies listed in your `conanfile.txt` by using the following:
```
cd $PROJECT_SRC_FOLDER
mkdir build
conan install --build missing ..
cmake ..
cmake --build .
```

If you choose not to use Conan, then you must have the dependencies in your system path. You should still list your packages in the `conanfile.txt` so that the CI system can build and test your library.

## Continious Integration

Continious Integration scripts are provided for Travis-CI, Appveyor and Gitlab Pipelines.

### Gitlab

The Gitlab pipeline will run two stages. The first stage is a CodeCoverage stage which will test the code coverage of your software. The second stage compiles runs all unit tests. The test is compiled on the following compilers through docker:

* clang3.8
* clang 3.9
* clang 4.0
* clang 5.0
* clang 6.0
* gcc 5
* gcc 6
* gcc 8

The Docker images which are used come pre-installed with the conan package manger and are provided by  https://hub.docker.com/u/lasote

### Travis-CI

Info coming soon.

### Appveyor

Info coming soon.


## Unit Testing

All unit tests are performed using the Catch2 library. A copy of the Catch2 headers are provided in the `test/third_party` folder.

To add a C++ unit test to your project. Simply make a copy one of the sample unit tests in the `test/src/` folder. All unit tests start with `unit-`.

Unit tests are automatically compiled by default, but you can turn off compiling of unit testing by adding the following flag to your cmake command

```
cmake .. -DCPPBOILERPLATE_USE_CONAN:BOOL=TRUE  -DCPPBOILERPLATE_BUILD_TESTS:BOOL=FALSE
```

## Code Coverage

Code Coverage is performed by compiling the library with the Code Coverage flag
turned on and then executing the unit test. It is therefore necessary to have both flags turned on to perform code coverage analysis of your unit tests.

```
cmake .. -DCPPBOILERPLATE_USE_CONAN:BOOL=TRUE  -DCPPBOILERPLATE_ENABLE_COVERAGE:BOOL=TRUE -DCPPBOILERPLATE_BUILD_TESTS:BOOL=FALSE
```

Travis will automatically upload the code coverage reports to codecov.io. It is currently enabled on a single build instance. You only need to have it execute on one build instance.

To enable code coverage, add `- RUN_CODECOV=TRUE` to the `env` section of a single build in `.travis.yaml`. Then enable your repository in your codecov.io account


## CI with Travis

Log into your Travis-CI account and enable CI for your repo. It will automatically pull the code, compile it and run the unit tests and code coverage tests. Modify the `.travis.yaml` file for your specific needs. The default behaviour is to run the build on the following architectures:

|Linux      |  Mac                  | Windows    |
|-----------|-----------------------|------------|
|gcc-4.8    |  Apple LLVM clang 7   | VS 2017    |
|gcc-4.9    |  Apple LLVM clang 8   | VS 2015    |
|gcc-5      |  Apple LLVM clang 9   |            |
|gcc-6      |  Apple LLVM clang 10  |            |
|gcc-7      |                       |            |
|gcc-8      |                       |            |
|clang-3.5  |                       |            |
|clang-3.6  |                       |            |
|clang-3.7  |                       |            |
|clang-3.8  |                       |            |
|clang-3.9  |                       |            |
|clang-4.0  |                       |            |
|clang-5.0  |                       |            |
|clang-6.0  |                       |            |

## Code Quality with Codacy

[Codacy](https://www.codacy.com/) is used to analyse the quality of your code. Enable it for your repository in your Codeacy account to get a report
