# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1"

# Include any dependencies generated for this target.
include tests/CMakeFiles/windows.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/windows.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/windows.dir/flags.make

tests/CMakeFiles/windows.dir/windows.c.o: tests/CMakeFiles/windows.dir/flags.make
tests/CMakeFiles/windows.dir/windows.c.o: tests/windows.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/windows.dir/windows.c.o"
	cd "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/windows.dir/windows.c.o   -c "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests/windows.c"

tests/CMakeFiles/windows.dir/windows.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/windows.dir/windows.c.i"
	cd "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests/windows.c" > CMakeFiles/windows.dir/windows.c.i

tests/CMakeFiles/windows.dir/windows.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/windows.dir/windows.c.s"
	cd "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests/windows.c" -o CMakeFiles/windows.dir/windows.c.s

tests/CMakeFiles/windows.dir/windows.c.o.requires:

.PHONY : tests/CMakeFiles/windows.dir/windows.c.o.requires

tests/CMakeFiles/windows.dir/windows.c.o.provides: tests/CMakeFiles/windows.dir/windows.c.o.requires
	$(MAKE) -f tests/CMakeFiles/windows.dir/build.make tests/CMakeFiles/windows.dir/windows.c.o.provides.build
.PHONY : tests/CMakeFiles/windows.dir/windows.c.o.provides

tests/CMakeFiles/windows.dir/windows.c.o.provides.build: tests/CMakeFiles/windows.dir/windows.c.o


tests/CMakeFiles/windows.dir/__/deps/getopt.c.o: tests/CMakeFiles/windows.dir/flags.make
tests/CMakeFiles/windows.dir/__/deps/getopt.c.o: deps/getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/CMakeFiles/windows.dir/__/deps/getopt.c.o"
	cd "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/windows.dir/__/deps/getopt.c.o   -c "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/deps/getopt.c"

tests/CMakeFiles/windows.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/windows.dir/__/deps/getopt.c.i"
	cd "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/deps/getopt.c" > CMakeFiles/windows.dir/__/deps/getopt.c.i

tests/CMakeFiles/windows.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/windows.dir/__/deps/getopt.c.s"
	cd "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/deps/getopt.c" -o CMakeFiles/windows.dir/__/deps/getopt.c.s

tests/CMakeFiles/windows.dir/__/deps/getopt.c.o.requires:

.PHONY : tests/CMakeFiles/windows.dir/__/deps/getopt.c.o.requires

tests/CMakeFiles/windows.dir/__/deps/getopt.c.o.provides: tests/CMakeFiles/windows.dir/__/deps/getopt.c.o.requires
	$(MAKE) -f tests/CMakeFiles/windows.dir/build.make tests/CMakeFiles/windows.dir/__/deps/getopt.c.o.provides.build
.PHONY : tests/CMakeFiles/windows.dir/__/deps/getopt.c.o.provides

tests/CMakeFiles/windows.dir/__/deps/getopt.c.o.provides.build: tests/CMakeFiles/windows.dir/__/deps/getopt.c.o


tests/CMakeFiles/windows.dir/__/deps/glad.c.o: tests/CMakeFiles/windows.dir/flags.make
tests/CMakeFiles/windows.dir/__/deps/glad.c.o: deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object tests/CMakeFiles/windows.dir/__/deps/glad.c.o"
	cd "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/windows.dir/__/deps/glad.c.o   -c "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/deps/glad.c"

tests/CMakeFiles/windows.dir/__/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/windows.dir/__/deps/glad.c.i"
	cd "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/deps/glad.c" > CMakeFiles/windows.dir/__/deps/glad.c.i

tests/CMakeFiles/windows.dir/__/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/windows.dir/__/deps/glad.c.s"
	cd "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/deps/glad.c" -o CMakeFiles/windows.dir/__/deps/glad.c.s

tests/CMakeFiles/windows.dir/__/deps/glad.c.o.requires:

.PHONY : tests/CMakeFiles/windows.dir/__/deps/glad.c.o.requires

tests/CMakeFiles/windows.dir/__/deps/glad.c.o.provides: tests/CMakeFiles/windows.dir/__/deps/glad.c.o.requires
	$(MAKE) -f tests/CMakeFiles/windows.dir/build.make tests/CMakeFiles/windows.dir/__/deps/glad.c.o.provides.build
.PHONY : tests/CMakeFiles/windows.dir/__/deps/glad.c.o.provides

tests/CMakeFiles/windows.dir/__/deps/glad.c.o.provides.build: tests/CMakeFiles/windows.dir/__/deps/glad.c.o


# Object files for target windows
windows_OBJECTS = \
"CMakeFiles/windows.dir/windows.c.o" \
"CMakeFiles/windows.dir/__/deps/getopt.c.o" \
"CMakeFiles/windows.dir/__/deps/glad.c.o"

# External object files for target windows
windows_EXTERNAL_OBJECTS =

tests/windows: tests/CMakeFiles/windows.dir/windows.c.o
tests/windows: tests/CMakeFiles/windows.dir/__/deps/getopt.c.o
tests/windows: tests/CMakeFiles/windows.dir/__/deps/glad.c.o
tests/windows: tests/CMakeFiles/windows.dir/build.make
tests/windows: src/libglfw.so.3.2
tests/windows: /usr/lib/x86_64-linux-gnu/libm.so
tests/windows: tests/CMakeFiles/windows.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable windows"
	cd "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/windows.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/windows.dir/build: tests/windows

.PHONY : tests/CMakeFiles/windows.dir/build

tests/CMakeFiles/windows.dir/requires: tests/CMakeFiles/windows.dir/windows.c.o.requires
tests/CMakeFiles/windows.dir/requires: tests/CMakeFiles/windows.dir/__/deps/getopt.c.o.requires
tests/CMakeFiles/windows.dir/requires: tests/CMakeFiles/windows.dir/__/deps/glad.c.o.requires

.PHONY : tests/CMakeFiles/windows.dir/requires

tests/CMakeFiles/windows.dir/clean:
	cd "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests" && $(CMAKE_COMMAND) -P CMakeFiles/windows.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/windows.dir/clean

tests/CMakeFiles/windows.dir/depend:
	cd "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1" "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests" "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1" "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests" "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests/CMakeFiles/windows.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : tests/CMakeFiles/windows.dir/depend

