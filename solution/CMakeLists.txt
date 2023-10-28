cmake_minimum_required(VERSION 3.10)
project(image-transformer)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(image-transformer
        src/main.c
        src/bmp.c
        src/transform.c
        src/io.c
        src/image.c
        include/bmp.h
        include/transform.h
        include/io.h
)