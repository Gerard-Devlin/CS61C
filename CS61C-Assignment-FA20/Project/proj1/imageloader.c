/************************************************************************
**
** NAME:        imageloader.c
**
** DESCRIPTION: CS61C Fall 2020 Project 1
**
** AUTHOR:      Dan Garcia  -  University of California at Berkeley
**              Copyright (C) Dan Garcia, 2020. All rights reserved.
**              Justin Yokota - Starter Code
**				YOUR NAME HERE
**
**
** DATE:        2020-08-15
**
**************************************************************************/

#include "imageloader.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Opens a .ppm P3 image file, and constructs an Image object.
// You may find the function fscanf useful.
// Make sure that you close the file with fclose before returning.
Image *readData(char *filename) {
    // YOUR CODE HERE
    // 打开文件，使用只读模式
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        // 文件打开失败，直接返回 NULL
        return NULL;
    }

    // 用来读取 ppm 文件头部的信息
    char format[3];      // 用来存 "P3"
    uint32_t cols, rows; // 图片的列数和行数
    uint32_t maxValue;   // 最大颜色值，题目里应该是 255

    // 读取第一项：格式，比如 "P3"
    if (fscanf(fp, "%2s", format) != 1) {
        fclose(fp);
        return NULL;
    }

    // 读取第二项和第三项：cols 和 rows
    if (fscanf(fp, "%" SCNu32 " %" SCNu32, &cols, &rows) != 2) {
        fclose(fp);
        return NULL;
    }

    // 读取第四项：最大颜色值
    if (fscanf(fp, "%" SCNu32, &maxValue) != 1) {
        fclose(fp);
        return NULL;
    }

    // 检查文件头是否符合要求
    if (strcmp(format, "P3") != 0 || maxValue != 255) {
        fclose(fp);
        return NULL;
    }

    // 给 Image 结构体本身分配空间
    Image *img = malloc(sizeof(Image));
    if (img == NULL) {
        fclose(fp);
        return NULL;
    }

    // 保存图片的行数和列数
    img->rows = rows;
    img->cols = cols;

    // 给二维数组的“行指针”分配空间
    img->image = malloc(rows * sizeof(Color *));
    if (img->image == NULL) {
        free(img);
        fclose(fp);
        return NULL;
    }

    // 逐行分配空间，每一行有 cols 个 Color
    for (uint32_t r = 0; r < rows; r++) {
        img->image[r] = malloc(cols * sizeof(Color));

        // 如果某一行分配失败，要把前面已经分配好的都释放掉
        if (img->image[r] == NULL) {
            for (uint32_t i = 0; i < r; i++) {
                free(img->image[i]);
            }
            free(img->image);
            free(img);
            fclose(fp);
            return NULL;
        }
    }

    // 开始读取每个像素的 RGB 值
    for (uint32_t r = 0; r < rows; r++) {
        for (uint32_t c = 0; c < cols; c++) {
            // 先用普通无符号整数接收，再存进 uint8_t
            unsigned int red;
            unsigned int green;
            unsigned int blue;

            // 每个像素需要读 3 个数：R G B
            if (fscanf(fp, "%u %u %u", &red, &green, &blue) != 3) {
                // 如果读取失败，释放已经申请的所有内存
                for (uint32_t i = 0; i < rows; i++) {
                    free(img->image[i]);
                }
                free(img->image);
                free(img);
                fclose(fp);
                return NULL;
            }

            // 把读到的值存到对应像素里
            img->image[r][c].R = red;
            img->image[r][c].G = green;
            img->image[r][c].B = blue;
        }
    }

    // 文件读取完成，关闭文件
    fclose(fp);

    // 返回构造好的图片对象
    return img;
}

// Given an image, prints to stdout (e.g. with printf) a .ppm P3 file with the image's data.
void writeData(Image *image) {
    // YOUR CODE HERE
    // 如果传进来的图片是空指针，直接返回
    if (image == NULL) {
        return;
    }

    // 先输出 PPM 文件头
    // 第一行固定是 P3
    printf("P3\n");

    // 第二行是：列数 行数
    printf("%" PRIu32 " %" PRIu32 "\n", image->cols, image->rows);

    // 第三行固定是最大颜色值 255
    printf("255\n");

    // 逐行输出每个像素
    for (uint32_t r = 0; r < image->rows; r++) {
        for (uint32_t c = 0; c < image->cols; c++) {
            // 输出当前像素的 R G B
            // %3d 的意思是：至少占 3 个字符宽度，和题目要求一致
            printf("%3d %3d %3d", image->image[r][c].R, image->image[r][c].G, image->image[r][c].B);

            // 如果不是这一行的最后一个像素，补上 3 个空格
            if (c != image->cols - 1) {
                printf("   ");
            }
        }

        // 每一行结束后换行
        printf("\n");
    }
}

// Frees an image
void freeImage(Image *image) {
    // YOUR CODE HERE
    // 如果 image 本身就是空，没什么可释放的
    if (image == NULL) {
        return;
    }

    // 如果二维数组存在，就先逐行释放
    if (image->image != NULL) {
        for (uint32_t r = 0; r < image->rows; r++) {
            free(image->image[r]);
        }

        // 再释放“行指针数组”
        free(image->image);
    }

    // 最后释放 Image 结构体本身
    free(image);
}