# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/dmr4eg/Folders/Codes/portfolio/tetris/tetrisgame/tests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/dmr4eg/Folders/Codes/portfolio/tetris/tetrisgame/tests/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/tetristests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tetristests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tetristests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tetristests.dir/flags.make

CMakeFiles/tetristests.dir/tetristest.cpp.o: CMakeFiles/tetristests.dir/flags.make
CMakeFiles/tetristests.dir/tetristest.cpp.o: /Users/dmr4eg/Folders/Codes/portfolio/tetris/tetrisgame/tests/tetristest.cpp
CMakeFiles/tetristests.dir/tetristest.cpp.o: CMakeFiles/tetristests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dmr4eg/Folders/Codes/portfolio/tetris/tetrisgame/tests/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tetristests.dir/tetristest.cpp.o"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tetristests.dir/tetristest.cpp.o -MF CMakeFiles/tetristests.dir/tetristest.cpp.o.d -o CMakeFiles/tetristests.dir/tetristest.cpp.o -c /Users/dmr4eg/Folders/Codes/portfolio/tetris/tetrisgame/tests/tetristest.cpp

CMakeFiles/tetristests.dir/tetristest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tetristests.dir/tetristest.cpp.i"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dmr4eg/Folders/Codes/portfolio/tetris/tetrisgame/tests/tetristest.cpp > CMakeFiles/tetristests.dir/tetristest.cpp.i

CMakeFiles/tetristests.dir/tetristest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tetristests.dir/tetristest.cpp.s"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dmr4eg/Folders/Codes/portfolio/tetris/tetrisgame/tests/tetristest.cpp -o CMakeFiles/tetristests.dir/tetristest.cpp.s

# Object files for target tetristests
tetristests_OBJECTS = \
"CMakeFiles/tetristests.dir/tetristest.cpp.o"

# External object files for target tetristests
tetristests_EXTERNAL_OBJECTS =

tetristests: CMakeFiles/tetristests.dir/tetristest.cpp.o
tetristests: CMakeFiles/tetristests.dir/build.make
tetristests: CMakeFiles/tetristests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/dmr4eg/Folders/Codes/portfolio/tetris/tetrisgame/tests/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tetristests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tetristests.dir/link.txt --verbose=$(VERBOSE)
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -D TEST_TARGET=tetristests -D TEST_EXECUTABLE=/Users/dmr4eg/Folders/Codes/portfolio/tetris/tetrisgame/tests/cmake-build-debug/tetristests -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/Users/dmr4eg/Folders/Codes/portfolio/tetris/tetrisgame/tests/cmake-build-debug -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=tetristests_TESTS -D CTEST_FILE=/Users/dmr4eg/Folders/Codes/portfolio/tetris/tetrisgame/tests/cmake-build-debug/tetristests[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /Applications/CLion.app/Contents/bin/cmake/mac/share/cmake-3.26/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
CMakeFiles/tetristests.dir/build: tetristests
.PHONY : CMakeFiles/tetristests.dir/build

CMakeFiles/tetristests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tetristests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tetristests.dir/clean

CMakeFiles/tetristests.dir/depend:
	cd /Users/dmr4eg/Folders/Codes/portfolio/tetris/tetrisgame/tests/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dmr4eg/Folders/Codes/portfolio/tetris/tetrisgame/tests /Users/dmr4eg/Folders/Codes/portfolio/tetris/tetrisgame/tests /Users/dmr4eg/Folders/Codes/portfolio/tetris/tetrisgame/tests/cmake-build-debug /Users/dmr4eg/Folders/Codes/portfolio/tetris/tetrisgame/tests/cmake-build-debug /Users/dmr4eg/Folders/Codes/portfolio/tetris/tetrisgame/tests/cmake-build-debug/CMakeFiles/tetristests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tetristests.dir/depend

