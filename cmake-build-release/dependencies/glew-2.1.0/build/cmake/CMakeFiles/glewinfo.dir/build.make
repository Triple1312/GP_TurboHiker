# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /snap/clion/137/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/137/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ppp/CLionProjects/untitled/GP_TurboHiker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ppp/CLionProjects/untitled/GP_TurboHiker/cmake-build-release

# Include any dependencies generated for this target.
include dependencies/glew-2.1.0/build/cmake/CMakeFiles/glewinfo.dir/depend.make

# Include the progress variables for this target.
include dependencies/glew-2.1.0/build/cmake/CMakeFiles/glewinfo.dir/progress.make

# Include the compile flags for this target's objects.
include dependencies/glew-2.1.0/build/cmake/CMakeFiles/glewinfo.dir/flags.make

dependencies/glew-2.1.0/build/cmake/CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.o: dependencies/glew-2.1.0/build/cmake/CMakeFiles/glewinfo.dir/flags.make
dependencies/glew-2.1.0/build/cmake/CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.o: ../dependencies/glew-2.1.0/src/glewinfo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ppp/CLionProjects/untitled/GP_TurboHiker/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object dependencies/glew-2.1.0/build/cmake/CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.o"
	cd /home/ppp/CLionProjects/untitled/GP_TurboHiker/cmake-build-release/dependencies/glew-2.1.0/build/cmake && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.o   -c /home/ppp/CLionProjects/untitled/GP_TurboHiker/dependencies/glew-2.1.0/src/glewinfo.c

dependencies/glew-2.1.0/build/cmake/CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.i"
	cd /home/ppp/CLionProjects/untitled/GP_TurboHiker/cmake-build-release/dependencies/glew-2.1.0/build/cmake && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ppp/CLionProjects/untitled/GP_TurboHiker/dependencies/glew-2.1.0/src/glewinfo.c > CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.i

dependencies/glew-2.1.0/build/cmake/CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.s"
	cd /home/ppp/CLionProjects/untitled/GP_TurboHiker/cmake-build-release/dependencies/glew-2.1.0/build/cmake && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ppp/CLionProjects/untitled/GP_TurboHiker/dependencies/glew-2.1.0/src/glewinfo.c -o CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.s

# Object files for target glewinfo
glewinfo_OBJECTS = \
"CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.o"

# External object files for target glewinfo
glewinfo_EXTERNAL_OBJECTS =

bin/glewinfo: dependencies/glew-2.1.0/build/cmake/CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.o
bin/glewinfo: dependencies/glew-2.1.0/build/cmake/CMakeFiles/glewinfo.dir/build.make
bin/glewinfo: lib/libGLEW.so.2.1.0
bin/glewinfo: /usr/lib/x86_64-linux-gnu/libSM.so
bin/glewinfo: /usr/lib/x86_64-linux-gnu/libICE.so
bin/glewinfo: /usr/lib/x86_64-linux-gnu/libX11.so
bin/glewinfo: /usr/lib/x86_64-linux-gnu/libXext.so
bin/glewinfo: /usr/lib/x86_64-linux-gnu/libGL.so
bin/glewinfo: dependencies/glew-2.1.0/build/cmake/CMakeFiles/glewinfo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ppp/CLionProjects/untitled/GP_TurboHiker/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../../../../bin/glewinfo"
	cd /home/ppp/CLionProjects/untitled/GP_TurboHiker/cmake-build-release/dependencies/glew-2.1.0/build/cmake && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glewinfo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
dependencies/glew-2.1.0/build/cmake/CMakeFiles/glewinfo.dir/build: bin/glewinfo

.PHONY : dependencies/glew-2.1.0/build/cmake/CMakeFiles/glewinfo.dir/build

dependencies/glew-2.1.0/build/cmake/CMakeFiles/glewinfo.dir/clean:
	cd /home/ppp/CLionProjects/untitled/GP_TurboHiker/cmake-build-release/dependencies/glew-2.1.0/build/cmake && $(CMAKE_COMMAND) -P CMakeFiles/glewinfo.dir/cmake_clean.cmake
.PHONY : dependencies/glew-2.1.0/build/cmake/CMakeFiles/glewinfo.dir/clean

dependencies/glew-2.1.0/build/cmake/CMakeFiles/glewinfo.dir/depend:
	cd /home/ppp/CLionProjects/untitled/GP_TurboHiker/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ppp/CLionProjects/untitled/GP_TurboHiker /home/ppp/CLionProjects/untitled/GP_TurboHiker/dependencies/glew-2.1.0/build/cmake /home/ppp/CLionProjects/untitled/GP_TurboHiker/cmake-build-release /home/ppp/CLionProjects/untitled/GP_TurboHiker/cmake-build-release/dependencies/glew-2.1.0/build/cmake /home/ppp/CLionProjects/untitled/GP_TurboHiker/cmake-build-release/dependencies/glew-2.1.0/build/cmake/CMakeFiles/glewinfo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : dependencies/glew-2.1.0/build/cmake/CMakeFiles/glewinfo.dir/depend
