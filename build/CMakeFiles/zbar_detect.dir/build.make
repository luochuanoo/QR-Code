# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/local/lib/python3.6/dist-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /usr/local/lib/python3.6/dist-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sdu829/LuoC/QR-Code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sdu829/LuoC/QR-Code/build

# Include any dependencies generated for this target.
include CMakeFiles/zbar_detect.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/zbar_detect.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zbar_detect.dir/flags.make

CMakeFiles/zbar_detect.dir/zbar_detect.cpp.o: CMakeFiles/zbar_detect.dir/flags.make
CMakeFiles/zbar_detect.dir/zbar_detect.cpp.o: ../zbar_detect.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sdu829/LuoC/QR-Code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/zbar_detect.dir/zbar_detect.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zbar_detect.dir/zbar_detect.cpp.o -c /home/sdu829/LuoC/QR-Code/zbar_detect.cpp

CMakeFiles/zbar_detect.dir/zbar_detect.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zbar_detect.dir/zbar_detect.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sdu829/LuoC/QR-Code/zbar_detect.cpp > CMakeFiles/zbar_detect.dir/zbar_detect.cpp.i

CMakeFiles/zbar_detect.dir/zbar_detect.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zbar_detect.dir/zbar_detect.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sdu829/LuoC/QR-Code/zbar_detect.cpp -o CMakeFiles/zbar_detect.dir/zbar_detect.cpp.s

# Object files for target zbar_detect
zbar_detect_OBJECTS = \
"CMakeFiles/zbar_detect.dir/zbar_detect.cpp.o"

# External object files for target zbar_detect
zbar_detect_EXTERNAL_OBJECTS =

../bin/zbar_detect: CMakeFiles/zbar_detect.dir/zbar_detect.cpp.o
../bin/zbar_detect: CMakeFiles/zbar_detect.dir/build.make
../bin/zbar_detect: ../lib/libQR_Code.so
../bin/zbar_detect: /usr/local/lib/libopencv_dnn.so.3.4.5
../bin/zbar_detect: /usr/local/lib/libopencv_ml.so.3.4.5
../bin/zbar_detect: /usr/local/lib/libopencv_objdetect.so.3.4.5
../bin/zbar_detect: /usr/local/lib/libopencv_shape.so.3.4.5
../bin/zbar_detect: /usr/local/lib/libopencv_stitching.so.3.4.5
../bin/zbar_detect: /usr/local/lib/libopencv_superres.so.3.4.5
../bin/zbar_detect: /usr/local/lib/libopencv_videostab.so.3.4.5
../bin/zbar_detect: /usr/local/lib/libopencv_calib3d.so.3.4.5
../bin/zbar_detect: /usr/local/lib/libopencv_features2d.so.3.4.5
../bin/zbar_detect: /usr/local/lib/libopencv_flann.so.3.4.5
../bin/zbar_detect: /usr/local/lib/libopencv_highgui.so.3.4.5
../bin/zbar_detect: /usr/local/lib/libopencv_photo.so.3.4.5
../bin/zbar_detect: /usr/local/lib/libopencv_video.so.3.4.5
../bin/zbar_detect: /usr/local/lib/libopencv_videoio.so.3.4.5
../bin/zbar_detect: /usr/local/lib/libopencv_imgcodecs.so.3.4.5
../bin/zbar_detect: /usr/local/lib/libopencv_imgproc.so.3.4.5
../bin/zbar_detect: /usr/local/lib/libopencv_core.so.3.4.5
../bin/zbar_detect: CMakeFiles/zbar_detect.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sdu829/LuoC/QR-Code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/zbar_detect"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zbar_detect.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zbar_detect.dir/build: ../bin/zbar_detect

.PHONY : CMakeFiles/zbar_detect.dir/build

CMakeFiles/zbar_detect.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/zbar_detect.dir/cmake_clean.cmake
.PHONY : CMakeFiles/zbar_detect.dir/clean

CMakeFiles/zbar_detect.dir/depend:
	cd /home/sdu829/LuoC/QR-Code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sdu829/LuoC/QR-Code /home/sdu829/LuoC/QR-Code /home/sdu829/LuoC/QR-Code/build /home/sdu829/LuoC/QR-Code/build /home/sdu829/LuoC/QR-Code/build/CMakeFiles/zbar_detect.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zbar_detect.dir/depend

