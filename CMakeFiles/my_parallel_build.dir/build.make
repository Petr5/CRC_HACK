# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /snap/cmake/1156/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1156/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/peter/CLionProjects/CRC_HACK

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/peter/CLionProjects/CRC_HACK

# Utility rule file for my_parallel_build.

# Include any custom commands dependencies for this target.
include CMakeFiles/my_parallel_build.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/my_parallel_build.dir/progress.make

CMakeFiles/my_parallel_build:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/peter/CLionProjects/CRC_HACK/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "My parallel build with 5 cores"
	/snap/cmake/1156/bin/cmake --build . -j 2

my_parallel_build: CMakeFiles/my_parallel_build
my_parallel_build: CMakeFiles/my_parallel_build.dir/build.make
.PHONY : my_parallel_build

# Rule to build all files generated by this target.
CMakeFiles/my_parallel_build.dir/build: my_parallel_build
.PHONY : CMakeFiles/my_parallel_build.dir/build

CMakeFiles/my_parallel_build.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_parallel_build.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_parallel_build.dir/clean

CMakeFiles/my_parallel_build.dir/depend:
	cd /home/peter/CLionProjects/CRC_HACK && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/peter/CLionProjects/CRC_HACK /home/peter/CLionProjects/CRC_HACK /home/peter/CLionProjects/CRC_HACK /home/peter/CLionProjects/CRC_HACK /home/peter/CLionProjects/CRC_HACK/CMakeFiles/my_parallel_build.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_parallel_build.dir/depend
