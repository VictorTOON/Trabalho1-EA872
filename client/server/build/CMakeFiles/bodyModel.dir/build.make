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
include CMakeFiles/bodyModel.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bodyModel.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bodyModel.dir/flags.make

CMakeFiles/bodyModel.dir/src/bodyModel.cpp.o: CMakeFiles/bodyModel.dir/flags.make
CMakeFiles/bodyModel.dir/src/bodyModel.cpp.o: ../src/bodyModel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bodyModel.dir/src/bodyModel.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bodyModel.dir/src/bodyModel.cpp.o -c /home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server/src/bodyModel.cpp

CMakeFiles/bodyModel.dir/src/bodyModel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bodyModel.dir/src/bodyModel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server/src/bodyModel.cpp > CMakeFiles/bodyModel.dir/src/bodyModel.cpp.i

CMakeFiles/bodyModel.dir/src/bodyModel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bodyModel.dir/src/bodyModel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server/src/bodyModel.cpp -o CMakeFiles/bodyModel.dir/src/bodyModel.cpp.s

# Object files for target bodyModel
bodyModel_OBJECTS = \
"CMakeFiles/bodyModel.dir/src/bodyModel.cpp.o"

# External object files for target bodyModel
bodyModel_EXTERNAL_OBJECTS =

libbodyModel.a: CMakeFiles/bodyModel.dir/src/bodyModel.cpp.o
libbodyModel.a: CMakeFiles/bodyModel.dir/build.make
libbodyModel.a: CMakeFiles/bodyModel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libbodyModel.a"
	$(CMAKE_COMMAND) -P CMakeFiles/bodyModel.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bodyModel.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bodyModel.dir/build: libbodyModel.a

.PHONY : CMakeFiles/bodyModel.dir/build

CMakeFiles/bodyModel.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bodyModel.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bodyModel.dir/clean

CMakeFiles/bodyModel.dir/depend:
	cd /home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server /home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server /home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server/build /home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server/build /home/ubuntu/git/Vinganca-das-Arvores-Part2-EA872/server/build/CMakeFiles/bodyModel.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bodyModel.dir/depend
