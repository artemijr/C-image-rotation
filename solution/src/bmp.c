// solution/src/bmp.c

#include "image.h"
#include <stdio.h>
#include <stdlib.h>

#define BMP_SIGNATURE 0x4D42
#define BITS_PER_PIXEL 24

#pragma pack(push, 1)//устанавливаем выравнивание в 1 байт

//структура для заголовка BMP-изображения
struct bmp_file_header {
    uint16_t bfType;//отметка формата (два ascii символа: «bm»)
    uint32_t bfileSize;//размер файла в байтах
    uint32_t bfReserved;//зарезервированное пространство (заполнено нулями)
    uint32_t bOffBits;//положение данных о пикселях относительно начала файла
};
//заголовок растровой информации
struct bmp_info_header {
    uint32_t biSize;//размер блока, также указывающий на его версию
    uint32_t biWidth;//ширина изображения (в пикселях)
    uint32_t biHeight;//высота изображения (в пикселях)
    uint16_t biPlanes;//значение формата (для .bmp файлов всегда равно 1)
    uint16_t biBitCount;//количество бит на пиксель
    uint32_t biCompression;//метод компрессии
    uint32_t biSizeImage;//размер пиксельных данных (если не используется сжатие, может быть равно 0)
    uint32_t biXPelsPerMeter;//ppm по горизонтали
    uint32_t biYPelsPerMeter;//ppm по вертикали
    uint32_t biClrUsed;//размер таблицы цветов в ячейках
    uint32_t biClrImportant;//количество ячеек от начала таблицы цветов до последней используемой (включая её саму)
};
#pragma pack(pop)//возвращение к предыдущему значению выравнивания данных

//вспомогательная функция для выравнивания строки до кратности 4 байтам
size_t calculate_padding(size_t width) {
    size_t padding = 0;
    size_t row_size = width * 3;
    if (row_size % 4 != 0) {
        padding = 4 - (row_size % 4);
    }
    return padding;
}

//конвертируем .bmp в структуру image
enum read_status from_bmp(FILE* in, struct image* img) {
    struct bmp_file_header file_header;
    struct bmp_info_header info_header;

    //чтение заголовков BMP
    if (fread(&file_header, sizeof(file_header), 1, in) != 1 ||
        fread(&info_header, sizeof(info_header), 1, in) != 1) {
        return READ_INVALID_HEADER;
    }

    //проверка отметки формата и проверка на то что один пиксель 24 бита
    if (file_header.bfType != BMP_SIGNATURE || info_header.biBitCount != BITS_PER_PIXEL) {
        return READ_INVALID_SIGNATURE;
    }

    img->width = info_header.biWidth;
    img->height = info_header.biHeight;

    // Расчет размера изображения и padding
    size_t padding = calculate_padding(img->width);

    img->data = (struct pixel*)malloc(sizeof(struct pixel) * img->width * img->height);

    //"проверка работы" malloc
    if (!img->data) {
        return READ_INVALID_BITS;
    }

//чтение данных растрового массива
    for (uint32_t i = 0; i < img->height; i++) {
        for (uint32_t j = 0; j < img->width; j++) {
            fread(&img->data[i * img->width + j], sizeof(struct pixel), 1, in);
        }
        // Убедитесь, что padding умещается в long
        long padding_for_seek = (long)padding;
        if (padding != padding_for_seek) {
            fprintf(stderr, "Padding size is too large for fseek\n");
            exit(EXIT_FAILURE);
        }
        fseek(in, padding_for_seek, SEEK_CUR); // учитываем padding
    }

    return READ_OK;
}

void create_bmp_headers(struct bmp_file_header* file_header,
                        struct bmp_info_header* info_header,
                        const struct image* img) {
    file_header->bfType = BMP_SIGNATURE; // 'BM'
    file_header->bfileSize = sizeof(struct bmp_file_header) + sizeof(struct bmp_info_header) +
                             img->width * img->height * sizeof(struct pixel) +
                             calculate_padding(img->width) * img->height;
    file_header->bfReserved = 0;
    file_header->bOffBits = sizeof(struct bmp_file_header) + sizeof(struct bmp_info_header);

    info_header->biSize = sizeof(struct bmp_info_header);
    info_header->biWidth = img->width;
    info_header->biHeight = img->height;
    info_header->biPlanes = 1;
    info_header->biBitCount = 24;
    info_header->biCompression = 0;
    info_header->biSizeImage = 0; // 0 сжатие не используется
    info_header->biXPelsPerMeter = 0;
    info_header->biYPelsPerMeter = 0;
    info_header->biClrUsed = 0;
    info_header->biClrImportant = 0;}

//функция конвертации структуры image в .bmp
enum write_status to_bmp(FILE* out, const struct image* img) {
    struct bmp_file_header file_header;
    struct bmp_info_header info_header;

    // Заполнение заголовка BMP
    create_bmp_headers(&file_header, &info_header, img);


    //запись заголовка .bmp
    fwrite(&file_header, sizeof(file_header), 1, out);
    fwrite(&info_header, sizeof(info_header), 1, out);

    //запись данных растрового массива
    size_t padding = calculate_padding(img->width);
    uint8_t padding_byte = 0;
    for (uint32_t i = 0; i < img->height; i++) {
        for (uint32_t j = 0; j < img->width; j++) {
            fwrite(&img->data[i * img->width + j], sizeof(struct pixel), 1, out);
        }
        for (int k = 0; k < padding; k++) {
            fwrite(&padding_byte, sizeof(uint8_t), 1, out);
        }
    }

    return WRITE_OK;
}
