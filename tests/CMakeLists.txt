cmake_minimum_required(VERSION 3.26)
project(tetristests)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
add_executable(tetristests tetristest.cpp)

target_include_directories(tetristests PRIVATE ${GTEST_INCLUDE_DIRS})

target_link_libraries(tetristests PRIVATE GTest::GTest GTest::Main pthread ncurses)

add_library(tetrisgame_lib STATIC /Users/dmr4eg/Folders/Codes/portfolio/tetris/tetrisgame/main.cpp)
target_link_libraries(tetristests PRIVATE tetrisgame_lib)

include(GoogleTest)
gtest_discover_tests(tetristests)