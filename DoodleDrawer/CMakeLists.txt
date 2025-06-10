cmake_minimum_required(VERSION 3.16)

project(DoodleDrawer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Qt-Module laden
find_package(Qt6 COMPONENTS Core Gui Qml Quick WebSockets REQUIRED)
message("Qt6 gefunden: ${Qt6_FOUND}")
message("Qt Version: ${QT_VERSION}")

qt_standard_project_setup(REQUIRES 6.8)

# Client ausführbare Datei
qt_add_executable(DoodleDrawerClient
    DoodleDrawerClient/main.cpp
)

qt_add_qml_module(DoodleDrawerClient
    URI DoodleDrawerClient
    VERSION 1.0
    QML_FILES
        DoodleDrawerClient/Main.qml
    SOURCES
        DoodleDrawerClient/Controllers/websockethandler.h
        DoodleDrawerClient/Controllers/websockethandler.cpp
)

set_target_properties(DoodleDrawerClient PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.DoodleDrawerClient
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(DoodleDrawerClient PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::WebSockets
)

# Server ausführbare Datei
qt_add_executable(DoodleDrawerServer
    DoodleDrawerServer/main.cpp
    DoodleDrawerServer/gamemanager.h
    DoodleDrawerServer/gamemanager.cpp
    DoodleDrawerServer/websockethandler.h
    DoodleDrawerServer/websockethandler.cpp
)

set_target_properties(DoodleDrawerServer PROPERTIES
    MACOSX_BUNDLE FALSE
    WIN32_EXECUTABLE FALSE
)

target_link_libraries(DoodleDrawerServer PRIVATE
    Qt6::Core
    Qt6::WebSockets
)

# Installation
include(GNUInstallDirs)
install(TARGETS DoodleDrawerClient DoodleDrawerServer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
