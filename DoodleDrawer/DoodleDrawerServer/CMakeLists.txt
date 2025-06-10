cmake_minimum_required(VERSION 3.16)

project(DoodleDrawerServer LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core WebSockets)


add_executable(DoodleDrawerServer
  main.cpp
  gamemanager.h gamemanager.cpp
  websockethandler.h websockethandler.cpp
)
target_link_libraries(DoodleDrawerServer Qt${QT_VERSION_MAJOR}::Core
                      Qt${QT_VERSION_MAJOR}::WebSockets)

include(GNUInstallDirs)
install(TARGETS DoodleDrawerServer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
