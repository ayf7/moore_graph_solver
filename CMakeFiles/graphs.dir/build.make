# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_SOURCE_DIR = /home/anthony/scipoptsuite-8.0.4/GraphsProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anthony/scipoptsuite-8.0.4/GraphsProject

# Include any dependencies generated for this target.
include CMakeFiles/graphs.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/graphs.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/graphs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/graphs.dir/flags.make

CMakeFiles/graphs.dir/src/graphs.cpp.o: CMakeFiles/graphs.dir/flags.make
CMakeFiles/graphs.dir/src/graphs.cpp.o: src/graphs.cpp
CMakeFiles/graphs.dir/src/graphs.cpp.o: CMakeFiles/graphs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anthony/scipoptsuite-8.0.4/GraphsProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/graphs.dir/src/graphs.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/graphs.dir/src/graphs.cpp.o -MF CMakeFiles/graphs.dir/src/graphs.cpp.o.d -o CMakeFiles/graphs.dir/src/graphs.cpp.o -c /home/anthony/scipoptsuite-8.0.4/GraphsProject/src/graphs.cpp

CMakeFiles/graphs.dir/src/graphs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/graphs.dir/src/graphs.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anthony/scipoptsuite-8.0.4/GraphsProject/src/graphs.cpp > CMakeFiles/graphs.dir/src/graphs.cpp.i

CMakeFiles/graphs.dir/src/graphs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/graphs.dir/src/graphs.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anthony/scipoptsuite-8.0.4/GraphsProject/src/graphs.cpp -o CMakeFiles/graphs.dir/src/graphs.cpp.s

CMakeFiles/graphs.dir/src/graphs_main.cpp.o: CMakeFiles/graphs.dir/flags.make
CMakeFiles/graphs.dir/src/graphs_main.cpp.o: src/graphs_main.cpp
CMakeFiles/graphs.dir/src/graphs_main.cpp.o: CMakeFiles/graphs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anthony/scipoptsuite-8.0.4/GraphsProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/graphs.dir/src/graphs_main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/graphs.dir/src/graphs_main.cpp.o -MF CMakeFiles/graphs.dir/src/graphs_main.cpp.o.d -o CMakeFiles/graphs.dir/src/graphs_main.cpp.o -c /home/anthony/scipoptsuite-8.0.4/GraphsProject/src/graphs_main.cpp

CMakeFiles/graphs.dir/src/graphs_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/graphs.dir/src/graphs_main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anthony/scipoptsuite-8.0.4/GraphsProject/src/graphs_main.cpp > CMakeFiles/graphs.dir/src/graphs_main.cpp.i

CMakeFiles/graphs.dir/src/graphs_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/graphs.dir/src/graphs_main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anthony/scipoptsuite-8.0.4/GraphsProject/src/graphs_main.cpp -o CMakeFiles/graphs.dir/src/graphs_main.cpp.s

# Object files for target graphs
graphs_OBJECTS = \
"CMakeFiles/graphs.dir/src/graphs.cpp.o" \
"CMakeFiles/graphs.dir/src/graphs_main.cpp.o"

# External object files for target graphs
graphs_EXTERNAL_OBJECTS =

graphs: CMakeFiles/graphs.dir/src/graphs.cpp.o
graphs: CMakeFiles/graphs.dir/src/graphs_main.cpp.o
graphs: CMakeFiles/graphs.dir/build.make
graphs: /usr/local/lib/libscip.so.8.0.4.0
graphs: CMakeFiles/graphs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/anthony/scipoptsuite-8.0.4/GraphsProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable graphs"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/graphs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/graphs.dir/build: graphs
.PHONY : CMakeFiles/graphs.dir/build

CMakeFiles/graphs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/graphs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/graphs.dir/clean

CMakeFiles/graphs.dir/depend:
	cd /home/anthony/scipoptsuite-8.0.4/GraphsProject && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anthony/scipoptsuite-8.0.4/GraphsProject /home/anthony/scipoptsuite-8.0.4/GraphsProject /home/anthony/scipoptsuite-8.0.4/GraphsProject /home/anthony/scipoptsuite-8.0.4/GraphsProject /home/anthony/scipoptsuite-8.0.4/GraphsProject/CMakeFiles/graphs.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/graphs.dir/depend

