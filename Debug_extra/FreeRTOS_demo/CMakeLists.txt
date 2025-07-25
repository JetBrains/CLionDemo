if (APPLE OR WIN32)
    return()
endif ()

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)
set(CMAKE_C_STANDARD 99)

add_definitions(-DprojCOVERAGE_TEST=1)

include_directories(
        freertos/Common/include
        freertos/Source/include
        freertos/Source/portable/ThirdParty/GCC/Posix
        freertos/Source/portable/ThirdParty/GCC/Posix/utils)

file(GLOB_RECURSE SOURCES
        console.c
        code_coverage_additions.c
        main_blinky.c
        main.c
        run-time-stats-utils.c
        "freertos/Demo/Common/Minimal/*.*"
        "freertos/Source/*.c"
        "freertos/Source/portable/MemMang/*.*")

set(CMAKE_THREAD_PREFER_PTHREAD ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)

add_executable(freertos_posix ${SOURCES})
target_link_libraries(freertos_posix PRIVATE Threads::Threads)