# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/nir/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5457.51/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/nir/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5457.51/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nir/CLionProjects/spl0101

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nir/CLionProjects/spl0101/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/untitled.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/untitled.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled.dir/flags.make

CMakeFiles/untitled.dir/src/main.cpp.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nir/CLionProjects/spl0101/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/untitled.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled.dir/src/main.cpp.o -c /home/nir/CLionProjects/spl0101/src/main.cpp

CMakeFiles/untitled.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nir/CLionProjects/spl0101/src/main.cpp > CMakeFiles/untitled.dir/src/main.cpp.i

CMakeFiles/untitled.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nir/CLionProjects/spl0101/src/main.cpp -o CMakeFiles/untitled.dir/src/main.cpp.s

CMakeFiles/untitled.dir/src/Workout.cpp.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/src/Workout.cpp.o: ../src/Workout.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nir/CLionProjects/spl0101/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/untitled.dir/src/Workout.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled.dir/src/Workout.cpp.o -c /home/nir/CLionProjects/spl0101/src/Workout.cpp

CMakeFiles/untitled.dir/src/Workout.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled.dir/src/Workout.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nir/CLionProjects/spl0101/src/Workout.cpp > CMakeFiles/untitled.dir/src/Workout.cpp.i

CMakeFiles/untitled.dir/src/Workout.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled.dir/src/Workout.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nir/CLionProjects/spl0101/src/Workout.cpp -o CMakeFiles/untitled.dir/src/Workout.cpp.s

CMakeFiles/untitled.dir/src/SweatyCustomer.cpp.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/src/SweatyCustomer.cpp.o: ../src/SweatyCustomer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nir/CLionProjects/spl0101/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/untitled.dir/src/SweatyCustomer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled.dir/src/SweatyCustomer.cpp.o -c /home/nir/CLionProjects/spl0101/src/SweatyCustomer.cpp

CMakeFiles/untitled.dir/src/SweatyCustomer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled.dir/src/SweatyCustomer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nir/CLionProjects/spl0101/src/SweatyCustomer.cpp > CMakeFiles/untitled.dir/src/SweatyCustomer.cpp.i

CMakeFiles/untitled.dir/src/SweatyCustomer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled.dir/src/SweatyCustomer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nir/CLionProjects/spl0101/src/SweatyCustomer.cpp -o CMakeFiles/untitled.dir/src/SweatyCustomer.cpp.s

CMakeFiles/untitled.dir/src/CheapCustomer.cpp.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/src/CheapCustomer.cpp.o: ../src/CheapCustomer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nir/CLionProjects/spl0101/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/untitled.dir/src/CheapCustomer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled.dir/src/CheapCustomer.cpp.o -c /home/nir/CLionProjects/spl0101/src/CheapCustomer.cpp

CMakeFiles/untitled.dir/src/CheapCustomer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled.dir/src/CheapCustomer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nir/CLionProjects/spl0101/src/CheapCustomer.cpp > CMakeFiles/untitled.dir/src/CheapCustomer.cpp.i

CMakeFiles/untitled.dir/src/CheapCustomer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled.dir/src/CheapCustomer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nir/CLionProjects/spl0101/src/CheapCustomer.cpp -o CMakeFiles/untitled.dir/src/CheapCustomer.cpp.s

CMakeFiles/untitled.dir/src/HeavyMuscleCustomer.cpp.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/src/HeavyMuscleCustomer.cpp.o: ../src/HeavyMuscleCustomer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nir/CLionProjects/spl0101/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/untitled.dir/src/HeavyMuscleCustomer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled.dir/src/HeavyMuscleCustomer.cpp.o -c /home/nir/CLionProjects/spl0101/src/HeavyMuscleCustomer.cpp

CMakeFiles/untitled.dir/src/HeavyMuscleCustomer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled.dir/src/HeavyMuscleCustomer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nir/CLionProjects/spl0101/src/HeavyMuscleCustomer.cpp > CMakeFiles/untitled.dir/src/HeavyMuscleCustomer.cpp.i

