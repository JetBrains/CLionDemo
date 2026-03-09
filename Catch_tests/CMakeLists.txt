configure_file(CMakeLists.txt.in catch2test-download/CMakeLists.txt)

execute_process(COMMAND ${CMAKE_COMMAND} -DCMAKE_MAKE_PROGRAM=${CMAKE_MAKE_PROGRAM} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/catch2test-download )
if(result)
    message(FATAL_ERROR "CMake step for catch2test failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/catch2test-download )
if(result)
    message(FATAL_ERROR "Build step for catch2test failed: ${result}")
endif()

add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/catch2test-src
        ${CMAKE_CURRENT_BINARY_DIR}/catch2test-build
        EXCLUDE_FROM_ALL)

include_directories("${Catch2_SOURCE_DIR}/include")

set(LIB_SOURCE_FILES sample_lib.cpp sample_lib.h)
add_library(sample_lib ${LIB_SOURCE_FILES})

set (TEST_SOURCE_FILES sample_test.cpp)
add_executable(test_runner ${TEST_SOURCE_FILES})
target_link_libraries(test_runner PRIVATE sample_lib Catch2::Catch2WithMain)