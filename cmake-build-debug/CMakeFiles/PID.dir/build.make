# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.1.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\tiger\CLionProjects\PID-controller

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\tiger\CLionProjects\PID-controller\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PID.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PID.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PID.dir/flags.make

CMakeFiles/PID.dir/src/PID.cpp.obj: CMakeFiles/PID.dir/flags.make
CMakeFiles/PID.dir/src/PID.cpp.obj: CMakeFiles/PID.dir/includes_CXX.rsp
CMakeFiles/PID.dir/src/PID.cpp.obj: ../src/PID.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\tiger\CLionProjects\PID-controller\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PID.dir/src/PID.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\PID.dir\src\PID.cpp.obj -c C:\Users\tiger\CLionProjects\PID-controller\src\PID.cpp

CMakeFiles/PID.dir/src/PID.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PID.dir/src/PID.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\tiger\CLionProjects\PID-controller\src\PID.cpp > CMakeFiles\PID.dir\src\PID.cpp.i

CMakeFiles/PID.dir/src/PID.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PID.dir/src/PID.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\tiger\CLionProjects\PID-controller\src\PID.cpp -o CMakeFiles\PID.dir\src\PID.cpp.s

# Object files for target PID
PID_OBJECTS = \
"CMakeFiles/PID.dir/src/PID.cpp.obj"

# External object files for target PID
PID_EXTERNAL_OBJECTS =

libPID.a: CMakeFiles/PID.dir/src/PID.cpp.obj
libPID.a: CMakeFiles/PID.dir/build.make
libPID.a: CMakeFiles/PID.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\tiger\CLionProjects\PID-controller\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libPID.a"
	$(CMAKE_COMMAND) -P CMakeFiles\PID.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\PID.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PID.dir/build: libPID.a

.PHONY : CMakeFiles/PID.dir/build

CMakeFiles/PID.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\PID.dir\cmake_clean.cmake
.PHONY : CMakeFiles/PID.dir/clean

CMakeFiles/PID.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\tiger\CLionProjects\PID-controller C:\Users\tiger\CLionProjects\PID-controller C:\Users\tiger\CLionProjects\PID-controller\cmake-build-debug C:\Users\tiger\CLionProjects\PID-controller\cmake-build-debug C:\Users\tiger\CLionProjects\PID-controller\cmake-build-debug\CMakeFiles\PID.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PID.dir/depend
