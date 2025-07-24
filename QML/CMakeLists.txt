set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Quick
        QuickControls2
        REQUIRED)

add_executable(qml_example qml_hello_world.cpp)

target_link_libraries(qml_example
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Quick
        Qt::QuickControls2)

configure_file(hello_world.qml hello_world.qml COPYONLY)
