# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Clion\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Clion\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Clion file\C\AdjacencyTest"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Clion file\C\AdjacencyTest\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/AdjacencyTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AdjacencyTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AdjacencyTest.dir/flags.make

CMakeFiles/AdjacencyTest.dir/main.c.obj: CMakeFiles/AdjacencyTest.dir/flags.make
CMakeFiles/AdjacencyTest.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Clion file\C\AdjacencyTest\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/AdjacencyTest.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\AdjacencyTest.dir\main.c.obj   -c "D:\Clion file\C\AdjacencyTest\main.c"

CMakeFiles/AdjacencyTest.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AdjacencyTest.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\Clion file\C\AdjacencyTest\main.c" > CMakeFiles\AdjacencyTest.dir\main.c.i

CMakeFiles/AdjacencyTest.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AdjacencyTest.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\Clion file\C\AdjacencyTest\main.c" -o CMakeFiles\AdjacencyTest.dir\main.c.s

CMakeFiles/AdjacencyTest.dir/Adjacency.c.obj: CMakeFiles/AdjacencyTest.dir/flags.make
CMakeFiles/AdjacencyTest.dir/Adjacency.c.obj: ../Adjacency.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Clion file\C\AdjacencyTest\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/AdjacencyTest.dir/Adjacency.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\AdjacencyTest.dir\Adjacency.c.obj   -c "D:\Clion file\C\AdjacencyTest\Adjacency.c"

CMakeFiles/AdjacencyTest.dir/Adjacency.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AdjacencyTest.dir/Adjacency.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\Clion file\C\AdjacencyTest\Adjacency.c" > CMakeFiles\AdjacencyTest.dir\Adjacency.c.i

CMakeFiles/AdjacencyTest.dir/Adjacency.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AdjacencyTest.dir/Adjacency.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\Clion file\C\AdjacencyTest\Adjacency.c" -o CMakeFiles\AdjacencyTest.dir\Adjacency.c.s

CMakeFiles/AdjacencyTest.dir/Queue.c.obj: CMakeFiles/AdjacencyTest.dir/flags.make
CMakeFiles/AdjacencyTest.dir/Queue.c.obj: ../Queue.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Clion file\C\AdjacencyTest\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/AdjacencyTest.dir/Queue.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\AdjacencyTest.dir\Queue.c.obj   -c "D:\Clion file\C\AdjacencyTest\Queue.c"

CMakeFiles/AdjacencyTest.dir/Queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AdjacencyTest.dir/Queue.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\Clion file\C\AdjacencyTest\Queue.c" > CMakeFiles\AdjacencyTest.dir\Queue.c.i

CMakeFiles/AdjacencyTest.dir/Queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AdjacencyTest.dir/Queue.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\Clion file\C\AdjacencyTest\Queue.c" -o CMakeFiles\AdjacencyTest.dir\Queue.c.s

# Object files for target AdjacencyTest
AdjacencyTest_OBJECTS = \
"CMakeFiles/AdjacencyTest.dir/main.c.obj" \
"CMakeFiles/AdjacencyTest.dir/Adjacency.c.obj" \
"CMakeFiles/AdjacencyTest.dir/Queue.c.obj"

# External object files for target AdjacencyTest
AdjacencyTest_EXTERNAL_OBJECTS =

AdjacencyTest.exe: CMakeFiles/AdjacencyTest.dir/main.c.obj
AdjacencyTest.exe: CMakeFiles/AdjacencyTest.dir/Adjacency.c.obj
AdjacencyTest.exe: CMakeFiles/AdjacencyTest.dir/Queue.c.obj
AdjacencyTest.exe: CMakeFiles/AdjacencyTest.dir/build.make
AdjacencyTest.exe: CMakeFiles/AdjacencyTest.dir/linklibs.rsp
AdjacencyTest.exe: CMakeFiles/AdjacencyTest.dir/objects1.rsp
AdjacencyTest.exe: CMakeFiles/AdjacencyTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Clion file\C\AdjacencyTest\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable AdjacencyTest.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\AdjacencyTest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AdjacencyTest.dir/build: AdjacencyTest.exe

.PHONY : CMakeFiles/AdjacencyTest.dir/build

CMakeFiles/AdjacencyTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\AdjacencyTest.dir\cmake_clean.cmake
.PHONY : CMakeFiles/AdjacencyTest.dir/clean

CMakeFiles/AdjacencyTest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Clion file\C\AdjacencyTest" "D:\Clion file\C\AdjacencyTest" "D:\Clion file\C\AdjacencyTest\cmake-build-debug" "D:\Clion file\C\AdjacencyTest\cmake-build-debug" "D:\Clion file\C\AdjacencyTest\cmake-build-debug\CMakeFiles\AdjacencyTest.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/AdjacencyTest.dir/depend

