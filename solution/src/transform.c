// solution/src/transform.c

#include "image.h"
//функция поворота изображения
struct image rotate(const struct image source) {
    struct image rotated_image = create_image(source.height, source.width);

    for (uint64_t i = 0; i < source.height; i++) {
        for (uint64_t j = 0; j < source.width; j++) {
            //поворот
            rotated_image.data[j * rotated_image.width + (source.height - i - 1)] = source.data[i * source.width + j];
        }
    }

    return rotated_image;
}
