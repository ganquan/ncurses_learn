# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.23.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.23.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ganquan/Code/GitHub/ncurses_learn

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ganquan/Code/GitHub/ncurses_learn/build

# Include any dependencies generated for this target.
include CMakeFiles/day0.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/day0.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/day0.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/day0.dir/flags.make

CMakeFiles/day0.dir/src/day0.cpp.o: CMakeFiles/day0.dir/flags.make
CMakeFiles/day0.dir/src/day0.cpp.o: ../src/day0.cpp
CMakeFiles/day0.dir/src/day0.cpp.o: CMakeFiles/day0.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ganquan/Code/GitHub/ncurses_learn/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/day0.dir/src/day0.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/day0.dir/src/day0.cpp.o -MF CMakeFiles/day0.dir/src/day0.cpp.o.d -o CMakeFiles/day0.dir/src/day0.cpp.o -c /Users/ganquan/Code/GitHub/ncurses_learn/src/day0.cpp

CMakeFiles/day0.dir/src/day0.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/day0.dir/src/day0.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ganquan/Code/GitHub/ncurses_learn/src/day0.cpp > CMakeFiles/day0.dir/src/day0.cpp.i

CMakeFiles/day0.dir/src/day0.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/day0.dir/src/day0.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ganquan/Code/GitHub/ncurses_learn/src/day0.cpp -o CMakeFiles/day0.dir/src/day0.cpp.s

# Object files for target day0
day0_OBJECTS = \
"CMakeFiles/day0.dir/src/day0.cpp.o"

# External object files for target day0
day0_EXTERNAL_OBJECTS =

day0: CMakeFiles/day0.dir/src/day0.cpp.o
day0: CMakeFiles/day0.dir/build.make
day0: CMakeFiles/day0.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ganquan/Code/GitHub/ncurses_learn/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable day0"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/day0.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/day0.dir/build: day0
.PHONY : CMakeFiles/day0.dir/build

CMakeFiles/day0.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/day0.dir/cmake_clean.cmake
.PHONY : CMakeFiles/day0.dir/clean

CMakeFiles/day0.dir/depend:
	cd /Users/ganquan/Code/GitHub/ncurses_learn/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ganquan/Code/GitHub/ncurses_learn /Users/ganquan/Code/GitHub/ncurses_learn /Users/ganquan/Code/GitHub/ncurses_learn/build /Users/ganquan/Code/GitHub/ncurses_learn/build /Users/ganquan/Code/GitHub/ncurses_learn/build/CMakeFiles/day0.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/day0.dir/depend

