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

# Include any dependencies generated for this target.
include CMakeFiles/MainProgram.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MainProgram.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MainProgram.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MainProgram.dir/flags.make

CMakeFiles/MainProgram.dir/main.cpp.o: CMakeFiles/MainProgram.dir/flags.make
CMakeFiles/MainProgram.dir/main.cpp.o: main.cpp
CMakeFiles/MainProgram.dir/main.cpp.o: CMakeFiles/MainProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/peter/CLionProjects/CRC_HACK/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MainProgram.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MainProgram.dir/main.cpp.o -MF CMakeFiles/MainProgram.dir/main.cpp.o.d -o CMakeFiles/MainProgram.dir/main.cpp.o -c /home/peter/CLionProjects/CRC_HACK/main.cpp

CMakeFiles/MainProgram.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MainProgram.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/peter/CLionProjects/CRC_HACK/main.cpp > CMakeFiles/MainProgram.dir/main.cpp.i

CMakeFiles/MainProgram.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MainProgram.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/peter/CLionProjects/CRC_HACK/main.cpp -o CMakeFiles/MainProgram.dir/main.cpp.s

CMakeFiles/MainProgram.dir/crc.cpp.o: CMakeFiles/MainProgram.dir/flags.make
CMakeFiles/MainProgram.dir/crc.cpp.o: crc.cpp
CMakeFiles/MainProgram.dir/crc.cpp.o: CMakeFiles/MainProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/peter/CLionProjects/CRC_HACK/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MainProgram.dir/crc.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MainProgram.dir/crc.cpp.o -MF CMakeFiles/MainProgram.dir/crc.cpp.o.d -o CMakeFiles/MainProgram.dir/crc.cpp.o -c /home/peter/CLionProjects/CRC_HACK/crc.cpp

CMakeFiles/MainProgram.dir/crc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MainProgram.dir/crc.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/peter/CLionProjects/CRC_HACK/crc.cpp > CMakeFiles/MainProgram.dir/crc.cpp.i

CMakeFiles/MainProgram.dir/crc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MainProgram.dir/crc.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/peter/CLionProjects/CRC_HACK/crc.cpp -o CMakeFiles/MainProgram.dir/crc.cpp.s

# Object files for target MainProgram
MainProgram_OBJECTS = \
"CMakeFiles/MainProgram.dir/main.cpp.o" \
"CMakeFiles/MainProgram.dir/crc.cpp.o"

# External object files for target MainProgram
MainProgram_EXTERNAL_OBJECTS =

MainProgram: CMakeFiles/MainProgram.dir/main.cpp.o
MainProgram: CMakeFiles/MainProgram.dir/crc.cpp.o
MainProgram: CMakeFiles/MainProgram.dir/build.make
MainProgram: CMakeFiles/MainProgram.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/peter/CLionProjects/CRC_HACK/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable MainProgram"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MainProgram.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MainProgram.dir/build: MainProgram
.PHONY : CMakeFiles/MainProgram.dir/build

CMakeFiles/MainProgram.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MainProgram.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MainProgram.dir/clean

CMakeFiles/MainProgram.dir/depend:
	cd /home/peter/CLionProjects/CRC_HACK && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/peter/CLionProjects/CRC_HACK /home/peter/CLionProjects/CRC_HACK /home/peter/CLionProjects/CRC_HACK /home/peter/CLionProjects/CRC_HACK /home/peter/CLionProjects/CRC_HACK/CMakeFiles/MainProgram.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MainProgram.dir/depend

