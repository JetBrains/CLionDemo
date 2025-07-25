cmake_minimum_required(VERSION ${cmake_minimal_version})
project(heap_buffer_overflow)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer -g")

add_executable(heap_buffer_overflow heap_buffer_overflow_case.cpp)