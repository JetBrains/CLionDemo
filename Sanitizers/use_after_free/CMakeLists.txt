cmake_minimum_required(VERSION ${cmake_minimal_version})
project(use_after_free)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -O1 -fno-omit-frame-pointer -g")

add_executable(use_after_free use_after_free_case.cpp)