# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\nmari\CLionProjects\PracticaFinalIG

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\nmari\CLionProjects\PracticaFinalIG\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PracticaHelicoptero.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/PracticaHelicoptero.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PracticaHelicoptero.dir/flags.make

CMakeFiles/PracticaHelicoptero.dir/src/Model.cpp.obj: CMakeFiles/PracticaHelicoptero.dir/flags.make
CMakeFiles/PracticaHelicoptero.dir/src/Model.cpp.obj: CMakeFiles/PracticaHelicoptero.dir/includes_CXX.rsp
CMakeFiles/PracticaHelicoptero.dir/src/Model.cpp.obj: ../src/Model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\nmari\CLionProjects\PracticaFinalIG\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PracticaHelicoptero.dir/src/Model.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\PracticaHelicoptero.dir\src\Model.cpp.obj -c C:\Users\nmari\CLionProjects\PracticaFinalIG\src\Model.cpp

CMakeFiles/PracticaHelicoptero.dir/src/Model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PracticaHelicoptero.dir/src/Model.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\nmari\CLionProjects\PracticaFinalIG\src\Model.cpp > CMakeFiles\PracticaHelicoptero.dir\src\Model.cpp.i

CMakeFiles/PracticaHelicoptero.dir/src/Model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PracticaHelicoptero.dir/src/Model.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\nmari\CLionProjects\PracticaFinalIG\src\Model.cpp -o CMakeFiles\PracticaHelicoptero.dir\src\Model.cpp.s

CMakeFiles/PracticaHelicoptero.dir/src/Shaders.cpp.obj: CMakeFiles/PracticaHelicoptero.dir/flags.make
CMakeFiles/PracticaHelicoptero.dir/src/Shaders.cpp.obj: CMakeFiles/PracticaHelicoptero.dir/includes_CXX.rsp
CMakeFiles/PracticaHelicoptero.dir/src/Shaders.cpp.obj: ../src/Shaders.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\nmari\CLionProjects\PracticaFinalIG\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PracticaHelicoptero.dir/src/Shaders.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\PracticaHelicoptero.dir\src\Shaders.cpp.obj -c C:\Users\nmari\CLionProjects\PracticaFinalIG\src\Shaders.cpp

CMakeFiles/PracticaHelicoptero.dir/src/Shaders.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PracticaHelicoptero.dir/src/Shaders.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\nmari\CLionProjects\PracticaFinalIG\src\Shaders.cpp > CMakeFiles\PracticaHelicoptero.dir\src\Shaders.cpp.i

CMakeFiles/PracticaHelicoptero.dir/src/Shaders.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PracticaHelicoptero.dir/src/Shaders.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\nmari\CLionProjects\PracticaFinalIG\src\Shaders.cpp -o CMakeFiles\PracticaHelicoptero.dir\src\Shaders.cpp.s

CMakeFiles/PracticaHelicoptero.dir/src/main.cpp.obj: CMakeFiles/PracticaHelicoptero.dir/flags.make
CMakeFiles/PracticaHelicoptero.dir/src/main.cpp.obj: CMakeFiles/PracticaHelicoptero.dir/includes_CXX.rsp
CMakeFiles/PracticaHelicoptero.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\nmari\CLionProjects\PracticaFinalIG\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/PracticaHelicoptero.dir/src/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\PracticaHelicoptero.dir\src\main.cpp.obj -c C:\Users\nmari\CLionProjects\PracticaFinalIG\src\main.cpp

CMakeFiles/PracticaHelicoptero.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PracticaHelicoptero.dir/src/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\nmari\CLionProjects\PracticaFinalIG\src\main.cpp > CMakeFiles\PracticaHelicoptero.dir\src\main.cpp.i

CMakeFiles/PracticaHelicoptero.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PracticaHelicoptero.dir/src/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\nmari\CLionProjects\PracticaFinalIG\src\main.cpp -o CMakeFiles\PracticaHelicoptero.dir\src\main.cpp.s

# Object files for target PracticaHelicoptero
PracticaHelicoptero_OBJECTS = \
"CMakeFiles/PracticaHelicoptero.dir/src/Model.cpp.obj" \
"CMakeFiles/PracticaHelicoptero.dir/src/Shaders.cpp.obj" \
"CMakeFiles/PracticaHelicoptero.dir/src/main.cpp.obj"

# External object files for target PracticaHelicoptero
PracticaHelicoptero_EXTERNAL_OBJECTS =

binary/PracticaHelicoptero.exe: CMakeFiles/PracticaHelicoptero.dir/src/Model.cpp.obj
binary/PracticaHelicoptero.exe: CMakeFiles/PracticaHelicoptero.dir/src/Shaders.cpp.obj
binary/PracticaHelicoptero.exe: CMakeFiles/PracticaHelicoptero.dir/src/main.cpp.obj
binary/PracticaHelicoptero.exe: CMakeFiles/PracticaHelicoptero.dir/build.make
binary/PracticaHelicoptero.exe: CMakeFiles/PracticaHelicoptero.dir/linklibs.rsp
binary/PracticaHelicoptero.exe: CMakeFiles/PracticaHelicoptero.dir/objects1.rsp
binary/PracticaHelicoptero.exe: CMakeFiles/PracticaHelicoptero.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\nmari\CLionProjects\PracticaFinalIG\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable binary\PracticaHelicoptero.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\PracticaHelicoptero.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PracticaHelicoptero.dir/build: binary/PracticaHelicoptero.exe
.PHONY : CMakeFiles/PracticaHelicoptero.dir/build

CMakeFiles/PracticaHelicoptero.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\PracticaHelicoptero.dir\cmake_clean.cmake
.PHONY : CMakeFiles/PracticaHelicoptero.dir/clean

CMakeFiles/PracticaHelicoptero.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\nmari\CLionProjects\PracticaFinalIG C:\Users\nmari\CLionProjects\PracticaFinalIG C:\Users\nmari\CLionProjects\PracticaFinalIG\cmake-build-debug C:\Users\nmari\CLionProjects\PracticaFinalIG\cmake-build-debug C:\Users\nmari\CLionProjects\PracticaFinalIG\cmake-build-debug\CMakeFiles\PracticaHelicoptero.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PracticaHelicoptero.dir/depend

