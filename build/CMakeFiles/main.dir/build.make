# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/pedro0210/Projects/AsteroidsPthreads

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pedro0210/Projects/AsteroidsPthreads/build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/src/main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/main.cpp.o: /home/pedro0210/Projects/AsteroidsPthreads/src/main.cpp
CMakeFiles/main.dir/src/main.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/pedro0210/Projects/AsteroidsPthreads/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/main.cpp.o -MF CMakeFiles/main.dir/src/main.cpp.o.d -o CMakeFiles/main.dir/src/main.cpp.o -c /home/pedro0210/Projects/AsteroidsPthreads/src/main.cpp

CMakeFiles/main.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pedro0210/Projects/AsteroidsPthreads/src/main.cpp > CMakeFiles/main.dir/src/main.cpp.i

CMakeFiles/main.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pedro0210/Projects/AsteroidsPthreads/src/main.cpp -o CMakeFiles/main.dir/src/main.cpp.s

CMakeFiles/main.dir/src/Ui/Ui.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/Ui/Ui.cpp.o: /home/pedro0210/Projects/AsteroidsPthreads/src/Ui/Ui.cpp
CMakeFiles/main.dir/src/Ui/Ui.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/pedro0210/Projects/AsteroidsPthreads/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/src/Ui/Ui.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/Ui/Ui.cpp.o -MF CMakeFiles/main.dir/src/Ui/Ui.cpp.o.d -o CMakeFiles/main.dir/src/Ui/Ui.cpp.o -c /home/pedro0210/Projects/AsteroidsPthreads/src/Ui/Ui.cpp

CMakeFiles/main.dir/src/Ui/Ui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/Ui/Ui.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pedro0210/Projects/AsteroidsPthreads/src/Ui/Ui.cpp > CMakeFiles/main.dir/src/Ui/Ui.cpp.i

CMakeFiles/main.dir/src/Ui/Ui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/Ui/Ui.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pedro0210/Projects/AsteroidsPthreads/src/Ui/Ui.cpp -o CMakeFiles/main.dir/src/Ui/Ui.cpp.s

CMakeFiles/main.dir/src/GameObjects/MovableObjects/MovableObject.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/GameObjects/MovableObjects/MovableObject.cpp.o: /home/pedro0210/Projects/AsteroidsPthreads/src/GameObjects/MovableObjects/MovableObject.cpp
CMakeFiles/main.dir/src/GameObjects/MovableObjects/MovableObject.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/pedro0210/Projects/AsteroidsPthreads/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/src/GameObjects/MovableObjects/MovableObject.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/GameObjects/MovableObjects/MovableObject.cpp.o -MF CMakeFiles/main.dir/src/GameObjects/MovableObjects/MovableObject.cpp.o.d -o CMakeFiles/main.dir/src/GameObjects/MovableObjects/MovableObject.cpp.o -c /home/pedro0210/Projects/AsteroidsPthreads/src/GameObjects/MovableObjects/MovableObject.cpp

CMakeFiles/main.dir/src/GameObjects/MovableObjects/MovableObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/GameObjects/MovableObjects/MovableObject.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pedro0210/Projects/AsteroidsPthreads/src/GameObjects/MovableObjects/MovableObject.cpp > CMakeFiles/main.dir/src/GameObjects/MovableObjects/MovableObject.cpp.i

CMakeFiles/main.dir/src/GameObjects/MovableObjects/MovableObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/GameObjects/MovableObjects/MovableObject.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pedro0210/Projects/AsteroidsPthreads/src/GameObjects/MovableObjects/MovableObject.cpp -o CMakeFiles/main.dir/src/GameObjects/MovableObjects/MovableObject.cpp.s

CMakeFiles/main.dir/src/GameObjects/MovableObjects/Ship.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/GameObjects/MovableObjects/Ship.cpp.o: /home/pedro0210/Projects/AsteroidsPthreads/src/GameObjects/MovableObjects/Ship.cpp
CMakeFiles/main.dir/src/GameObjects/MovableObjects/Ship.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/pedro0210/Projects/AsteroidsPthreads/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/src/GameObjects/MovableObjects/Ship.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/GameObjects/MovableObjects/Ship.cpp.o -MF CMakeFiles/main.dir/src/GameObjects/MovableObjects/Ship.cpp.o.d -o CMakeFiles/main.dir/src/GameObjects/MovableObjects/Ship.cpp.o -c /home/pedro0210/Projects/AsteroidsPthreads/src/GameObjects/MovableObjects/Ship.cpp

