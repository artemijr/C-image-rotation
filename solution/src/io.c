// solution/src/io.c

#include "bmp.h"
#include <stdio.h>
#include <stdlib.h>


// Функция для открытия файла с обработкой ошибок
FILE* open_file(const char* filename, const char* mode) {
    FILE* file = fopen(filename, mode);
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    return file;
}

// Функция для закрытия файла с обработкой ошибок
void close_file(FILE* file) {
    if (fclose(file) == EOF) {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }
}
//функция загрузки .bmp в структуру image
struct image load_image(const char* filename) {
    FILE* file = open_file(filename, "rb"); // Используем open_file для открытия файла

    struct image img;
    enum read_status status = from_bmp(file, &img); // Считываем .bmp и заполняем структуру, также получаем статус

    if (status != READ_OK) {
        close_file(file); // Используем close_file для закрытия файла

    }

    close_file(file); // Используем close_file для закрытия файла
    return img;
}

//превращаем структуру image в .bmp
void save_image(const struct image* img, const char* filename) {
    FILE* file = open_file(filename, "wb"); // Используем open_file для открытия файла

    enum write_status status = to_bmp(file, img); // Конвертируем структуру image в .bmp, также получаем статус

    if (status != WRITE_OK) {
        close_file(file); // Используем close_file для закрытия файла

    }

    close_file(file); // Используем close_file для закрытия файла
}
