cmake_minimum_required(VERSION 3.8)

SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})

MESSAGE("\n\n")
MESSAGE("=====================================================")
MESSAGE(" Collecting Executables                              ")
MESSAGE("=====================================================")
FOREACH(subdir ${SUBDIRS})
  MESSAGE("Compiling Module ${subdir} into executable" )

  include_directories( ${CPPBOILERPLATE_INCLUDE} )

  FILE(GLOB_RECURSE  SRC_FILES  "${subdir}/*.cpp" )

  add_executable(${subdir} ${SRC_FILES})
  target_link_libraries( ${subdir} ${CPPBOILERPLATE_LIBS} ${CPPBOILERPLATE_COVERAGE_FLAGS})


ENDFOREACH()
MESSAGE("=====================================================")
