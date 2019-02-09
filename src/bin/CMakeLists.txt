cmake_minimum_required(VERSION 3.8)

SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})

MESSAGE("\n\n")
MESSAGE("=====================================================")
MESSAGE(" Collecting Executables                              ")
MESSAGE("=====================================================")
FOREACH(subdir ${SUBDIRS})

    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${subdir}/CMakeLists.txt")

        MESSAGE("Custom CMakeLists.txt file found for executable: ${subdir} ")
        add_subdirectory(${subdir})

    else()

        MESSAGE("Compiling Module ${subdir} into executable. Libs: ${CPPBOILERPLATE_LIBS} " )

        include_directories( ${CPPBOILERPLATE_INCLUDE} )

        FILE(GLOB_RECURSE  SRC_FILES  "${subdir}/*.cpp" )

        add_executable(${subdir} ${SRC_FILES})

        target_link_libraries( ${subdir} ${CPPBOILERPLATE_LIBS} ${CPPBOILERPLATE_COVERAGE_FLAGS})

        install(TARGETS ${subdir}
                RUNTIME DESTINATION bin
                LIBRARY DESTINATION lib
                ARCHIVE DESTINATION lib)

    endif()

ENDFOREACH()
MESSAGE("=====================================================")
