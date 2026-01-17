cmake_minimum_required(VERSION 3.5)

project(kt21 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(kt21 main.cpp
    Game.h
    Game.cpp)

include(GNUInstallDirs)
install(TARGETS kt21
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