CMakeFiles/main.dir/src/GameObjects/MovableObjects/Ship.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/GameObjects/MovableObjects/Ship.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pedro0210/Projects/AsteroidsPthreads/src/GameObjects/MovableObjects/Ship.cpp > CMakeFiles/main.dir/src/GameObjects/MovableObjects/Ship.cpp.i

CMakeFiles/main.dir/src/GameObjects/MovableObjects/Ship.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/GameObjects/MovableObjects/Ship.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pedro0210/Projects/AsteroidsPthreads/src/GameObjects/MovableObjects/Ship.cpp -o CMakeFiles/main.dir/src/GameObjects/MovableObjects/Ship.cpp.s

CMakeFiles/main.dir/src/Ui/Util/ScreenSettingsInit.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/Ui/Util/ScreenSettingsInit.cpp.o: /home/pedro0210/Projects/AsteroidsPthreads/src/Ui/Util/ScreenSettingsInit.cpp
CMakeFiles/main.dir/src/Ui/Util/ScreenSettingsInit.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/pedro0210/Projects/AsteroidsPthreads/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main.dir/src/Ui/Util/ScreenSettingsInit.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/Ui/Util/ScreenSettingsInit.cpp.o -MF CMakeFiles/main.dir/src/Ui/Util/ScreenSettingsInit.cpp.o.d -o CMakeFiles/main.dir/src/Ui/Util/ScreenSettingsInit.cpp.o -c /home/pedro0210/Projects/AsteroidsPthreads/src/Ui/Util/ScreenSettingsInit.cpp

CMakeFiles/main.dir/src/Ui/Util/ScreenSettingsInit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/Ui/Util/ScreenSettingsInit.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pedro0210/Projects/AsteroidsPthreads/src/Ui/Util/ScreenSettingsInit.cpp > CMakeFiles/main.dir/src/Ui/Util/ScreenSettingsInit.cpp.i

CMakeFiles/main.dir/src/Ui/Util/ScreenSettingsInit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/Ui/Util/ScreenSettingsInit.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pedro0210/Projects/AsteroidsPthreads/src/Ui/Util/ScreenSettingsInit.cpp -o CMakeFiles/main.dir/src/Ui/Util/ScreenSettingsInit.cpp.s

CMakeFiles/main.dir/src/GameObjects/MovableObjects/Projectile.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/GameObjects/MovableObjects/Projectile.cpp.o: /home/pedro0210/Projects/AsteroidsPthreads/src/GameObjects/MovableObjects/Projectile.cpp
CMakeFiles/main.dir/src/GameObjects/MovableObjects/Projectile.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/pedro0210/Projects/AsteroidsPthreads/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/main.dir/src/GameObjects/MovableObjects/Projectile.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/GameObjects/MovableObjects/Projectile.cpp.o -MF CMakeFiles/main.dir/src/GameObjects/MovableObjects/Projectile.cpp.o.d -o CMakeFiles/main.dir/src/GameObjects/MovableObjects/Projectile.cpp.o -c /home/pedro0210/Projects/AsteroidsPthreads/src/GameObjects/MovableObjects/Projectile.cpp

CMakeFiles/main.dir/src/GameObjects/MovableObjects/Projectile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/GameObjects/MovableObjects/Projectile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pedro0210/Projects/AsteroidsPthreads/src/GameObjects/MovableObjects/Projectile.cpp > CMakeFiles/main.dir/src/GameObjects/MovableObjects/Projectile.cpp.i

CMakeFiles/main.dir/src/GameObjects/MovableObjects/Projectile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/GameObjects/MovableObjects/Projectile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pedro0210/Projects/AsteroidsPthreads/src/GameObjects/MovableObjects/Projectile.cpp -o CMakeFiles/main.dir/src/GameObjects/MovableObjects/Projectile.cpp.s

