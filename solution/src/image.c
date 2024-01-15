// solution/src/image.c

#include "image.h"
#include <stdlib.h>
#include <stdio.h>

//функция создания image
struct image create_image(uint64_t width, uint64_t height) {
    struct image img;
    img.width = width;
    img.height = height;
    img.data = (struct pixel*)malloc(sizeof(struct pixel) * width * height);

    if (!img.data) {
        fprintf(stderr, "Failed to allocate memory for image data\n");
        // Обработка ошибки
        img.width = 0;
        img.height = 0;
        return img;
    }

    return img;
}



//функция освобождения памяти
void destroy_image(struct image* img) {
    if (img->data) {
        free(img->data);
        img->data = NULL;
    }
}
