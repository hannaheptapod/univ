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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.20.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.20.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jink/Desktop/Programme/C++/ohya-lab3/0531

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jink/Desktop/Programme/C++/ohya-lab3/0531/0531ex5

# Include any dependencies generated for this target.
include CMakeFiles/main.out.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.out.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.out.dir/flags.make

CMakeFiles/main.out.dir/main.cpp.o: CMakeFiles/main.out.dir/flags.make
CMakeFiles/main.out.dir/main.cpp.o: main.cpp
CMakeFiles/main.out.dir/main.cpp.o: CMakeFiles/main.out.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jink/Desktop/Programme/C++/ohya-lab3/0531/0531ex5/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.out.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.out.dir/main.cpp.o -MF CMakeFiles/main.out.dir/main.cpp.o.d -o CMakeFiles/main.out.dir/main.cpp.o -c /Users/jink/Desktop/Programme/C++/ohya-lab3/0531/0531ex5/main.cpp

CMakeFiles/main.out.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.out.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jink/Desktop/Programme/C++/ohya-lab3/0531/0531ex5/main.cpp > CMakeFiles/main.out.dir/main.cpp.i

CMakeFiles/main.out.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.out.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jink/Desktop/Programme/C++/ohya-lab3/0531/0531ex5/main.cpp -o CMakeFiles/main.out.dir/main.cpp.s

# Object files for target main.out
main_out_OBJECTS = \
"CMakeFiles/main.out.dir/main.cpp.o"

# External object files for target main.out
main_out_EXTERNAL_OBJECTS =

main.out: CMakeFiles/main.out.dir/main.cpp.o
main.out: CMakeFiles/main.out.dir/build.make
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_gapi.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_stitching.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_alphamat.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_aruco.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_bgsegm.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_bioinspired.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_ccalib.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_dnn_objdetect.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_dnn_superres.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_dpm.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_face.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_freetype.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_fuzzy.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_hfs.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_img_hash.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_intensity_transform.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_line_descriptor.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_mcc.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_quality.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_rapid.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_reg.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_rgbd.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_saliency.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_stereo.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_structured_light.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_superres.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_surface_matching.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_tracking.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_videostab.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_xfeatures2d.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_xobjdetect.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_xphoto.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_shape.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_highgui.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_datasets.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_plot.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_text.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_ml.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_phase_unwrapping.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_optflow.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_ximgproc.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_video.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_dnn.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_videoio.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_imgcodecs.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_objdetect.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_calib3d.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_features2d.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_flann.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_photo.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_imgproc.4.5.1.dylib
main.out: /opt/homebrew/Caskroom/miniforge/base/lib/libopencv_core.4.5.1.dylib
main.out: CMakeFiles/main.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jink/Desktop/Programme/C++/ohya-lab3/0531/0531ex5/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable main.out"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.out.dir/build: main.out
.PHONY : CMakeFiles/main.out.dir/build

CMakeFiles/main.out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.out.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.out.dir/clean

CMakeFiles/main.out.dir/depend:
	cd /Users/jink/Desktop/Programme/C++/ohya-lab3/0531/0531ex5 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jink/Desktop/Programme/C++/ohya-lab3/0531 /Users/jink/Desktop/Programme/C++/ohya-lab3/0531 /Users/jink/Desktop/Programme/C++/ohya-lab3/0531/0531ex5 /Users/jink/Desktop/Programme/C++/ohya-lab3/0531/0531ex5 /Users/jink/Desktop/Programme/C++/ohya-lab3/0531/0531ex5/CMakeFiles/main.out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.out.dir/depend

