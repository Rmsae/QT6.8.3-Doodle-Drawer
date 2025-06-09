cmake_minimum_required(VERSION 3.16)

project(DoodleDrawerClient VERSION 0.1 LANGUAGES CXX)
message("Qt6 gefunden: ${Qt6_FOUND}")
message("Qt Version: ${QT_VERSION}")

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Qt-Module laden
find_package(Qt6 COMPONENTS Core Gui Qml Quick WebSockets REQUIRED)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(DoodleDrawerClient
    main.cpp
)

qt_add_qml_module(DoodleDrawerClient
    URI DoodleDrawerClient
    VERSION 1.0
    QML_FILES
        Main.qml
    SOURCES
        Controllers/websockethandler.h
        Controllers/websockethandler.cpp
)

set_target_properties(DoodleDrawerClient PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.DoodleDrawerClient
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_link_libraries(DoodleDrawerClient PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Qml
    Qt${QT_VERSION_MAJOR}::Quick
    Qt${QT_VERSION_MAJOR}::WebSockets
)

include(GNUInstallDirs)
install(TARGETS DoodleDrawerClient
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
