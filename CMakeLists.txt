cmake_minimum_required (VERSION 2.6)
project (Tutorial)
# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# C++ 11
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall ${CMAKE_CXX_FLAGS} -DULAPI")


# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
  "${PROJECT_BINARY_DIR}/TutorialConfig.h"
  )
 
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories(
    "${PROJECT_BINARY_DIR}"
    /usr/include/linuxcnc
    )

add_library(lcnc STATIC IMPORTED)
set_target_properties(lcnc PROPERTIES IMPORTED_LOCATION 
"/usr/lib/liblinuxcnc.a"
)

add_library(lcnchal SHARED IMPORTED)
set_target_properties(lcnchal PROPERTIES IMPORTED_LOCATION 
"/usr/lib/liblinuxcnchal.so"
)

# add the executable
add_executable(Tutorial tutorial.cpp)
#target_link_libraries(Tutorial /usr/lib/linuxcnculapi.so)
target_link_libraries (Tutorial lcnc lcnchal)