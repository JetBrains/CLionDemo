cmake_minimum_required(VERSION ${cmake_minimal_version})
project(UMR)

set(CMAKE_CXX_STANDARD 11)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=memory -fPIE -pie -fno-omit-frame-pointer -g -O2")

add_executable(UMR memory_error_case.cpp)