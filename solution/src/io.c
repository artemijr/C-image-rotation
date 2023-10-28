// solution/src/io.c

#include "bmp.h"
#include <stdio.h>
#include <stdlib.h>

//функция загрузки .bmp в структуру image
struct image load_image(const char* filename) {

    FILE* file = fopen(filename, "rb");//открываем файл в режиме двоичного чтения

    //проверка успешности открытия
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    struct image img;
    enum read_status status = from_bmp(file, &img);//считываем .bmp и заполняем структуру, так же получаем статус

    //проверка успешности заполнения структуры image
    if (status != READ_OK) {
        fclose(file);
        fprintf(stderr, "Error reading BMP file: %d\n", status);
        exit(EXIT_FAILURE);
    }
    fclose(file);
    return img;
}

//превращаем структуру image в .bmp
void save_image(const struct image* img, const char* filename) {

    FILE* file = fopen(filename, "wb");//открываем файл в режиме двоичной записи

    //проверка успешности открытия
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    enum write_status status = to_bmp(file, img);//конвертируем структуру image в .bmp, так же получаем статус

    //проверка успешности конвертации
    if (status != WRITE_OK) {
        fclose(file);
        fprintf(stderr, "Error writing BMP file: %d\n", status);
        exit(EXIT_FAILURE);
    }
    fclose(file);
}
