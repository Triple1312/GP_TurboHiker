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

# Utility rule file for uninstall.

# Include the progress variables for this target.
include dependencies/glew-2.1.0/build/cmake/CMakeFiles/uninstall.dir/progress.make

dependencies/glew-2.1.0/build/cmake/CMakeFiles/uninstall:
	cd /home/ppp/CLionProjects/untitled/GP_TurboHiker/cmake-build-release/dependencies/glew-2.1.0/build/cmake && /snap/clion/137/bin/cmake/linux/bin/cmake -P /home/ppp/CLionProjects/untitled/GP_TurboHiker/cmake-build-release/dependencies/glew-2.1.0/build/cmake/cmake_uninstall.cmake

uninstall: dependencies/glew-2.1.0/build/cmake/CMakeFiles/uninstall
uninstall: dependencies/glew-2.1.0/build/cmake/CMakeFiles/uninstall.dir/build.make

.PHONY : uninstall

# Rule to build all files generated by this target.
dependencies/glew-2.1.0/build/cmake/CMakeFiles/uninstall.dir/build: uninstall

.PHONY : dependencies/glew-2.1.0/build/cmake/CMakeFiles/uninstall.dir/build

dependencies/glew-2.1.0/build/cmake/CMakeFiles/uninstall.dir/clean:
	cd /home/ppp/CLionProjects/untitled/GP_TurboHiker/cmake-build-release/dependencies/glew-2.1.0/build/cmake && $(CMAKE_COMMAND) -P CMakeFiles/uninstall.dir/cmake_clean.cmake
.PHONY : dependencies/glew-2.1.0/build/cmake/CMakeFiles/uninstall.dir/clean

dependencies/glew-2.1.0/build/cmake/CMakeFiles/uninstall.dir/depend:
	cd /home/ppp/CLionProjects/untitled/GP_TurboHiker/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ppp/CLionProjects/untitled/GP_TurboHiker /home/ppp/CLionProjects/untitled/GP_TurboHiker/dependencies/glew-2.1.0/build/cmake /home/ppp/CLionProjects/untitled/GP_TurboHiker/cmake-build-release /home/ppp/CLionProjects/untitled/GP_TurboHiker/cmake-build-release/dependencies/glew-2.1.0/build/cmake /home/ppp/CLionProjects/untitled/GP_TurboHiker/cmake-build-release/dependencies/glew-2.1.0/build/cmake/CMakeFiles/uninstall.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : dependencies/glew-2.1.0/build/cmake/CMakeFiles/uninstall.dir/depend
