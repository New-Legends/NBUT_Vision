# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/davi/rmVison4.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/davi/rmVison4.0/build

# Include any dependencies generated for this target.
include CMakeFiles/TEST.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TEST.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TEST.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TEST.dir/flags.make

CMakeFiles/TEST.dir/main.cpp.o: CMakeFiles/TEST.dir/flags.make
CMakeFiles/TEST.dir/main.cpp.o: ../main.cpp
CMakeFiles/TEST.dir/main.cpp.o: CMakeFiles/TEST.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/davi/rmVison4.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TEST.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TEST.dir/main.cpp.o -MF CMakeFiles/TEST.dir/main.cpp.o.d -o CMakeFiles/TEST.dir/main.cpp.o -c /home/davi/rmVison4.0/main.cpp

CMakeFiles/TEST.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TEST.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/davi/rmVison4.0/main.cpp > CMakeFiles/TEST.dir/main.cpp.i

CMakeFiles/TEST.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TEST.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/davi/rmVison4.0/main.cpp -o CMakeFiles/TEST.dir/main.cpp.s

CMakeFiles/TEST.dir/src/ArmorCenter/ArmorCenter.cpp.o: CMakeFiles/TEST.dir/flags.make
CMakeFiles/TEST.dir/src/ArmorCenter/ArmorCenter.cpp.o: ../src/ArmorCenter/ArmorCenter.cpp
CMakeFiles/TEST.dir/src/ArmorCenter/ArmorCenter.cpp.o: CMakeFiles/TEST.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/davi/rmVison4.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TEST.dir/src/ArmorCenter/ArmorCenter.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TEST.dir/src/ArmorCenter/ArmorCenter.cpp.o -MF CMakeFiles/TEST.dir/src/ArmorCenter/ArmorCenter.cpp.o.d -o CMakeFiles/TEST.dir/src/ArmorCenter/ArmorCenter.cpp.o -c /home/davi/rmVison4.0/src/ArmorCenter/ArmorCenter.cpp

CMakeFiles/TEST.dir/src/ArmorCenter/ArmorCenter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TEST.dir/src/ArmorCenter/ArmorCenter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/davi/rmVison4.0/src/ArmorCenter/ArmorCenter.cpp > CMakeFiles/TEST.dir/src/ArmorCenter/ArmorCenter.cpp.i

CMakeFiles/TEST.dir/src/ArmorCenter/ArmorCenter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TEST.dir/src/ArmorCenter/ArmorCenter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/davi/rmVison4.0/src/ArmorCenter/ArmorCenter.cpp -o CMakeFiles/TEST.dir/src/ArmorCenter/ArmorCenter.cpp.s

CMakeFiles/TEST.dir/src/ArmorCenter/AngleSolve.cpp.o: CMakeFiles/TEST.dir/flags.make
CMakeFiles/TEST.dir/src/ArmorCenter/AngleSolve.cpp.o: ../src/ArmorCenter/AngleSolve.cpp
CMakeFiles/TEST.dir/src/ArmorCenter/AngleSolve.cpp.o: CMakeFiles/TEST.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/davi/rmVison4.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TEST.dir/src/ArmorCenter/AngleSolve.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TEST.dir/src/ArmorCenter/AngleSolve.cpp.o -MF CMakeFiles/TEST.dir/src/ArmorCenter/AngleSolve.cpp.o.d -o CMakeFiles/TEST.dir/src/ArmorCenter/AngleSolve.cpp.o -c /home/davi/rmVison4.0/src/ArmorCenter/AngleSolve.cpp

CMakeFiles/TEST.dir/src/ArmorCenter/AngleSolve.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TEST.dir/src/ArmorCenter/AngleSolve.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/davi/rmVison4.0/src/ArmorCenter/AngleSolve.cpp > CMakeFiles/TEST.dir/src/ArmorCenter/AngleSolve.cpp.i

CMakeFiles/TEST.dir/src/ArmorCenter/AngleSolve.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TEST.dir/src/ArmorCenter/AngleSolve.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/davi/rmVison4.0/src/ArmorCenter/AngleSolve.cpp -o CMakeFiles/TEST.dir/src/ArmorCenter/AngleSolve.cpp.s

