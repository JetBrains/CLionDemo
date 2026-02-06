include(../version.cmake)
cmake_minimum_required(VERSION ${REQUIRED_CMAKE_VERSION} FATAL_ERROR)

set(SOURCE_FILES Distance.cpp)

add_library(code_generation ${SOURCE_FILES})
