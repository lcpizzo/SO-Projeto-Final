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
include tests/CMakeFiles/timeout.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/timeout.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/timeout.dir/flags.make

tests/CMakeFiles/timeout.dir/timeout.c.o: tests/CMakeFiles/timeout.dir/flags.make
tests/CMakeFiles/timeout.dir/timeout.c.o: tests/timeout.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/timeout.dir/timeout.c.o"
	cd "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/timeout.dir/timeout.c.o   -c "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests/timeout.c"

tests/CMakeFiles/timeout.dir/timeout.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/timeout.dir/timeout.c.i"
	cd "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests/timeout.c" > CMakeFiles/timeout.dir/timeout.c.i

tests/CMakeFiles/timeout.dir/timeout.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/timeout.dir/timeout.c.s"
	cd "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests/timeout.c" -o CMakeFiles/timeout.dir/timeout.c.s

tests/CMakeFiles/timeout.dir/timeout.c.o.requires:

.PHONY : tests/CMakeFiles/timeout.dir/timeout.c.o.requires

tests/CMakeFiles/timeout.dir/timeout.c.o.provides: tests/CMakeFiles/timeout.dir/timeout.c.o.requires
	$(MAKE) -f tests/CMakeFiles/timeout.dir/build.make tests/CMakeFiles/timeout.dir/timeout.c.o.provides.build
.PHONY : tests/CMakeFiles/timeout.dir/timeout.c.o.provides

tests/CMakeFiles/timeout.dir/timeout.c.o.provides.build: tests/CMakeFiles/timeout.dir/timeout.c.o


tests/CMakeFiles/timeout.dir/__/deps/glad.c.o: tests/CMakeFiles/timeout.dir/flags.make
tests/CMakeFiles/timeout.dir/__/deps/glad.c.o: deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/CMakeFiles/timeout.dir/__/deps/glad.c.o"
	cd "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/timeout.dir/__/deps/glad.c.o   -c "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/deps/glad.c"

tests/CMakeFiles/timeout.dir/__/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/timeout.dir/__/deps/glad.c.i"
	cd "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/deps/glad.c" > CMakeFiles/timeout.dir/__/deps/glad.c.i

tests/CMakeFiles/timeout.dir/__/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/timeout.dir/__/deps/glad.c.s"
	cd "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/deps/glad.c" -o CMakeFiles/timeout.dir/__/deps/glad.c.s

tests/CMakeFiles/timeout.dir/__/deps/glad.c.o.requires:

.PHONY : tests/CMakeFiles/timeout.dir/__/deps/glad.c.o.requires

tests/CMakeFiles/timeout.dir/__/deps/glad.c.o.provides: tests/CMakeFiles/timeout.dir/__/deps/glad.c.o.requires
	$(MAKE) -f tests/CMakeFiles/timeout.dir/build.make tests/CMakeFiles/timeout.dir/__/deps/glad.c.o.provides.build
.PHONY : tests/CMakeFiles/timeout.dir/__/deps/glad.c.o.provides

tests/CMakeFiles/timeout.dir/__/deps/glad.c.o.provides.build: tests/CMakeFiles/timeout.dir/__/deps/glad.c.o


# Object files for target timeout
timeout_OBJECTS = \
"CMakeFiles/timeout.dir/timeout.c.o" \
"CMakeFiles/timeout.dir/__/deps/glad.c.o"

# External object files for target timeout
timeout_EXTERNAL_OBJECTS =

tests/timeout: tests/CMakeFiles/timeout.dir/timeout.c.o
tests/timeout: tests/CMakeFiles/timeout.dir/__/deps/glad.c.o
tests/timeout: tests/CMakeFiles/timeout.dir/build.make
tests/timeout: src/libglfw.so.3.2
tests/timeout: /usr/lib/x86_64-linux-gnu/libm.so
tests/timeout: tests/CMakeFiles/timeout.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable timeout"
	cd "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/timeout.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/timeout.dir/build: tests/timeout

.PHONY : tests/CMakeFiles/timeout.dir/build

tests/CMakeFiles/timeout.dir/requires: tests/CMakeFiles/timeout.dir/timeout.c.o.requires
tests/CMakeFiles/timeout.dir/requires: tests/CMakeFiles/timeout.dir/__/deps/glad.c.o.requires

.PHONY : tests/CMakeFiles/timeout.dir/requires

tests/CMakeFiles/timeout.dir/clean:
	cd "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests" && $(CMAKE_COMMAND) -P CMakeFiles/timeout.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/timeout.dir/clean

tests/CMakeFiles/timeout.dir/depend:
	cd "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1" "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests" "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1" "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests" "/home/guijun/Área de Trabalho/grad/sistemOps/glfw-3.2.1/tests/CMakeFiles/timeout.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : tests/CMakeFiles/timeout.dir/depend
