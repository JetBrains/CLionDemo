set(cmake_minimal_version 3.10)

include(../version.cmake)
cmake_minimum_required(VERSION ${REQUIRED_CMAKE_VERSION} FATAL_ERROR)

add_subdirectory(use_after_free)
add_subdirectory(UMR)
add_subdirectory(data_race)
add_subdirectory(data_race_2)
add_subdirectory(heap_buffer_overflow)
add_subdirectory(stack_buffer_overflow)
add_subdirectory(global_buffer_overflow)