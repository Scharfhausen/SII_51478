# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/jorge/Documentos/Lab_SII/azornoza-sii_51540-4046e0431dfa/practica1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jorge/Documentos/Lab_SII/azornoza-sii_51540-4046e0431dfa/practica1/build

# Include any dependencies generated for this target.
include src/CMakeFiles/logger.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/logger.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/logger.dir/flags.make

src/CMakeFiles/logger.dir/logger.cpp.o: src/CMakeFiles/logger.dir/flags.make
src/CMakeFiles/logger.dir/logger.cpp.o: ../src/logger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jorge/Documentos/Lab_SII/azornoza-sii_51540-4046e0431dfa/practica1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/logger.dir/logger.cpp.o"
	cd /home/jorge/Documentos/Lab_SII/azornoza-sii_51540-4046e0431dfa/practica1/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/logger.dir/logger.cpp.o -c /home/jorge/Documentos/Lab_SII/azornoza-sii_51540-4046e0431dfa/practica1/src/logger.cpp

src/CMakeFiles/logger.dir/logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/logger.dir/logger.cpp.i"
	cd /home/jorge/Documentos/Lab_SII/azornoza-sii_51540-4046e0431dfa/practica1/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jorge/Documentos/Lab_SII/azornoza-sii_51540-4046e0431dfa/practica1/src/logger.cpp > CMakeFiles/logger.dir/logger.cpp.i

src/CMakeFiles/logger.dir/logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/logger.dir/logger.cpp.s"
	cd /home/jorge/Documentos/Lab_SII/azornoza-sii_51540-4046e0431dfa/practica1/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jorge/Documentos/Lab_SII/azornoza-sii_51540-4046e0431dfa/practica1/src/logger.cpp -o CMakeFiles/logger.dir/logger.cpp.s

src/CMakeFiles/logger.dir/logger.cpp.o.requires:

.PHONY : src/CMakeFiles/logger.dir/logger.cpp.o.requires

src/CMakeFiles/logger.dir/logger.cpp.o.provides: src/CMakeFiles/logger.dir/logger.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/logger.dir/build.make src/CMakeFiles/logger.dir/logger.cpp.o.provides.build
.PHONY : src/CMakeFiles/logger.dir/logger.cpp.o.provides

src/CMakeFiles/logger.dir/logger.cpp.o.provides.build: src/CMakeFiles/logger.dir/logger.cpp.o


# Object files for target logger
logger_OBJECTS = \
"CMakeFiles/logger.dir/logger.cpp.o"

# External object files for target logger
logger_EXTERNAL_OBJECTS =

src/logger: src/CMakeFiles/logger.dir/logger.cpp.o
src/logger: src/CMakeFiles/logger.dir/build.make
src/logger: src/CMakeFiles/logger.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jorge/Documentos/Lab_SII/azornoza-sii_51540-4046e0431dfa/practica1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable logger"
	cd /home/jorge/Documentos/Lab_SII/azornoza-sii_51540-4046e0431dfa/practica1/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/logger.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/logger.dir/build: src/logger

.PHONY : src/CMakeFiles/logger.dir/build

src/CMakeFiles/logger.dir/requires: src/CMakeFiles/logger.dir/logger.cpp.o.requires

.PHONY : src/CMakeFiles/logger.dir/requires

src/CMakeFiles/logger.dir/clean:
	cd /home/jorge/Documentos/Lab_SII/azornoza-sii_51540-4046e0431dfa/practica1/build/src && $(CMAKE_COMMAND) -P CMakeFiles/logger.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/logger.dir/clean

src/CMakeFiles/logger.dir/depend:
	cd /home/jorge/Documentos/Lab_SII/azornoza-sii_51540-4046e0431dfa/practica1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jorge/Documentos/Lab_SII/azornoza-sii_51540-4046e0431dfa/practica1 /home/jorge/Documentos/Lab_SII/azornoza-sii_51540-4046e0431dfa/practica1/src /home/jorge/Documentos/Lab_SII/azornoza-sii_51540-4046e0431dfa/practica1/build /home/jorge/Documentos/Lab_SII/azornoza-sii_51540-4046e0431dfa/practica1/build/src /home/jorge/Documentos/Lab_SII/azornoza-sii_51540-4046e0431dfa/practica1/build/src/CMakeFiles/logger.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/logger.dir/depend