CMakeFiles/main.dir/src/GameObjects/MovableObjects/Asteroids.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/GameObjects/MovableObjects/Asteroids.cpp.o: /home/pedro0210/Projects/AsteroidsPthreads/src/GameObjects/MovableObjects/Asteroids.cpp
CMakeFiles/main.dir/src/GameObjects/MovableObjects/Asteroids.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/pedro0210/Projects/AsteroidsPthreads/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/main.dir/src/GameObjects/MovableObjects/Asteroids.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/GameObjects/MovableObjects/Asteroids.cpp.o -MF CMakeFiles/main.dir/src/GameObjects/MovableObjects/Asteroids.cpp.o.d -o CMakeFiles/main.dir/src/GameObjects/MovableObjects/Asteroids.cpp.o -c /home/pedro0210/Projects/AsteroidsPthreads/src/GameObjects/MovableObjects/Asteroids.cpp

CMakeFiles/main.dir/src/GameObjects/MovableObjects/Asteroids.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/GameObjects/MovableObjects/Asteroids.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pedro0210/Projects/AsteroidsPthreads/src/GameObjects/MovableObjects/Asteroids.cpp > CMakeFiles/main.dir/src/GameObjects/MovableObjects/Asteroids.cpp.i

CMakeFiles/main.dir/src/GameObjects/MovableObjects/Asteroids.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/GameObjects/MovableObjects/Asteroids.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pedro0210/Projects/AsteroidsPthreads/src/GameObjects/MovableObjects/Asteroids.cpp -o CMakeFiles/main.dir/src/GameObjects/MovableObjects/Asteroids.cpp.s

CMakeFiles/main.dir/src/GameManager/GameManager.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/GameManager/GameManager.cpp.o: /home/pedro0210/Projects/AsteroidsPthreads/src/GameManager/GameManager.cpp
CMakeFiles/main.dir/src/GameManager/GameManager.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/pedro0210/Projects/AsteroidsPthreads/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/main.dir/src/GameManager/GameManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/GameManager/GameManager.cpp.o -MF CMakeFiles/main.dir/src/GameManager/GameManager.cpp.o.d -o CMakeFiles/main.dir/src/GameManager/GameManager.cpp.o -c /home/pedro0210/Projects/AsteroidsPthreads/src/GameManager/GameManager.cpp

CMakeFiles/main.dir/src/GameManager/GameManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/GameManager/GameManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pedro0210/Projects/AsteroidsPthreads/src/GameManager/GameManager.cpp > CMakeFiles/main.dir/src/GameManager/GameManager.cpp.i

CMakeFiles/main.dir/src/GameManager/GameManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/GameManager/GameManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pedro0210/Projects/AsteroidsPthreads/src/GameManager/GameManager.cpp -o CMakeFiles/main.dir/src/GameManager/GameManager.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/src/main.cpp.o" \
"CMakeFiles/main.dir/src/Ui/Ui.cpp.o" \
"CMakeFiles/main.dir/src/GameObjects/MovableObjects/MovableObject.cpp.o" \
"CMakeFiles/main.dir/src/GameObjects/MovableObjects/Ship.cpp.o" \
"CMakeFiles/main.dir/src/Ui/Util/ScreenSettingsInit.cpp.o" \
"CMakeFiles/main.dir/src/GameObjects/MovableObjects/Projectile.cpp.o" \
"CMakeFiles/main.dir/src/GameObjects/MovableObjects/Asteroids.cpp.o" \
"CMakeFiles/main.dir/src/GameManager/GameManager.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/src/main.cpp.o
main: CMakeFiles/main.dir/src/Ui/Ui.cpp.o
main: CMakeFiles/main.dir/src/GameObjects/MovableObjects/MovableObject.cpp.o
main: CMakeFiles/main.dir/src/GameObjects/MovableObjects/Ship.cpp.o
main: CMakeFiles/main.dir/src/Ui/Util/ScreenSettingsInit.cpp.o
main: CMakeFiles/main.dir/src/GameObjects/MovableObjects/Projectile.cpp.o
main: CMakeFiles/main.dir/src/GameObjects/MovableObjects/Asteroids.cpp.o
main: CMakeFiles/main.dir/src/GameManager/GameManager.cpp.o
main: CMakeFiles/main.dir/build.make
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/pedro0210/Projects/AsteroidsPthreads/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /home/pedro0210/Projects/AsteroidsPthreads/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pedro0210/Projects/AsteroidsPthreads /home/pedro0210/Projects/AsteroidsPthreads /home/pedro0210/Projects/AsteroidsPthreads/build /home/pedro0210/Projects/AsteroidsPthreads/build /home/pedro0210/Projects/AsteroidsPthreads/build/CMakeFiles/main.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/main.dir/depend

