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
include CMakeFiles/characterModel.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/characterModel.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/characterModel.dir/flags.make

CMakeFiles/characterModel.dir/src/characterModel.cpp.o: CMakeFiles/characterModel.dir/flags.make
CMakeFiles/characterModel.dir/src/characterModel.cpp.o: ../src/characterModel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alvaromarques/Documents/EA872/Vinganca-das-Arvores-Part2-EA872/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/characterModel.dir/src/characterModel.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/characterModel.dir/src/characterModel.cpp.o -c /Users/alvaromarques/Documents/EA872/Vinganca-das-Arvores-Part2-EA872/src/characterModel.cpp

CMakeFiles/characterModel.dir/src/characterModel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/characterModel.dir/src/characterModel.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alvaromarques/Documents/EA872/Vinganca-das-Arvores-Part2-EA872/src/characterModel.cpp > CMakeFiles/characterModel.dir/src/characterModel.cpp.i

CMakeFiles/characterModel.dir/src/characterModel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/characterModel.dir/src/characterModel.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alvaromarques/Documents/EA872/Vinganca-das-Arvores-Part2-EA872/src/characterModel.cpp -o CMakeFiles/characterModel.dir/src/characterModel.cpp.s

# Object files for target characterModel
characterModel_OBJECTS = \
"CMakeFiles/characterModel.dir/src/characterModel.cpp.o"

# External object files for target characterModel
characterModel_EXTERNAL_OBJECTS =

libcharacterModel.a: CMakeFiles/characterModel.dir/src/characterModel.cpp.o
libcharacterModel.a: CMakeFiles/characterModel.dir/build.make
libcharacterModel.a: CMakeFiles/characterModel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/alvaromarques/Documents/EA872/Vinganca-das-Arvores-Part2-EA872/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libcharacterModel.a"
	$(CMAKE_COMMAND) -P CMakeFiles/characterModel.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/characterModel.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/characterModel.dir/build: libcharacterModel.a

.PHONY : CMakeFiles/characterModel.dir/build

CMakeFiles/characterModel.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/characterModel.dir/cmake_clean.cmake
.PHONY : CMakeFiles/characterModel.dir/clean

CMakeFiles/characterModel.dir/depend:
	cd /Users/alvaromarques/Documents/EA872/Vinganca-das-Arvores-Part2-EA872/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/alvaromarques/Documents/EA872/Vinganca-das-Arvores-Part2-EA872 /Users/alvaromarques/Documents/EA872/Vinganca-das-Arvores-Part2-EA872 /Users/alvaromarques/Documents/EA872/Vinganca-das-Arvores-Part2-EA872/build /Users/alvaromarques/Documents/EA872/Vinganca-das-Arvores-Part2-EA872/build /Users/alvaromarques/Documents/EA872/Vinganca-das-Arvores-Part2-EA872/build/CMakeFiles/characterModel.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/characterModel.dir/depend

