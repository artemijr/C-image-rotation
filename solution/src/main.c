// solution/src/main.c


#include "../include/io.h"
#include "../include/transform.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
    //обрабатывем ошибки запуска через командную строку
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source-image> <transformed-image>\n", argv[0]);
        return 1;
    }

    const char* source_filename = argv[1]; //название исходного файла
    const char* transformed_filename = argv[2];//название итогового файла

    struct image original_image = load_image(source_filename);//превращаем .bmp в структуру image
    struct image rotated_image = rotate(original_image);// поворачиваем

    save_image(&rotated_image, transformed_filename);//сохраняем итоговый файл

    //освобождаем память
    destroy_image(&original_image);
    destroy_image(&rotated_image);

    return 0;
}
