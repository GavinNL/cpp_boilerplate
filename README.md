# C++ Boilerplate

| Branch      | Gitlab-CI  | Travis-CI | Appveyor | CodeCov | Codacy |
|-----------|-----------------------------------------------------------------------------------------------------------------|
| master    | [![Build Status](https://gitlab.com/GavinNL/cpp_boilerplate/badges/master/build.svg)](https://gitlab.com/GavinNL/cpp_boilerplate/pipelines/)| [![Build Status](https://travis-ci.org/GavinNL/cpp_boilerplate.svg?branch=master)](https://travis-ci.org/GavinNL/cpp_boilerplate)| [![Build status](https://ci.appveyor.com/api/projects/status/0tsak73ak5c2mhbu/branch/master?svg=true)](https://ci.appveyor.com/project/GavinNL/cpp-boilerplate/branch/master) | [![codecov](https://codecov.io/gh/GavinNL/cpp_boilerplate/branch/master/graph/badge.svg)](https://codecov.io/gh/GavinNL/cpp_boilerplate)| ![Codacy branch grade](https://img.shields.io/codacy/grade/4fe50de6102e4d678bacdd292c949310/master.svg) |
| dev       | [![Build Status](https://gitlab.com/GavinNL/cpp_boilerplate/badges/dev/build.svg)](https://gitlab.com/GavinNL/cpp_boilerplate/pipelines/) | [![Build Status](https://travis-ci.org/GavinNL/cpp_boilerplate.svg?branch=dev)](https://travis-ci.org/GavinNL/cpp_boilerplate)| [![Build status](https://ci.appveyor.com/api/projects/status/0tsak73ak5c2mhbu/branch/dev?svg=true)](https://ci.appveyor.com/project/GavinNL/cpp-boilerplate/branch/dev) |  [![codecov](https://codecov.io/gh/GavinNL/cpp_boilerplate/branch/dev/graph/badge.svg)](https://codecov.io/gh/GavinNL/cpp_boilerplate) | ![Codacy branch grade](https://img.shields.io/codacy/grade/4fe50de6102e4d678bacdd292c949310/dev.svg) |

This repo is a boilerplate for your C++ projects. This includes Continuous Integration scripts for Travis-ci, Appveyor and Gitlab-CI.

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
| src/lib   | Source code for your libraries. All subfolders will be compiled into its own library |
| src/bin   | Source code for your executables. All subfolders will be compiled into executables and linked with the libraries in src/lib |
| test/src/ | All unit tests. Each unit test starts with `unit-`. Unit tests are automatically compiled an executed when Travis CI executes the build  |

### Custom CMakeLists.txt files

The subfolders that reside within `src/lib` and `src/bin` will be compiled automatically. If you need a custom CMakeLists.txt file, simply
add the CmakeLists.txt file into the library's or executable's folder and it will automatically be included.

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

## Continuous Integration

Continuous Integration scripts are provided for Travis-CI, Appveyor and Gitlab Pipelines.

### Gitlab

The Gitlab pipeline will run two stages. The first stage is a CPP-Check stage which will generate a cppcheck report and html document and export it as build stage artifact.

* clang3.8
* clang 3.9
* clang 4.0
* clang 5.0
* clang 6.0
* gcc 5
* gcc 6
* gcc 7

The Docker images which are used come pre-installed with the Conan Package Manger and are provided by  https://hub.docker.com/u/lasote

### Travis-CI

The Travis-CI builds execute on the following platforms/compilers

* Mac XCode LLVM 8.3
* Mac XCode LLVM 9.4
* Mac XCode LLVM 10
* Linux clang 5.0
* Linux clang 6.0
* Linux clang 7.0
* Linux gcc 5
* Linux gcc 6
* Linux gcc 7
* Windows Visual Studio 2017

### Appveyor

Info coming soon. May be deprecated in favour of Travis-CI's windows builds.


## Unit Testing

All unit tests are performed using the Catch2 library. A copy of the Catch2 headers are provided in the `test/third_party` folder.

To add a C++ unit test to your project. Simply make a copy one of the sample unit tests in the `test/src/` folder. All unit tests start with `unit-`.

Unit tests are automatically compiled by default, but you can turn off compiling of unit testing by adding the following flag to your cmake command

```
cmake .. -DCPPBOILERPLATE_BUILD_TESTS:BOOL=FALSE
```

## Code Coverage

Code Coverage is performed by compiling the library with the Code Coverage flag
turned on and then executing the unit test. It is therefore necessary to have both flags turned on to perform code coverage analysis of your unit tests.

```
cmake .. -DCPPBOILERPLATE_ENABLE_COVERAGE:BOOL=TRUE -DCPPBOILERPLATE_BUILD_TESTS:BOOL=TRUE
```

Travis will automatically upload the code coverage reports to codecov.io. It is currently enabled on a single build instance. You only need to have it execute on one build instance.

To enable code coverage, add `- RUN_CODECOV=TRUE` to the `env` section of a single build in `.travis.yaml`. Then enable your repository in your codecov.io account


## Code Quality with Codacy

[Codacy](https://www.codacy.com/) is used to analyse the quality of your code. Enable it for your repository in your Codeacy account to get a report
