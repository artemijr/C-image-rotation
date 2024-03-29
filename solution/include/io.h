// solution/include/io.h

#ifndef IO_H
#define IO_H

#include "bmp.h"
#include "image.h"


struct image load_image(const char* filename);//функция загрузки .bmp в структуру image
void save_image(const struct image* img, const char* filename);//превращаем структуру image в .bmp

#endif
