cmake_minimum_required(VERSION 3.5)

project(kt4uus LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(kt4uus main.cpp)

include(GNUInstallDirs)
install(TARGETS kt4uus
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
