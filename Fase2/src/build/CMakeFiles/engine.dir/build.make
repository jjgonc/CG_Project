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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/saraiva/Desktop/University/CG/CG_Project/Fase2/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/saraiva/Desktop/University/CG/CG_Project/Fase2/src/build

# Include any dependencies generated for this target.
include CMakeFiles/engine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/engine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/engine.dir/flags.make

CMakeFiles/engine.dir/engine.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/engine.cpp.o: ../engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/saraiva/Desktop/University/CG/CG_Project/Fase2/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/engine.dir/engine.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/engine.cpp.o -c /home/saraiva/Desktop/University/CG/CG_Project/Fase2/src/engine.cpp

CMakeFiles/engine.dir/engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/engine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saraiva/Desktop/University/CG/CG_Project/Fase2/src/engine.cpp > CMakeFiles/engine.dir/engine.cpp.i

CMakeFiles/engine.dir/engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/engine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saraiva/Desktop/University/CG/CG_Project/Fase2/src/engine.cpp -o CMakeFiles/engine.dir/engine.cpp.s

CMakeFiles/engine.dir/point.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/point.cpp.o: ../point.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/saraiva/Desktop/University/CG/CG_Project/Fase2/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/engine.dir/point.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/point.cpp.o -c /home/saraiva/Desktop/University/CG/CG_Project/Fase2/src/point.cpp

CMakeFiles/engine.dir/point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/point.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saraiva/Desktop/University/CG/CG_Project/Fase2/src/point.cpp > CMakeFiles/engine.dir/point.cpp.i

CMakeFiles/engine.dir/point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/point.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saraiva/Desktop/University/CG/CG_Project/Fase2/src/point.cpp -o CMakeFiles/engine.dir/point.cpp.s

CMakeFiles/engine.dir/vector.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/vector.cpp.o: ../vector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/saraiva/Desktop/University/CG/CG_Project/Fase2/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/engine.dir/vector.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/vector.cpp.o -c /home/saraiva/Desktop/University/CG/CG_Project/Fase2/src/vector.cpp

CMakeFiles/engine.dir/vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/vector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saraiva/Desktop/University/CG/CG_Project/Fase2/src/vector.cpp > CMakeFiles/engine.dir/vector.cpp.i

CMakeFiles/engine.dir/vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/vector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saraiva/Desktop/University/CG/CG_Project/Fase2/src/vector.cpp -o CMakeFiles/engine.dir/vector.cpp.s

CMakeFiles/engine.dir/tree.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/tree.cpp.o: ../tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/saraiva/Desktop/University/CG/CG_Project/Fase2/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/engine.dir/tree.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/tree.cpp.o -c /home/saraiva/Desktop/University/CG/CG_Project/Fase2/src/tree.cpp

CMakeFiles/engine.dir/tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/tree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saraiva/Desktop/University/CG/CG_Project/Fase2/src/tree.cpp > CMakeFiles/engine.dir/tree.cpp.i

CMakeFiles/engine.dir/tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/tree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saraiva/Desktop/University/CG/CG_Project/Fase2/src/tree.cpp -o CMakeFiles/engine.dir/tree.cpp.s

CMakeFiles/engine.dir/tinyxml2.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/tinyxml2.cpp.o: ../tinyxml2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/saraiva/Desktop/University/CG/CG_Project/Fase2/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/engine.dir/tinyxml2.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/tinyxml2.cpp.o -c /home/saraiva/Desktop/University/CG/CG_Project/Fase2/src/tinyxml2.cpp

CMakeFiles/engine.dir/tinyxml2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/tinyxml2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saraiva/Desktop/University/CG/CG_Project/Fase2/src/tinyxml2.cpp > CMakeFiles/engine.dir/tinyxml2.cpp.i

CMakeFiles/engine.dir/tinyxml2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/tinyxml2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saraiva/Desktop/University/CG/CG_Project/Fase2/src/tinyxml2.cpp -o CMakeFiles/engine.dir/tinyxml2.cpp.s

# Object files for target engine
engine_OBJECTS = \
"CMakeFiles/engine.dir/engine.cpp.o" \
"CMakeFiles/engine.dir/point.cpp.o" \
"CMakeFiles/engine.dir/vector.cpp.o" \
"CMakeFiles/engine.dir/tree.cpp.o" \
"CMakeFiles/engine.dir/tinyxml2.cpp.o"

# External object files for target engine
engine_EXTERNAL_OBJECTS =

engine: CMakeFiles/engine.dir/engine.cpp.o
engine: CMakeFiles/engine.dir/point.cpp.o
engine: CMakeFiles/engine.dir/vector.cpp.o
engine: CMakeFiles/engine.dir/tree.cpp.o
engine: CMakeFiles/engine.dir/tinyxml2.cpp.o
engine: CMakeFiles/engine.dir/build.make
engine: /usr/lib/x86_64-linux-gnu/libGL.so
engine: /usr/lib/x86_64-linux-gnu/libGLU.so
engine: /usr/lib/x86_64-linux-gnu/libglut.so
engine: /usr/lib/x86_64-linux-gnu/libXmu.so
engine: /usr/lib/x86_64-linux-gnu/libXi.so
engine: CMakeFiles/engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/saraiva/Desktop/University/CG/CG_Project/Fase2/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable engine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/engine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/engine.dir/build: engine

.PHONY : CMakeFiles/engine.dir/build

CMakeFiles/engine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/engine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/engine.dir/clean

CMakeFiles/engine.dir/depend:
	cd /home/saraiva/Desktop/University/CG/CG_Project/Fase2/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/saraiva/Desktop/University/CG/CG_Project/Fase2/src /home/saraiva/Desktop/University/CG/CG_Project/Fase2/src /home/saraiva/Desktop/University/CG/CG_Project/Fase2/src/build /home/saraiva/Desktop/University/CG/CG_Project/Fase2/src/build /home/saraiva/Desktop/University/CG/CG_Project/Fase2/src/build/CMakeFiles/engine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/engine.dir/depend

