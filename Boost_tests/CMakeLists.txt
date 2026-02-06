include(../version.cmake)
cmake_minimum_required(VERSION ${REQUIRED_CMAKE_VERSION} FATAL_ERROR)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)
include_directories(${Boost_INCLUDE_DIR})

add_executable(boost_demo boost_demo_tests.cpp)

