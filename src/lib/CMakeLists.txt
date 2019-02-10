cmake_minimum_required(VERSION 3.8)

SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})

MESSAGE("\n\n")
MESSAGE("=====================================================")
MESSAGE(" Collecting Libraries                              ")
MESSAGE("=====================================================")
FOREACH(subdir ${SUBDIRS})

  string(TOUPPER ${subdir} subdir_cap)

  if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${subdir}/CMakeLists.txt")
      MESSAGE("Custom CMakeLists.txt file found for lib{subdir} " )
      add_subdirectory(${subdir})
  endif()

ENDFOREACH()
MESSAGE("=====================================================")
