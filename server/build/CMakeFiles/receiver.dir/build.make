# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.18.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.18.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/alvaromarques/Documents/EA872/Vinganca-das-Arvores-Part2-EA872

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/alvaromarques/Documents/EA872/Vinganca-das-Arvores-Part2-EA872/build

# Include any dependencies generated for this target.
include CMakeFiles/receiver.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/receiver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/receiver.dir/flags.make

CMakeFiles/receiver.dir/src/receiver.cpp.o: CMakeFiles/receiver.dir/flags.make
CMakeFiles/receiver.dir/src/receiver.cpp.o: ../src/receiver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alvaromarques/Documents/EA872/Vinganca-das-Arvores-Part2-EA872/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/receiver.dir/src/receiver.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/receiver.dir/src/receiver.cpp.o -c /Users/alvaromarques/Documents/EA872/Vinganca-das-Arvores-Part2-EA872/src/receiver.cpp

CMakeFiles/receiver.dir/src/receiver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/receiver.dir/src/receiver.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alvaromarques/Documents/EA872/Vinganca-das-Arvores-Part2-EA872/src/receiver.cpp > CMakeFiles/receiver.dir/src/receiver.cpp.i

CMakeFiles/receiver.dir/src/receiver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/receiver.dir/src/receiver.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alvaromarques/Documents/EA872/Vinganca-das-Arvores-Part2-EA872/src/receiver.cpp -o CMakeFiles/receiver.dir/src/receiver.cpp.s

# Object files for target receiver
receiver_OBJECTS = \
"CMakeFiles/receiver.dir/src/receiver.cpp.o"

# External object files for target receiver
receiver_EXTERNAL_OBJECTS =

libreceiver.a: CMakeFiles/receiver.dir/src/receiver.cpp.o
libreceiver.a: CMakeFiles/receiver.dir/build.make
libreceiver.a: CMakeFiles/receiver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/alvaromarques/Documents/EA872/Vinganca-das-Arvores-Part2-EA872/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libreceiver.a"
	$(CMAKE_COMMAND) -P CMakeFiles/receiver.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/receiver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/receiver.dir/build: libreceiver.a

.PHONY : CMakeFiles/receiver.dir/build

CMakeFiles/receiver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/receiver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/receiver.dir/clean

CMakeFiles/receiver.dir/depend:
	cd /Users/alvaromarques/Documents/EA872/Vinganca-das-Arvores-Part2-EA872/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/alvaromarques/Documents/EA872/Vinganca-das-Arvores-Part2-EA872 /Users/alvaromarques/Documents/EA872/Vinganca-das-Arvores-Part2-EA872 /Users/alvaromarques/Documents/EA872/Vinganca-das-Arvores-Part2-EA872/build /Users/alvaromarques/Documents/EA872/Vinganca-das-Arvores-Part2-EA872/build /Users/alvaromarques/Documents/EA872/Vinganca-das-Arvores-Part2-EA872/build/CMakeFiles/receiver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/receiver.dir/depend
