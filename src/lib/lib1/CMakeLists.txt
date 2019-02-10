# This file is automatically loaded.

cmake_minimum_required(VERSION 3.8)

get_filename_component(library_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" library_name ${library_name})
string(TOUPPER ${library_name} library_name_cap)


MESSAGE("Compiling Module ${library_name} into library using a custom CMakeLists file" )

# Get all the source files that will need to be compiled
FILE(GLOB_RECURSE  SRC_FILES  "*.cpp" "*.c" "*.cc")

# Create a library.
add_library(${library_name} ${SRC_FILES})

# Add the common include path
include_directories( ${CPPBOILERPLATE_INCLUDE} )

# ==============================================================
# Add extra libraries that this library might want to use
# This is more so for windows
# ==============================================================
#target_link_libraries( ${library_name} lib2 )
# ==============================================================

# If this is a shared library and we're on windows, we need to have the
# library_name_DEFINE_EXPORTS defined so that the symbols can be exported
if(${BUILD_SHARED_LIBS})
  target_compile_definitions( ${library_name} PRIVATE -D${library_name_cap}_DEFINE_EXPORTS )
endif()


# The install targets that will be created when we type "make install"
install(TARGETS ${library_name}
      RUNTIME DESTINATION bin
      LIBRARY DESTINATION lib
      ARCHIVE DESTINATION lib)

