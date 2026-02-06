include(../version.cmake)
cmake_minimum_required(VERSION ${REQUIRED_CMAKE_VERSION} FATAL_ERROR)

project(check_coverage)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage")

add_executable(check_coverage main.cpp)
