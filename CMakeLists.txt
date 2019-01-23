#
# This CMake project is a boilerplate code for developing a C++ library
#
#
#
#
#
#
#
#
#
#


cmake_minimum_required(VERSION 3.8)

project(CPP_BOILERPLATE)

#CPPBOILERPLATE
set (CMAKE_CXX_STANDARD 11)


option(BUILD_SHARED_LIBS "Enable compilation of shared libraries" OFF)

option(CPPBOILERPLATE_ENABLE_COVERAGE "Enable Code Coverage flags" OFF)
option(CPPBOILERPLATE_BUILD_TESTS "Build Tests" ON)

#########################################################
FILE(GLOB TEXT_FILES  "*.yml" )
add_custom_target(ci_files    SOURCES ${TEXT_FILES} .travis/install.sh .travis/build.sh conanfile.txt)

FILE(GLOB README_FILES  "*.md" )
add_custom_target(readme    SOURCES ${README_FILES})
#########################################################

# Link this 'library' to use the following warnings
add_library(project_warnings INTERFACE)

#########################################################
# Add the main include folder for our library
#########################################################
set(CPPBOILERPLATE_INCLUDE ${PROJECT_SOURCE_DIR}/include)
#########################################################


if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    set(CONAN_SYSTEM_INCLUDES ON)
    conan_basic_setup()
    link_libraries(${CONAN_LIBS})
else()
    if(EXISTS ${CMAKE_SOURCE_DIR}/conanfile.txt)
        message( FATAL_ERROR
" A conanfile.txt file exists in the source directory\n"
" indicating conan is used for dependences but a conanbuildinfo.cmake\n"
" file does not exist. Make sure to execute:\n\n"
" conan install ${CMAKE_SOURCE_DIR} --build=missing -if ${CMAKE_BINARY_DIR}" )
    endif()

endif()

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)


#########################################################
# If we hhave enabled coverage, make sure to add the
# specific flags required to calculate the coverage
#########################################################
if(CPPBOILERPLATE_ENABLE_COVERAGE)

  if(CMAKE_COMPILER_IS_GNUCC)
    option(CPPBOILERPLATE_ENABLE_COVERAGE "Enable coverage reporting for gcc/clang" FALSE)

    add_compile_options(--coverage -g -O0 -fprofile-arcs -ftest-coverage)
  endif()

endif()
#########################################################

if(MSVC)
  target_compile_options(project_warnings INTERFACE /W4)
else()
    if (CMAKE_COMPILER_IS_GNUCC AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 7.1)
        add_compile_options(
                               -Wnon-virtual-dtor # warn the user if a class with virtual functions has a
                                                  # non-virtual destructor. This helps catch hard to
                                                  # track down memory errors
                               -Wold-style-cast # warn for c-style casts
                               -Wcast-align # warn for potential performance problem casts
                               -Wunused # warn on anything being unused
                               -Woverloaded-virtual # warn if you overload (not override) a virtual
                                                    # function
                               -Wpedantic # warn if non-standard C++ is used
                               -Wconversion # warn on type conversions that may lose data
                               -Wsign-conversion # warn on sign conversions
                               -Wmisleading-indentation # warn if identation implies blocks where blocks
                                                        # do not exist
                               -Wduplicated-cond # warn if if / else chain has duplicated conditions
                               -Wduplicated-branches # warn if if / else branches have duplicated code
                               -Wlogical-op # warn about logical operations being used where bitwise were
                                            # probably wanted
                               -Wnull-dereference # warn if a null dereference is detected
                               -Wuseless-cast # warn if you perform a cast to the same type
                               -Wdouble-promotion # warn if float is implicit promoted to double
                               -Wformat=2 # warn on security issues around functions that format output
                                          # (ie printf)
                               -Werror=return-type
                               )
    else()
        add_compile_options(
                               -Wnon-virtual-dtor # warn the user if a class with virtual functions has a
                                                  # non-virtual destructor. This helps catch hard to
                                                  # track down memory errors
                               -Wold-style-cast # warn for c-style casts
                               -Wcast-align # warn for potential performance problem casts
                               -Wunused # warn on anything being unused
                               -Woverloaded-virtual # warn if you overload (not override) a virtual
                                                    # function
                               -Wpedantic # warn if non-standard C++ is used
                               -Wconversion # warn on type conversions that may lose data
                               -Wsign-conversion # warn on sign conversions
                               -Wformat=2 # warn on security issues around functions that format output
                                          # (ie printf)
                               -Werror=return-type
                               )
    endif()

endif()






# Maros

#########################################################
# Macro to find all sub directories within a folder
#########################################################
MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()
#########################################################



######################
# Get a list of all the subdirectories in the src folder. Each of
# these subdirectories is compiled into its own library
# which will be linked with all unit tests
SUBDIRLIST(CPPBOILERPLATE_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/src/lib)


if(CPPBOILERPLATE_ENABLE_COVERAGE)
    set(CPPBOILERPLATE_COVERAGE_FLAGS "--coverage -g -O0 -fprofile-arcs -ftest-coverage")
    MESSAGE("Setting Coverage flags: ${CPPBOILERPLATE_COVERAGE_FLAGS} ")
endif()


if( ${CPPBOILERPLATE_BUILD_TESTS})
    enable_testing()
endif()

#########################################################
# Add the src sub directory. Each subdirectory within
# the src folder will be compiled into its own library
#
# The Src folder contains 2 sub folders: bin and lib
#
# All subfolders within the lib folder will be compiled
# into a library. Ideally each of these libraries
# should be independent and should not depend on
# each other.
#
# All subfolders within the bin folder will be compiled
# into an executable and linked with each of the sub
# folders in src/lib.
#########################################################
add_subdirectory(src)
#########################################################


#########################################################
# Add the test sub directory. This is where all unit tests
# will be stored. Each unit test will be compiled and
# linked with all the libraryes in the src/ folder
#########################################################
if( ${CPPBOILERPLATE_BUILD_TESTS})
    add_subdirectory(test)
endif()
#########################################################
