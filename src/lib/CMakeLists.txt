cmake_minimum_required(VERSION 3.8)

SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})

MESSAGE("\n\n")
MESSAGE("=====================================================")
MESSAGE(" Collecting Libraries                              ")
MESSAGE("=====================================================")
FOREACH(subdir ${SUBDIRS})

  if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${subdir}/CMakeLists.txt")
      MESSAGE("Custom CMakeLists.txt file found for lib{subdir} " )
      add_subdirectory(${subdir})
  else()
      MESSAGE("Compiling Module ${subdir} into library" )

      include_directories( ${CPPBOILERPLATE_INCLUDE} )

      FILE(GLOB_RECURSE  SRC_FILES  "${subdir}/*.cpp" )

      add_library(${subdir} ${SRC_FILES})

      install(TARGETS ${subdir}
              RUNTIME DESTINATION bin
              LIBRARY DESTINATION lib
              ARCHIVE DESTINATION lib)

  endif()

ENDFOREACH()
MESSAGE("=====================================================")
