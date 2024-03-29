# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/eehab-saadat/Documents/OOP/Project/first-integrated/Cosmic-Assault

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/eehab-saadat/Documents/OOP/Project/first-integrated/Cosmic-Assault

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/eehab-saadat/Documents/OOP/Project/first-integrated/Cosmic-Assault/CMakeFiles /home/eehab-saadat/Documents/OOP/Project/first-integrated/Cosmic-Assault//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/eehab-saadat/Documents/OOP/Project/first-integrated/Cosmic-Assault/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named COSMIC-ASSAULT

# Build rule for target.
COSMIC-ASSAULT: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 COSMIC-ASSAULT
.PHONY : COSMIC-ASSAULT

# fast build rule for target.
COSMIC-ASSAULT/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/COSMIC-ASSAULT.dir/build.make CMakeFiles/COSMIC-ASSAULT.dir/build
.PHONY : COSMIC-ASSAULT/fast

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/COSMIC-ASSAULT.dir/build.make CMakeFiles/COSMIC-ASSAULT.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/COSMIC-ASSAULT.dir/build.make CMakeFiles/COSMIC-ASSAULT.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/COSMIC-ASSAULT.dir/build.make CMakeFiles/COSMIC-ASSAULT.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/playGame.o: src/playGame.cpp.o
.PHONY : src/playGame.o

# target to build an object file
src/playGame.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/COSMIC-ASSAULT.dir/build.make CMakeFiles/COSMIC-ASSAULT.dir/src/playGame.cpp.o
.PHONY : src/playGame.cpp.o

src/playGame.i: src/playGame.cpp.i
.PHONY : src/playGame.i

# target to preprocess a source file
src/playGame.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/COSMIC-ASSAULT.dir/build.make CMakeFiles/COSMIC-ASSAULT.dir/src/playGame.cpp.i
.PHONY : src/playGame.cpp.i

src/playGame.s: src/playGame.cpp.s
.PHONY : src/playGame.s

# target to generate assembly for a file
src/playGame.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/COSMIC-ASSAULT.dir/build.make CMakeFiles/COSMIC-ASSAULT.dir/src/playGame.cpp.s
.PHONY : src/playGame.cpp.s

src/screens.o: src/screens.cpp.o
.PHONY : src/screens.o

# target to build an object file
src/screens.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/COSMIC-ASSAULT.dir/build.make CMakeFiles/COSMIC-ASSAULT.dir/src/screens.cpp.o
.PHONY : src/screens.cpp.o

src/screens.i: src/screens.cpp.i
.PHONY : src/screens.i

# target to preprocess a source file
src/screens.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/COSMIC-ASSAULT.dir/build.make CMakeFiles/COSMIC-ASSAULT.dir/src/screens.cpp.i
.PHONY : src/screens.cpp.i

src/screens.s: src/screens.cpp.s
.PHONY : src/screens.s

# target to generate assembly for a file
src/screens.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/COSMIC-ASSAULT.dir/build.make CMakeFiles/COSMIC-ASSAULT.dir/src/screens.cpp.s
.PHONY : src/screens.cpp.s

src/spacecraftAndBullet.o: src/spacecraftAndBullet.cpp.o
.PHONY : src/spacecraftAndBullet.o

# target to build an object file
src/spacecraftAndBullet.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/COSMIC-ASSAULT.dir/build.make CMakeFiles/COSMIC-ASSAULT.dir/src/spacecraftAndBullet.cpp.o
.PHONY : src/spacecraftAndBullet.cpp.o

src/spacecraftAndBullet.i: src/spacecraftAndBullet.cpp.i
.PHONY : src/spacecraftAndBullet.i

# target to preprocess a source file
src/spacecraftAndBullet.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/COSMIC-ASSAULT.dir/build.make CMakeFiles/COSMIC-ASSAULT.dir/src/spacecraftAndBullet.cpp.i
.PHONY : src/spacecraftAndBullet.cpp.i

src/spacecraftAndBullet.s: src/spacecraftAndBullet.cpp.s
.PHONY : src/spacecraftAndBullet.s

# target to generate assembly for a file
src/spacecraftAndBullet.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/COSMIC-ASSAULT.dir/build.make CMakeFiles/COSMIC-ASSAULT.dir/src/spacecraftAndBullet.cpp.s
.PHONY : src/spacecraftAndBullet.cpp.s

src/test1.o: src/test1.cpp.o
.PHONY : src/test1.o

# target to build an object file
src/test1.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/COSMIC-ASSAULT.dir/build.make CMakeFiles/COSMIC-ASSAULT.dir/src/test1.cpp.o
.PHONY : src/test1.cpp.o

src/test1.i: src/test1.cpp.i
.PHONY : src/test1.i

# target to preprocess a source file
src/test1.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/COSMIC-ASSAULT.dir/build.make CMakeFiles/COSMIC-ASSAULT.dir/src/test1.cpp.i
.PHONY : src/test1.cpp.i

src/test1.s: src/test1.cpp.s
.PHONY : src/test1.s

# target to generate assembly for a file
src/test1.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/COSMIC-ASSAULT.dir/build.make CMakeFiles/COSMIC-ASSAULT.dir/src/test1.cpp.s
.PHONY : src/test1.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... COSMIC-ASSAULT"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/playGame.o"
	@echo "... src/playGame.i"
	@echo "... src/playGame.s"
	@echo "... src/screens.o"
	@echo "... src/screens.i"
	@echo "... src/screens.s"
	@echo "... src/spacecraftAndBullet.o"
	@echo "... src/spacecraftAndBullet.i"
	@echo "... src/spacecraftAndBullet.s"
	@echo "... src/test1.o"
	@echo "... src/test1.i"
	@echo "... src/test1.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

