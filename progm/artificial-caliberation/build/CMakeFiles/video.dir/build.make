# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jitender/progm/caliberation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jitender/progm/caliberation/build

# Include any dependencies generated for this target.
include CMakeFiles/video.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/video.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/video.dir/flags.make

CMakeFiles/video.dir/calibration_artificial.cpp.o: CMakeFiles/video.dir/flags.make
CMakeFiles/video.dir/calibration_artificial.cpp.o: ../calibration_artificial.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jitender/progm/caliberation/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/video.dir/calibration_artificial.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/video.dir/calibration_artificial.cpp.o -c /home/jitender/progm/caliberation/calibration_artificial.cpp

CMakeFiles/video.dir/calibration_artificial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/video.dir/calibration_artificial.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jitender/progm/caliberation/calibration_artificial.cpp > CMakeFiles/video.dir/calibration_artificial.cpp.i

CMakeFiles/video.dir/calibration_artificial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/video.dir/calibration_artificial.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jitender/progm/caliberation/calibration_artificial.cpp -o CMakeFiles/video.dir/calibration_artificial.cpp.s

CMakeFiles/video.dir/calibration_artificial.cpp.o.requires:
.PHONY : CMakeFiles/video.dir/calibration_artificial.cpp.o.requires

CMakeFiles/video.dir/calibration_artificial.cpp.o.provides: CMakeFiles/video.dir/calibration_artificial.cpp.o.requires
	$(MAKE) -f CMakeFiles/video.dir/build.make CMakeFiles/video.dir/calibration_artificial.cpp.o.provides.build
.PHONY : CMakeFiles/video.dir/calibration_artificial.cpp.o.provides

CMakeFiles/video.dir/calibration_artificial.cpp.o.provides.build: CMakeFiles/video.dir/calibration_artificial.cpp.o

# Object files for target video
video_OBJECTS = \
"CMakeFiles/video.dir/calibration_artificial.cpp.o"

# External object files for target video
video_EXTERNAL_OBJECTS =

video: CMakeFiles/video.dir/calibration_artificial.cpp.o
video: /usr/local/lib/libopencv_videostab.so.2.4.9
video: /usr/local/lib/libopencv_video.so.2.4.9
video: /usr/local/lib/libopencv_ts.a
video: /usr/local/lib/libopencv_superres.so.2.4.9
video: /usr/local/lib/libopencv_stitching.so.2.4.9
video: /usr/local/lib/libopencv_photo.so.2.4.9
video: /usr/local/lib/libopencv_ocl.so.2.4.9
video: /usr/local/lib/libopencv_objdetect.so.2.4.9
video: /usr/local/lib/libopencv_nonfree.so.2.4.9
video: /usr/local/lib/libopencv_ml.so.2.4.9
video: /usr/local/lib/libopencv_legacy.so.2.4.9
video: /usr/local/lib/libopencv_imgproc.so.2.4.9
video: /usr/local/lib/libopencv_highgui.so.2.4.9
video: /usr/local/lib/libopencv_gpu.so.2.4.9
video: /usr/local/lib/libopencv_flann.so.2.4.9
video: /usr/local/lib/libopencv_features2d.so.2.4.9
video: /usr/local/lib/libopencv_core.so.2.4.9
video: /usr/local/lib/libopencv_contrib.so.2.4.9
video: /usr/local/lib/libopencv_calib3d.so.2.4.9
video: /usr/lib/i386-linux-gnu/libGLU.so
video: /usr/lib/i386-linux-gnu/libGL.so
video: /usr/lib/i386-linux-gnu/libSM.so
video: /usr/lib/i386-linux-gnu/libICE.so
video: /usr/lib/i386-linux-gnu/libX11.so
video: /usr/lib/i386-linux-gnu/libXext.so
video: /usr/local/lib/libopencv_nonfree.so.2.4.9
video: /usr/local/lib/libopencv_ocl.so.2.4.9
video: /usr/local/lib/libopencv_gpu.so.2.4.9
video: /usr/local/lib/libopencv_photo.so.2.4.9
video: /usr/local/lib/libopencv_objdetect.so.2.4.9
video: /usr/local/lib/libopencv_legacy.so.2.4.9
video: /usr/local/lib/libopencv_video.so.2.4.9
video: /usr/local/lib/libopencv_ml.so.2.4.9
video: /usr/local/lib/libopencv_calib3d.so.2.4.9
video: /usr/local/lib/libopencv_features2d.so.2.4.9
video: /usr/local/lib/libopencv_highgui.so.2.4.9
video: /usr/local/lib/libopencv_imgproc.so.2.4.9
video: /usr/local/lib/libopencv_flann.so.2.4.9
video: /usr/local/lib/libopencv_core.so.2.4.9
video: CMakeFiles/video.dir/build.make
video: CMakeFiles/video.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable video"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/video.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/video.dir/build: video
.PHONY : CMakeFiles/video.dir/build

CMakeFiles/video.dir/requires: CMakeFiles/video.dir/calibration_artificial.cpp.o.requires
.PHONY : CMakeFiles/video.dir/requires

CMakeFiles/video.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/video.dir/cmake_clean.cmake
.PHONY : CMakeFiles/video.dir/clean

CMakeFiles/video.dir/depend:
	cd /home/jitender/progm/caliberation/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jitender/progm/caliberation /home/jitender/progm/caliberation /home/jitender/progm/caliberation/build /home/jitender/progm/caliberation/build /home/jitender/progm/caliberation/build/CMakeFiles/video.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/video.dir/depend

