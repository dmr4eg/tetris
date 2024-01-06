# tetrisgame/CMakeLists.txt

cmake_minimum_required(VERSION 3.26)
project(tetrisgame)

set(CMAKE_CXX_STANDARD 17)

add_executable(tetrisgame main.cpp)
target_link_libraries(tetrisgame PRIVATE ncurses)

# Pridani složky s testy
add_subdirectory(tests)