CMakeFiles/untitled.dir/src/HeavyMuscleCustomer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled.dir/src/HeavyMuscleCustomer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nir/CLionProjects/spl0101/src/HeavyMuscleCustomer.cpp -o CMakeFiles/untitled.dir/src/HeavyMuscleCustomer.cpp.s

CMakeFiles/untitled.dir/src/FullBodyCustomer.cpp.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/src/FullBodyCustomer.cpp.o: ../src/FullBodyCustomer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nir/CLionProjects/spl0101/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/untitled.dir/src/FullBodyCustomer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled.dir/src/FullBodyCustomer.cpp.o -c /home/nir/CLionProjects/spl0101/src/FullBodyCustomer.cpp

CMakeFiles/untitled.dir/src/FullBodyCustomer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled.dir/src/FullBodyCustomer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nir/CLionProjects/spl0101/src/FullBodyCustomer.cpp > CMakeFiles/untitled.dir/src/FullBodyCustomer.cpp.i

CMakeFiles/untitled.dir/src/FullBodyCustomer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled.dir/src/FullBodyCustomer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nir/CLionProjects/spl0101/src/FullBodyCustomer.cpp -o CMakeFiles/untitled.dir/src/FullBodyCustomer.cpp.s

CMakeFiles/untitled.dir/src/QuickSort.cpp.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/src/QuickSort.cpp.o: ../src/QuickSort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nir/CLionProjects/spl0101/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/untitled.dir/src/QuickSort.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled.dir/src/QuickSort.cpp.o -c /home/nir/CLionProjects/spl0101/src/QuickSort.cpp

CMakeFiles/untitled.dir/src/QuickSort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled.dir/src/QuickSort.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nir/CLionProjects/spl0101/src/QuickSort.cpp > CMakeFiles/untitled.dir/src/QuickSort.cpp.i

CMakeFiles/untitled.dir/src/QuickSort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled.dir/src/QuickSort.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nir/CLionProjects/spl0101/src/QuickSort.cpp -o CMakeFiles/untitled.dir/src/QuickSort.cpp.s

# Object files for target untitled
untitled_OBJECTS = \
"CMakeFiles/untitled.dir/src/main.cpp.o" \
"CMakeFiles/untitled.dir/src/Workout.cpp.o" \
"CMakeFiles/untitled.dir/src/SweatyCustomer.cpp.o" \
"CMakeFiles/untitled.dir/src/CheapCustomer.cpp.o" \
"CMakeFiles/untitled.dir/src/HeavyMuscleCustomer.cpp.o" \
"CMakeFiles/untitled.dir/src/FullBodyCustomer.cpp.o" \
"CMakeFiles/untitled.dir/src/QuickSort.cpp.o"

# External object files for target untitled
untitled_EXTERNAL_OBJECTS =

untitled: CMakeFiles/untitled.dir/src/main.cpp.o
untitled: CMakeFiles/untitled.dir/src/Workout.cpp.o
untitled: CMakeFiles/untitled.dir/src/SweatyCustomer.cpp.o
untitled: CMakeFiles/untitled.dir/src/CheapCustomer.cpp.o
untitled: CMakeFiles/untitled.dir/src/HeavyMuscleCustomer.cpp.o
untitled: CMakeFiles/untitled.dir/src/FullBodyCustomer.cpp.o
untitled: CMakeFiles/untitled.dir/src/QuickSort.cpp.o
untitled: CMakeFiles/untitled.dir/build.make
untitled: CMakeFiles/untitled.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nir/CLionProjects/spl0101/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable untitled"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/untitled.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled.dir/build: untitled
.PHONY : CMakeFiles/untitled.dir/build

CMakeFiles/untitled.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/untitled.dir/cmake_clean.cmake
.PHONY : CMakeFiles/untitled.dir/clean

CMakeFiles/untitled.dir/depend:
	cd /home/nir/CLionProjects/spl0101/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nir/CLionProjects/spl0101 /home/nir/CLionProjects/spl0101 /home/nir/CLionProjects/spl0101/cmake-build-debug /home/nir/CLionProjects/spl0101/cmake-build-debug /home/nir/CLionProjects/spl0101/cmake-build-debug/CMakeFiles/untitled.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/untitled.dir/depend

