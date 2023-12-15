cmake_minimum_required(VERSION 3.26)
project(AtividadeExtensao)

set(CMAKE_CXX_STANDARD 17)

add_executable(AtividadeExtensao main.cpp
        util.cpp
        menu.cpp
        util.h)
add_executable(Principal principal.cpp)
