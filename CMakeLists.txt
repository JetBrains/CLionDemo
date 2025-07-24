cmake_minimum_required(VERSION 3.24)
project(CLionDemo)

set(CMAKE_CXX_STANDARD 20)

option(BUILD_BOOST_TESTS "Build Boost tests" ON)
option(BUILD_QT_DEMO "Build Arkanoid demo" ON)
option(BUILD_MODULES "Build Modules example" ON)

add_executable(demoMore main.cpp)

if (BUILD_MODULES)
    add_subdirectory(Modules)
endif ()

add_subdirectory(Code_Analysis)

add_subdirectory(Code_Generation)
add_subdirectory(Completion)
add_subdirectory(Documentation)
add_subdirectory(Param_Info)
add_subdirectory(Refactoring)

add_subdirectory(Catch_tests)
if (BUILD_BOOST_TESTS)
    add_subdirectory(Boost_tests)
endif ()

add_subdirectory(Doctest_tests)
enable_testing()
add_subdirectory(CTest_tests)

add_subdirectory(precompiled_header)
add_subdirectory(Navigation)
add_subdirectory(Editor)
add_subdirectory(ElevatorPitch)
add_subdirectory(StartNewDemo)
add_subdirectory(Resolve_Context)

add_subdirectory(CMake_support)
add_subdirectory(CUDA_support)

if (BUILD_QT_DEMO)
    add_subdirectory(Debug_demo)
    add_subdirectory(QML)
endif ()
add_subdirectory(Debug_extra)
add_subdirectory(Debug_extra/FreeRTOS_demo)

add_subdirectory(Valgrind_memcheck)
add_subdirectory(Sanitizers)
add_subdirectory(Coverage)
add_subdirectory(Profiler)

add_subdirectory(Remote_Dev)