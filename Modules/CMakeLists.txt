if(${CMAKE_VERSION} VERSION_LESS "3.28")
    message(FATAL_ERROR "CMake version 3.28 or higher is required for C++20 modules support. You are running version ${CMAKE_VERSION}.")
endif()

set(CMAKE_CXX_SCAN_FOR_MODULES ON)

add_executable(Modules)
target_sources(Modules
        PUBLIC
        main.cpp
)
target_sources(Modules
        PUBLIC
        FILE_SET all_my_modules TYPE CXX_MODULES FILES
        AdvancedMath.cppm
        language.cppm
)