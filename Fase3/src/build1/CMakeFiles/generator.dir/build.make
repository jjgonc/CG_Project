# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/build1"

# Include any dependencies generated for this target.
include CMakeFiles/generator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/generator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/generator.dir/flags.make

CMakeFiles/generator.dir/generator.cpp.o: CMakeFiles/generator.dir/flags.make
CMakeFiles/generator.dir/generator.cpp.o: ../generator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/build1/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/generator.dir/generator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/generator.dir/generator.cpp.o -c "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/generator.cpp"

CMakeFiles/generator.dir/generator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/generator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/generator.cpp" > CMakeFiles/generator.dir/generator.cpp.i

CMakeFiles/generator.dir/generator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/generator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/generator.cpp" -o CMakeFiles/generator.dir/generator.cpp.s

CMakeFiles/generator.dir/point.cpp.o: CMakeFiles/generator.dir/flags.make
CMakeFiles/generator.dir/point.cpp.o: ../point.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/build1/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/generator.dir/point.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/generator.dir/point.cpp.o -c "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/point.cpp"

CMakeFiles/generator.dir/point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/point.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/point.cpp" > CMakeFiles/generator.dir/point.cpp.i

CMakeFiles/generator.dir/point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/point.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/point.cpp" -o CMakeFiles/generator.dir/point.cpp.s

CMakeFiles/generator.dir/vector.cpp.o: CMakeFiles/generator.dir/flags.make
CMakeFiles/generator.dir/vector.cpp.o: ../vector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/build1/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/generator.dir/vector.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/generator.dir/vector.cpp.o -c "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/vector.cpp"

CMakeFiles/generator.dir/vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/vector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/vector.cpp" > CMakeFiles/generator.dir/vector.cpp.i

CMakeFiles/generator.dir/vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/vector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/vector.cpp" -o CMakeFiles/generator.dir/vector.cpp.s

CMakeFiles/generator.dir/plane.cpp.o: CMakeFiles/generator.dir/flags.make
CMakeFiles/generator.dir/plane.cpp.o: ../plane.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/build1/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/generator.dir/plane.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/generator.dir/plane.cpp.o -c "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/plane.cpp"

CMakeFiles/generator.dir/plane.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/plane.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/plane.cpp" > CMakeFiles/generator.dir/plane.cpp.i

CMakeFiles/generator.dir/plane.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/plane.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/plane.cpp" -o CMakeFiles/generator.dir/plane.cpp.s

CMakeFiles/generator.dir/box.cpp.o: CMakeFiles/generator.dir/flags.make
CMakeFiles/generator.dir/box.cpp.o: ../box.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/build1/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/generator.dir/box.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/generator.dir/box.cpp.o -c "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/box.cpp"

CMakeFiles/generator.dir/box.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/box.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/box.cpp" > CMakeFiles/generator.dir/box.cpp.i

CMakeFiles/generator.dir/box.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/box.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/box.cpp" -o CMakeFiles/generator.dir/box.cpp.s

CMakeFiles/generator.dir/sphere.cpp.o: CMakeFiles/generator.dir/flags.make
CMakeFiles/generator.dir/sphere.cpp.o: ../sphere.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/build1/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/generator.dir/sphere.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/generator.dir/sphere.cpp.o -c "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/sphere.cpp"

CMakeFiles/generator.dir/sphere.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/sphere.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/sphere.cpp" > CMakeFiles/generator.dir/sphere.cpp.i

CMakeFiles/generator.dir/sphere.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/sphere.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/sphere.cpp" -o CMakeFiles/generator.dir/sphere.cpp.s

CMakeFiles/generator.dir/cone.cpp.o: CMakeFiles/generator.dir/flags.make
CMakeFiles/generator.dir/cone.cpp.o: ../cone.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/build1/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/generator.dir/cone.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/generator.dir/cone.cpp.o -c "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/cone.cpp"

CMakeFiles/generator.dir/cone.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/cone.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/cone.cpp" > CMakeFiles/generator.dir/cone.cpp.i

CMakeFiles/generator.dir/cone.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/cone.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/cone.cpp" -o CMakeFiles/generator.dir/cone.cpp.s

CMakeFiles/generator.dir/torus.cpp.o: CMakeFiles/generator.dir/flags.make
CMakeFiles/generator.dir/torus.cpp.o: ../torus.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/build1/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/generator.dir/torus.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/generator.dir/torus.cpp.o -c "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/torus.cpp"

CMakeFiles/generator.dir/torus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/torus.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/torus.cpp" > CMakeFiles/generator.dir/torus.cpp.i

CMakeFiles/generator.dir/torus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/torus.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/torus.cpp" -o CMakeFiles/generator.dir/torus.cpp.s

CMakeFiles/generator.dir/bezier.cpp.o: CMakeFiles/generator.dir/flags.make
CMakeFiles/generator.dir/bezier.cpp.o: ../bezier.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/build1/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/generator.dir/bezier.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/generator.dir/bezier.cpp.o -c "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/bezier.cpp"

CMakeFiles/generator.dir/bezier.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/bezier.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/bezier.cpp" > CMakeFiles/generator.dir/bezier.cpp.i

CMakeFiles/generator.dir/bezier.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/bezier.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/bezier.cpp" -o CMakeFiles/generator.dir/bezier.cpp.s

# Object files for target generator
generator_OBJECTS = \
"CMakeFiles/generator.dir/generator.cpp.o" \
"CMakeFiles/generator.dir/point.cpp.o" \
"CMakeFiles/generator.dir/vector.cpp.o" \
"CMakeFiles/generator.dir/plane.cpp.o" \
"CMakeFiles/generator.dir/box.cpp.o" \
"CMakeFiles/generator.dir/sphere.cpp.o" \
"CMakeFiles/generator.dir/cone.cpp.o" \
"CMakeFiles/generator.dir/torus.cpp.o" \
"CMakeFiles/generator.dir/bezier.cpp.o"

# External object files for target generator
generator_EXTERNAL_OBJECTS =

generator: CMakeFiles/generator.dir/generator.cpp.o
generator: CMakeFiles/generator.dir/point.cpp.o
generator: CMakeFiles/generator.dir/vector.cpp.o
generator: CMakeFiles/generator.dir/plane.cpp.o
generator: CMakeFiles/generator.dir/box.cpp.o
generator: CMakeFiles/generator.dir/sphere.cpp.o
generator: CMakeFiles/generator.dir/cone.cpp.o
generator: CMakeFiles/generator.dir/torus.cpp.o
generator: CMakeFiles/generator.dir/bezier.cpp.o
generator: CMakeFiles/generator.dir/build.make
generator: CMakeFiles/generator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/build1/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable generator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/generator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/generator.dir/build: generator

.PHONY : CMakeFiles/generator.dir/build

CMakeFiles/generator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/generator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/generator.dir/clean

CMakeFiles/generator.dir/depend:
	cd "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/build1" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src" "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src" "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/build1" "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/build1" "/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Fase3/src/build1/CMakeFiles/generator.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/generator.dir/depend

