cmake_minimum_required(VERSION ${cmake_minimal_version})
project(data_race)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread -fPIE -pie -g")

add_executable(data_race data_race_case.cpp)