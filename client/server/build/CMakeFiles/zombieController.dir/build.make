# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server/build

# Include any dependencies generated for this target.
include CMakeFiles/zombieController.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/zombieController.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zombieController.dir/flags.make

CMakeFiles/zombieController.dir/src/zombieController.cpp.o: CMakeFiles/zombieController.dir/flags.make
CMakeFiles/zombieController.dir/src/zombieController.cpp.o: ../src/zombieController.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/zombieController.dir/src/zombieController.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zombieController.dir/src/zombieController.cpp.o -c /home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server/src/zombieController.cpp

CMakeFiles/zombieController.dir/src/zombieController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zombieController.dir/src/zombieController.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server/src/zombieController.cpp > CMakeFiles/zombieController.dir/src/zombieController.cpp.i

CMakeFiles/zombieController.dir/src/zombieController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zombieController.dir/src/zombieController.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server/src/zombieController.cpp -o CMakeFiles/zombieController.dir/src/zombieController.cpp.s

# Object files for target zombieController
zombieController_OBJECTS = \
"CMakeFiles/zombieController.dir/src/zombieController.cpp.o"

# External object files for target zombieController
zombieController_EXTERNAL_OBJECTS =

libzombieController.a: CMakeFiles/zombieController.dir/src/zombieController.cpp.o
libzombieController.a: CMakeFiles/zombieController.dir/build.make
libzombieController.a: CMakeFiles/zombieController.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libzombieController.a"
	$(CMAKE_COMMAND) -P CMakeFiles/zombieController.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zombieController.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zombieController.dir/build: libzombieController.a

.PHONY : CMakeFiles/zombieController.dir/build

CMakeFiles/zombieController.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/zombieController.dir/cmake_clean.cmake
.PHONY : CMakeFiles/zombieController.dir/clean

CMakeFiles/zombieController.dir/depend:
	cd /home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server /home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server /home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server/build /home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server/build /home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server/build/CMakeFiles/zombieController.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zombieController.dir/depend
