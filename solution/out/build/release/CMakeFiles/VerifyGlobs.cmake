# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.26
cmake_policy(SET CMP0009 NEW)

# test_directories at tester/CMakeLists.txt:10 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "C:/CProjects/assignment-image-rotation1/tester/tests/*")
set(OLD_GLOB
  "C:/CProjects/assignment-image-rotation1/tester/tests/.gitignore"
  "C:/CProjects/assignment-image-rotation1/tester/tests/1"
  "C:/CProjects/assignment-image-rotation1/tester/tests/2"
  "C:/CProjects/assignment-image-rotation1/tester/tests/3"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "C:/CProjects/assignment-image-rotation1/out/build/release/CMakeFiles/cmake.verify_globs")
endif()

# sources at tester/CMakeLists.txt:1 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "C:/CProjects/assignment-image-rotation1/tester/include/*.h")
set(OLD_GLOB
  "C:/CProjects/assignment-image-rotation1/tester/include/bmp.h"
  "C:/CProjects/assignment-image-rotation1/tester/include/cmp.h"
  "C:/CProjects/assignment-image-rotation1/tester/include/common.h"
  "C:/CProjects/assignment-image-rotation1/tester/include/dimensions.h"
  "C:/CProjects/assignment-image-rotation1/tester/include/file_cmp.h"
  "C:/CProjects/assignment-image-rotation1/tester/include/image.h"
  "C:/CProjects/assignment-image-rotation1/tester/include/io.h"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "C:/CProjects/assignment-image-rotation1/out/build/release/CMakeFiles/cmake.verify_globs")
endif()

# sources at tester/CMakeLists.txt:1 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "C:/CProjects/assignment-image-rotation1/tester/src/*.c")
set(OLD_GLOB
  "C:/CProjects/assignment-image-rotation1/tester/src/bmp.c"
  "C:/CProjects/assignment-image-rotation1/tester/src/file_cmp.c"
  "C:/CProjects/assignment-image-rotation1/tester/src/main.c"
  "C:/CProjects/assignment-image-rotation1/tester/src/util.c"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "C:/CProjects/assignment-image-rotation1/out/build/release/CMakeFiles/cmake.verify_globs")
endif()

# sources at tester/CMakeLists.txt:1 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "C:/CProjects/assignment-image-rotation1/tester/src/*.h")
set(OLD_GLOB
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "C:/CProjects/assignment-image-rotation1/out/build/release/CMakeFiles/cmake.verify_globs")
endif()
