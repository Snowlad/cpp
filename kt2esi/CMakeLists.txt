cmake_minimum_required(VERSION 3.5)

project(kt2esi LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(kt2esi main.cpp)

include(GNUInstallDirs)
install(TARGETS kt2esi
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
