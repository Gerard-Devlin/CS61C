/************************************************************************
**
** NAME:        steganography.c
**
** DESCRIPTION: CS61C Fall 2020 Project 1
**
** AUTHOR:      Dan Garcia  -  University of California at Berkeley
**              Copyright (C) Dan Garcia, 2020. All rights reserved.
**				Justin Yokota - Starter Code
**				YOUR NAME HERE
**
** DATE:        2020-08-23
**
**************************************************************************/

#include "imageloader.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

// Determines what color the cell at the given row/col should be. This should not affect Image, and
// should allocate space for a new Color.
Color *evaluateOnePixel(Image *image, int row, int col) {
    // YOUR CODE HERE
    //  给返回的新像素分配空间
    Color *newColor = malloc(sizeof(Color));
    if (newColor == NULL) {
        return NULL;
    }

    // 取出原图中这个位置像素的蓝色通道
    uint8_t blue = image->image[row][col].B;

    // blue 的最低位如果是 1，就设成白色
    // blue 的最低位如果是 0，就设成黑色
    if ((blue & 1) == 1) {
        newColor->R = 255;
        newColor->G = 255;
        newColor->B = 255;
    } else {
        newColor->R = 0;
        newColor->G = 0;
        newColor->B = 0;
    }

    return newColor;
}

// Given an image, creates a new image extracting the LSB of the B channel.
Image *steganography(Image *image) {
    // YOUR CODE HERE
    // 先给新图片本身分配空间
    Image *newImage = malloc(sizeof(Image));
    if (newImage == NULL) {
        return NULL;
    }

    // 新图和原图尺寸一样
    newImage->rows = image->rows;
    newImage->cols = image->cols;

    // 给新图的每一行指针分配空间
    newImage->image = malloc(newImage->rows * sizeof(Color *));
    if (newImage->image == NULL) {
        free(newImage);
        return NULL;
    }

    // 给新图每一行分配空间
    for (uint32_t r = 0; r < newImage->rows; r++) {
        newImage->image[r] = malloc(newImage->cols * sizeof(Color));
        if (newImage->image[r] == NULL) {
            for (uint32_t i = 0; i < r; i++) {
                free(newImage->image[i]);
            }
            free(newImage->image);
            free(newImage);
            return NULL;
        }
    }

    // 逐像素计算新图
    for (uint32_t r = 0; r < newImage->rows; r++) {
        for (uint32_t c = 0; c < newImage->cols; c++) {
            Color *pixel = evaluateOnePixel(image, r, c);

            if (pixel == NULL) {
                for (uint32_t i = 0; i < newImage->rows; i++) {
                    free(newImage->image[i]);
                }
                free(newImage->image);
                free(newImage);
                return NULL;
            }

            // 把算出来的新像素拷贝进新图
            newImage->image[r][c] = *pixel;

            // evaluateOnePixel 里单独 malloc 了一个 Color，这里用完就 free
            free(pixel);
        }
    }

    return newImage;
}

/*
Loads a file of ppm P3 format from a file, and prints to stdout (e.g. with printf) a new image,
where each pixel is black if the LSB of the B channel is 0,
and white if the LSB of the B channel is 1.

argc stores the number of arguments.
argv stores a list of arguments. Here is the expected input:
argv[0] will store the name of the program (this happens automatically).
argv[1] should contain a filename, containing a file of ppm P3 format (not necessarily with .ppm
file extension). If the input is not correct, a malloc fails, or any other error occurs, you should
exit with code -1. Otherwise, you should return from main with code 0. Make sure to free all memory
before returning!
*/
int main(int argc, char **argv) {
    // YOUR CODE HERE
    // steganography 程序应该只接收一个输入文件名
    if (argc != 2) {
        return -1;
    }

    // 读取输入图片
    Image *inputImage = readData(argv[1]);
    if (inputImage == NULL) {
        return -1;
    }

    // 生成隐藏信息对应的新图片
    Image *outputImage = steganography(inputImage);
    if (outputImage == NULL) {
        freeImage(inputImage);
        return -1;
    }

    // 输出结果
    writeData(outputImage);

    // 释放内存
    freeImage(inputImage);
    freeImage(outputImage);

    return 0;
}
