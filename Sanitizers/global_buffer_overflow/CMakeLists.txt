include(../../version.cmake)
cmake_minimum_required(VERSION ${REQUIRED_CMAKE_VERSION} FATAL_ERROR)

project(global_buffer_overflow)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer -g")

add_executable(global_buffer_overflow global_buffer_overflow_case.cpp)