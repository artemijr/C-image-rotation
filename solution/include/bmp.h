// solution/include/bmp.h

#ifndef BMP_H
#define BMP_H

#include <stdio.h>

#include "image.h"


enum read_status from_bmp(FILE* in, struct image* img);//функция конвертации .bmp в структуру image
enum write_status to_bmp(FILE* out, const struct image* img);//функция конвертации структуры image в .bmp

#endif
