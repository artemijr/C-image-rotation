# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.26
cmake_policy(SET CMP0009 NEW)

# test_directories at CMakeLists.txt:10 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "C:/CProjects/my/assignment-image-rotation/tester/tests/*")
set(OLD_GLOB
  "C:/CProjects/my/assignment-image-rotation/tester/tests/.gitignore"
  "C:/CProjects/my/assignment-image-rotation/tester/tests/1"
  "C:/CProjects/my/assignment-image-rotation/tester/tests/2"
  "C:/CProjects/my/assignment-image-rotation/tester/tests/3"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "C:/CProjects/my/assignment-image-rotation/tester/out/build/lsan/CMakeFiles/cmake.verify_globs")
endif()

# sources at CMakeLists.txt:1 (file)
file(GLOB_RECURSE NEW_GLOB FOLLOW_SYMLINKS LIST_DIRECTORIES false "C:/CProjects/my/assignment-image-rotation/tester/include/*.h")
set(OLD_GLOB
  "C:/CProjects/my/assignment-image-rotation/tester/include/bmp.h"
  "C:/CProjects/my/assignment-image-rotation/tester/include/cmp.h"
  "C:/CProjects/my/assignment-image-rotation/tester/include/common.h"
  "C:/CProjects/my/assignment-image-rotation/tester/include/dimensions.h"
  "C:/CProjects/my/assignment-image-rotation/tester/include/file_cmp.h"
  "C:/CProjects/my/assignment-image-rotation/tester/include/image.h"
  "C:/CProjects/my/assignment-image-rotation/tester/include/io.h"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "C:/CProjects/my/assignment-image-rotation/tester/out/build/lsan/CMakeFiles/cmake.verify_globs")
endif()

# sources at CMakeLists.txt:1 (file)
file(GLOB_RECURSE NEW_GLOB FOLLOW_SYMLINKS LIST_DIRECTORIES false "C:/CProjects/my/assignment-image-rotation/tester/src/*.c")
set(OLD_GLOB
  "C:/CProjects/my/assignment-image-rotation/tester/src/bmp.c"
  "C:/CProjects/my/assignment-image-rotation/tester/src/file_cmp.c"
  "C:/CProjects/my/assignment-image-rotation/tester/src/main.c"
  "C:/CProjects/my/assignment-image-rotation/tester/src/util.c"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "C:/CProjects/my/assignment-image-rotation/tester/out/build/lsan/CMakeFiles/cmake.verify_globs")
endif()

# sources at CMakeLists.txt:1 (file)
file(GLOB_RECURSE NEW_GLOB FOLLOW_SYMLINKS LIST_DIRECTORIES false "C:/CProjects/my/assignment-image-rotation/tester/src/*.h")
set(OLD_GLOB
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "C:/CProjects/my/assignment-image-rotation/tester/out/build/lsan/CMakeFiles/cmake.verify_globs")
endif()
