#Don't forget to add -DCMAKE_MODULE_PATH=<qt6 path>

set(QT_VERSION 6)

find_package(Qt${QT_VERSION}Widgets REQUIRED)

add_library(arkanoidLib
        Ball.cpp Ball.h
        GameObject.cpp GameObject.h
        Brick.cpp Brick.h
        Collisions.cpp Collisions.h
        GameState.cpp GameState.h)

target_link_libraries(arkanoidLib Qt${QT_VERSION}::Widgets)

set(SOURCE_FILES main.cpp GameWidget.cpp GameWidget.h)
add_executable(arkanoid ${SOURCE_FILES})
target_link_libraries(arkanoid arkanoidLib)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()

    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET arkanoid POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:arkanoid>/plugins/platforms/")
        add_custom_command(TARGET arkanoid POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:arkanoid>/plugins/platforms/")
    endif ()

    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET arkanoid POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt${QT_VERSION}${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:arkanoid>")
    endforeach (QT_LIB)
endif()

add_subdirectory(3rdparty/googletest)
add_executable(arkanoidTest test.cpp)
target_link_libraries(arkanoidTest gtest_main arkanoidLib)

add_executable(printers printers.cpp)
