if(EXISTS "/Users/dmr4eg/Folders/Codes/portfolio/tetris/tetrisgame/cmake-build-debug/tetristests/tetristests[1]_tests.cmake")
  include("/Users/dmr4eg/Folders/Codes/portfolio/tetris/tetrisgame/cmake-build-debug/tetristests/tetristests[1]_tests.cmake")
else()
  add_test(tetristests_NOT_BUILT tetristests_NOT_BUILT)
endif()
