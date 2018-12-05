cmake_minimum_required(VERSION 3.8)

SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})
MESSAGE("\n\n")
MESSAGE("=====================================================")
MESSAGE(" Collecting Modules                                  ")
MESSAGE("=====================================================")
FOREACH(subdir ${SUBDIRS})
  MESSAGE("Compiling Module ${subdir} into lib${subdir}" )

  # Find all the cpp files in the subdirectory
  FILE(GLOB_RECURSE  SRC_FILES  "${subdir}/*.cpp" )

  # Make sure the include paths are set
  include_directories( ${CPPBOILERPLATE_INCLUDE} )

  # Compile all the source files into a library
  add_library(${subdir} ${SRC_FILES})

ENDFOREACH()
MESSAGE("=====================================================")

MESSAGE("${CPPBOILERPLATE_LIBS}")
