// solution/src/image.c

#include "image.h"
#include <stdlib.h>

//функция создания image
struct image create_image(uint64_t width, uint64_t height) {
    struct image img;
    img.width = width;//ширина в пикселях
    img.height = height;//высота в пикселях
    img.data = (struct pixel*)malloc(sizeof(struct pixel) * width * height);//массив из пикселей изображения
    return img;
}

//функция освобождения памяти
void destroy_image(struct image* img) {
    if (img->data) {
        free(img->data);
        img->data = NULL;
    }
}
