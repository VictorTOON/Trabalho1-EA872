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
include CMakeFiles/sender.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sender.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sender.dir/flags.make

CMakeFiles/sender.dir/src/sender.cpp.o: CMakeFiles/sender.dir/flags.make
CMakeFiles/sender.dir/src/sender.cpp.o: ../src/sender.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sender.dir/src/sender.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sender.dir/src/sender.cpp.o -c /home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server/src/sender.cpp

CMakeFiles/sender.dir/src/sender.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sender.dir/src/sender.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server/src/sender.cpp > CMakeFiles/sender.dir/src/sender.cpp.i

CMakeFiles/sender.dir/src/sender.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sender.dir/src/sender.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server/src/sender.cpp -o CMakeFiles/sender.dir/src/sender.cpp.s

# Object files for target sender
sender_OBJECTS = \
"CMakeFiles/sender.dir/src/sender.cpp.o"

# External object files for target sender
sender_EXTERNAL_OBJECTS =

libsender.a: CMakeFiles/sender.dir/src/sender.cpp.o
libsender.a: CMakeFiles/sender.dir/build.make
libsender.a: CMakeFiles/sender.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libsender.a"
	$(CMAKE_COMMAND) -P CMakeFiles/sender.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sender.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sender.dir/build: libsender.a

.PHONY : CMakeFiles/sender.dir/build

CMakeFiles/sender.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sender.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sender.dir/clean

CMakeFiles/sender.dir/depend:
	cd /home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server /home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server /home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server/build /home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server/build /home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server/build/CMakeFiles/sender.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sender.dir/depend

