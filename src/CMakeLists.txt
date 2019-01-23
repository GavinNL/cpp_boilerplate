cmake_minimum_required(VERSION 3.8)

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/bin)
    add_subdirectory(bin)
endif()

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/lib)
    add_subdirectory(lib)
endif()