CMakeFiles/TEST.dir/src/KF/kalman.cpp.o: CMakeFiles/TEST.dir/flags.make
CMakeFiles/TEST.dir/src/KF/kalman.cpp.o: ../src/KF/kalman.cpp
CMakeFiles/TEST.dir/src/KF/kalman.cpp.o: CMakeFiles/TEST.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/davi/rmVison4.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TEST.dir/src/KF/kalman.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TEST.dir/src/KF/kalman.cpp.o -MF CMakeFiles/TEST.dir/src/KF/kalman.cpp.o.d -o CMakeFiles/TEST.dir/src/KF/kalman.cpp.o -c /home/davi/rmVison4.0/src/KF/kalman.cpp

CMakeFiles/TEST.dir/src/KF/kalman.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TEST.dir/src/KF/kalman.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/davi/rmVison4.0/src/KF/kalman.cpp > CMakeFiles/TEST.dir/src/KF/kalman.cpp.i

CMakeFiles/TEST.dir/src/KF/kalman.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TEST.dir/src/KF/kalman.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/davi/rmVison4.0/src/KF/kalman.cpp -o CMakeFiles/TEST.dir/src/KF/kalman.cpp.s

# Object files for target TEST
TEST_OBJECTS = \
"CMakeFiles/TEST.dir/main.cpp.o" \
"CMakeFiles/TEST.dir/src/ArmorCenter/ArmorCenter.cpp.o" \
"CMakeFiles/TEST.dir/src/ArmorCenter/AngleSolve.cpp.o" \
"CMakeFiles/TEST.dir/src/KF/kalman.cpp.o"

# External object files for target TEST
TEST_EXTERNAL_OBJECTS =

TEST: CMakeFiles/TEST.dir/main.cpp.o
TEST: CMakeFiles/TEST.dir/src/ArmorCenter/ArmorCenter.cpp.o
TEST: CMakeFiles/TEST.dir/src/ArmorCenter/AngleSolve.cpp.o
TEST: CMakeFiles/TEST.dir/src/KF/kalman.cpp.o
TEST: CMakeFiles/TEST.dir/build.make
TEST: /usr/lib/x86_64-linux-gnu/libjsoncpp.so.1.9.5
TEST: /usr/local/lib/libopencv_gapi.so.4.6.0
TEST: /usr/local/lib/libopencv_highgui.so.4.6.0
TEST: /usr/local/lib/libopencv_ml.so.4.6.0
TEST: /usr/local/lib/libopencv_objdetect.so.4.6.0
TEST: /usr/local/lib/libopencv_photo.so.4.6.0
TEST: /usr/local/lib/libopencv_stitching.so.4.6.0
TEST: /usr/local/lib/libopencv_video.so.4.6.0
TEST: /usr/local/lib/libopencv_videoio.so.4.6.0
TEST: /usr/lib/x86_64-linux-gnu/libpython3.10.so
TEST: /usr/local/lib/libopencv_imgcodecs.so.4.6.0
TEST: /usr/local/lib/libopencv_dnn.so.4.6.0
TEST: /usr/local/lib/libopencv_calib3d.so.4.6.0
TEST: /usr/local/lib/libopencv_features2d.so.4.6.0
TEST: /usr/local/lib/libopencv_flann.so.4.6.0
TEST: /usr/local/lib/libopencv_imgproc.so.4.6.0
TEST: /usr/local/lib/libopencv_core.so.4.6.0
TEST: CMakeFiles/TEST.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/davi/rmVison4.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable TEST"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TEST.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TEST.dir/build: TEST
.PHONY : CMakeFiles/TEST.dir/build

CMakeFiles/TEST.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TEST.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TEST.dir/clean

CMakeFiles/TEST.dir/depend:
	cd /home/davi/rmVison4.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/davi/rmVison4.0 /home/davi/rmVison4.0 /home/davi/rmVison4.0/build /home/davi/rmVison4.0/build /home/davi/rmVison4.0/build/CMakeFiles/TEST.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TEST.dir/depend

