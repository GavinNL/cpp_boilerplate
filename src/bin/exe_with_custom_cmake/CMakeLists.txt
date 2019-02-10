# This file is automatically loaded.

cmake_minimum_required(VERSION 3.8)

get_filename_component(exe_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" exe_name ${exe_name})
string(TOUPPER ${exe_name} exe_name_cap)


MESSAGE("Compiling Module ${exe_name} into an executable using a custom CMakeLists file" )

# Get all the source files that will need to be compiled
FILE(GLOB_RECURSE  SRC_FILES  "*.cpp" "*.c" "*.cc")

# Create an executable.
add_executable(${exe_name} ${SRC_FILES})

# Add the common include path
include_directories( ${CPPBOILERPLATE_INCLUDE} )

# ==============================================================
# Add extra libraries that this library might want to use
# By default, all libraries in the "lib" folder will be
# automatically added.
# ==============================================================
target_link_libraries( ${exe_name} ${CPPBOILERPLATE_LIBS} ${CPPBOILERPLATE_COVERAGE_FLAGS}  )
# ==============================================================

# If this is a shared library and we're on windows, we need to have the
# exe_name_DEFINE_EXPORTS defined so that the symbols can be exported
if(${BUILD_SHARED_LIBS})
  target_compile_definitions( ${exe_name} PRIVATE -D${exe_name_cap}_DEFINE_EXPORTS )
endif()


# The install targets that will be created when we type "make install"
install(TARGETS ${exe_name}
      RUNTIME DESTINATION bin
      LIBRARY DESTINATION lib
      ARCHIVE DESTINATION lib)


