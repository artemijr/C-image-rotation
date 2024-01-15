// solution/include/image.h
#ifndef IMAGE_H
#define IMAGE_H

#include <stdint.h>

//структура пикселя red (r), green (g), and blue (b)
struct pixel {
    uint8_t r, g, b;
};

//структура image
struct image {
    uint64_t width, height;
    struct pixel* data;
};

//статусы чтения
enum read_status {
    READ_OK = 0,
    READ_INVALID_SIGNATURE,
    READ_INVALID_BITS,
    READ_INVALID_HEADER
};

//статусы записи
enum write_status {
    WRITE_OK = 0,
    WRITE_ERROR
};

const struct image create_image(uint64_t width, uint64_t height);//функция создания image

void destroy_image(struct image* img);//функция освобождения памяти

#endif
