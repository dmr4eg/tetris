cmake_minimum_required(VERSION 3.26)
project(newtet)

set(CMAKE_CXX_STANDARD 17)

add_executable(tetrisgame main.cpp)

target_link_libraries(tetrisgame PRIVATE ncurses)
