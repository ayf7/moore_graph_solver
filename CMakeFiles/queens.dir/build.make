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
CMAKE_SOURCE_DIR = /home/anthony/scipoptsuite-8.0.4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anthony/scipoptsuite-8.0.4

# Include any dependencies generated for this target.
include scip/examples/Queens/CMakeFiles/queens.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include scip/examples/Queens/CMakeFiles/queens.dir/compiler_depend.make

# Include the progress variables for this target.
include scip/examples/Queens/CMakeFiles/queens.dir/progress.make

# Include the compile flags for this target's objects.
include scip/examples/Queens/CMakeFiles/queens.dir/flags.make

scip/examples/Queens/CMakeFiles/queens.dir/src/queens.cpp.o: scip/examples/Queens/CMakeFiles/queens.dir/flags.make
scip/examples/Queens/CMakeFiles/queens.dir/src/queens.cpp.o: scip/examples/Queens/src/queens.cpp
scip/examples/Queens/CMakeFiles/queens.dir/src/queens.cpp.o: scip/examples/Queens/CMakeFiles/queens.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anthony/scipoptsuite-8.0.4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object scip/examples/Queens/CMakeFiles/queens.dir/src/queens.cpp.o"
	cd /home/anthony/scipoptsuite-8.0.4/scip/examples/Queens && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT scip/examples/Queens/CMakeFiles/queens.dir/src/queens.cpp.o -MF CMakeFiles/queens.dir/src/queens.cpp.o.d -o CMakeFiles/queens.dir/src/queens.cpp.o -c /home/anthony/scipoptsuite-8.0.4/scip/examples/Queens/src/queens.cpp

scip/examples/Queens/CMakeFiles/queens.dir/src/queens.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/queens.dir/src/queens.cpp.i"
	cd /home/anthony/scipoptsuite-8.0.4/scip/examples/Queens && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anthony/scipoptsuite-8.0.4/scip/examples/Queens/src/queens.cpp > CMakeFiles/queens.dir/src/queens.cpp.i

scip/examples/Queens/CMakeFiles/queens.dir/src/queens.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/queens.dir/src/queens.cpp.s"
	cd /home/anthony/scipoptsuite-8.0.4/scip/examples/Queens && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anthony/scipoptsuite-8.0.4/scip/examples/Queens/src/queens.cpp -o CMakeFiles/queens.dir/src/queens.cpp.s

scip/examples/Queens/CMakeFiles/queens.dir/src/queens_main.cpp.o: scip/examples/Queens/CMakeFiles/queens.dir/flags.make
scip/examples/Queens/CMakeFiles/queens.dir/src/queens_main.cpp.o: scip/examples/Queens/src/queens_main.cpp
scip/examples/Queens/CMakeFiles/queens.dir/src/queens_main.cpp.o: scip/examples/Queens/CMakeFiles/queens.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anthony/scipoptsuite-8.0.4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object scip/examples/Queens/CMakeFiles/queens.dir/src/queens_main.cpp.o"
	cd /home/anthony/scipoptsuite-8.0.4/scip/examples/Queens && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT scip/examples/Queens/CMakeFiles/queens.dir/src/queens_main.cpp.o -MF CMakeFiles/queens.dir/src/queens_main.cpp.o.d -o CMakeFiles/queens.dir/src/queens_main.cpp.o -c /home/anthony/scipoptsuite-8.0.4/scip/examples/Queens/src/queens_main.cpp

scip/examples/Queens/CMakeFiles/queens.dir/src/queens_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/queens.dir/src/queens_main.cpp.i"
	cd /home/anthony/scipoptsuite-8.0.4/scip/examples/Queens && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anthony/scipoptsuite-8.0.4/scip/examples/Queens/src/queens_main.cpp > CMakeFiles/queens.dir/src/queens_main.cpp.i

scip/examples/Queens/CMakeFiles/queens.dir/src/queens_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/queens.dir/src/queens_main.cpp.s"
	cd /home/anthony/scipoptsuite-8.0.4/scip/examples/Queens && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anthony/scipoptsuite-8.0.4/scip/examples/Queens/src/queens_main.cpp -o CMakeFiles/queens.dir/src/queens_main.cpp.s

# Object files for target queens
queens_OBJECTS = \
"CMakeFiles/queens.dir/src/queens.cpp.o" \
"CMakeFiles/queens.dir/src/queens_main.cpp.o"

# External object files for target queens
queens_EXTERNAL_OBJECTS =

bin/examples/queens: scip/examples/Queens/CMakeFiles/queens.dir/src/queens.cpp.o
bin/examples/queens: scip/examples/Queens/CMakeFiles/queens.dir/src/queens_main.cpp.o
bin/examples/queens: scip/examples/Queens/CMakeFiles/queens.dir/build.make
bin/examples/queens: lib/libscip.so.8.0.4.0
bin/examples/queens: scip/examples/Queens/CMakeFiles/queens.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/anthony/scipoptsuite-8.0.4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../../bin/examples/queens"
	cd /home/anthony/scipoptsuite-8.0.4/scip/examples/Queens && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/queens.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
scip/examples/Queens/CMakeFiles/queens.dir/build: bin/examples/queens
.PHONY : scip/examples/Queens/CMakeFiles/queens.dir/build

scip/examples/Queens/CMakeFiles/queens.dir/clean:
	cd /home/anthony/scipoptsuite-8.0.4/scip/examples/Queens && $(CMAKE_COMMAND) -P CMakeFiles/queens.dir/cmake_clean.cmake
.PHONY : scip/examples/Queens/CMakeFiles/queens.dir/clean

scip/examples/Queens/CMakeFiles/queens.dir/depend:
	cd /home/anthony/scipoptsuite-8.0.4 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anthony/scipoptsuite-8.0.4 /home/anthony/scipoptsuite-8.0.4/scip/examples/Queens /home/anthony/scipoptsuite-8.0.4 /home/anthony/scipoptsuite-8.0.4/scip/examples/Queens /home/anthony/scipoptsuite-8.0.4/scip/examples/Queens/CMakeFiles/queens.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : scip/examples/Queens/CMakeFiles/queens.dir/depend

