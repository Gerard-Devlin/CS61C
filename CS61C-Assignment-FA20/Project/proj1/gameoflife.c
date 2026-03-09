/************************************************************************
**
** NAME:        gameoflife.c
**
** DESCRIPTION: CS61C Fall 2020 Project 1
**
** AUTHOR:      Justin Yokota - Starter Code
**				YOUR NAME HERE
**
**
** DATE:        2020-08-23
**
**************************************************************************/

#include "imageloader.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

// Determines what color the cell at the given row/col should be. This function allocates space for
// a new Color. Note that you will need to read the eight neighbors of the cell in question. The
// grid "wraps", so we treat the top row as adjacent to the bottom row and the left column as
// adjacent to the right column.
Color *evaluateOneCell(Image *image, int row, int col, uint32_t rule) {
    // 给新的颜色分配空间
    Color *newColor = malloc(sizeof(Color));
    if (newColor == NULL) {
        return NULL;
    }

    // 先把新颜色清零，后面再一位一位设置
    newColor->R = 0;
    newColor->G = 0;
    newColor->B = 0;

    // 为了方便做“环绕”运算，先取出行数和列数
    int rows = (int)image->rows;
    int cols = (int)image->cols;

    // 下面会分别处理 R、G、B 三个通道
    // 每个通道里又要分别处理 bit 0 到 bit 7
    for (int bit = 0; bit < 8; bit++) {
        int redNeighbors = 0;
        int greenNeighbors = 0;
        int blueNeighbors = 0;

        // 统计 8 个邻居
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                // 跳过自己本身
                if (dr == 0 && dc == 0) {
                    continue;
                }

                // 环绕边界
                int nr = (row + dr + rows) % rows;
                int nc = (col + dc + cols) % cols;

                // 取出邻居对应 bit 是否为 1
                redNeighbors += (image->image[nr][nc].R >> bit) & 1;
                greenNeighbors += (image->image[nr][nc].G >> bit) & 1;
                blueNeighbors += (image->image[nr][nc].B >> bit) & 1;
            }
        }

        // 当前这个像素在当前 bit 上是否活着
        int redAlive = (image->image[row][col].R >> bit) & 1;
        int greenAlive = (image->image[row][col].G >> bit) & 1;
        int blueAlive = (image->image[row][col].B >> bit) & 1;

        // 根据题目的规则编码方式：
        // dead(0) 的 0~8 邻居存在 rule 的低 9 位
        // alive(1) 的 0~8 邻居存在 rule 的高 9 位
        int redRuleBit;
        int greenRuleBit;
        int blueRuleBit;

        if (redAlive == 1) {
            redRuleBit = redNeighbors + 9;
        } else {
            redRuleBit = redNeighbors;
        }

        if (greenAlive == 1) {
            greenRuleBit = greenNeighbors + 9;
        } else {
            greenRuleBit = greenNeighbors;
        }

        if (blueAlive == 1) {
            blueRuleBit = blueNeighbors + 9;
        } else {
            blueRuleBit = blueNeighbors;
        }

        // 看 rule 对应位置上的 bit 是否为 1
        int nextRedAlive = (rule >> redRuleBit) & 1;
        int nextGreenAlive = (rule >> greenRuleBit) & 1;
        int nextBlueAlive = (rule >> blueRuleBit) & 1;

        // 如果下一代该 bit 活着，就把它设到新颜色里
        if (nextRedAlive == 1) {
            newColor->R |= (1 << bit);
        }

        if (nextGreenAlive == 1) {
            newColor->G |= (1 << bit);
        }

        if (nextBlueAlive == 1) {
            newColor->B |= (1 << bit);
        }
    }

    return newColor;
}

// The main body of Life; given an image and a rule, computes one iteration of the Game of Life.
// You should be able to copy most of this from steganography.c
Image *life(Image *image, uint32_t rule) {
    // 给新图片本身分配空间
    Image *newImage = malloc(sizeof(Image));
    if (newImage == NULL) {
        return NULL;
    }

    // 新图尺寸和原图一样
    newImage->rows = image->rows;
    newImage->cols = image->cols;

    // 给每一行的指针分配空间
    newImage->image = malloc(newImage->rows * sizeof(Color *));
    if (newImage->image == NULL) {
        free(newImage);
        return NULL;
    }

    // 给每一行真正的像素数组分配空间
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

    // 逐像素计算下一代
    for (uint32_t r = 0; r < newImage->rows; r++) {
        for (uint32_t c = 0; c < newImage->cols; c++) {
            Color *pixel = evaluateOneCell(image, (int)r, (int)c, rule);
            if (pixel == NULL) {
                for (uint32_t i = 0; i < newImage->rows; i++) {
                    free(newImage->image[i]);
                }
                free(newImage->image);
                free(newImage);
                return NULL;
            }

            // 把结果拷贝进去
            newImage->image[r][c] = *pixel;

            // evaluateOneCell 里 malloc 过，所以这里要 free
            free(pixel);
        }
    }

    return newImage;
}

/*
Loads a .ppm from a file, computes the next iteration of the game of life, then prints to stdout the
new image.

argc stores the number of arguments.
argv stores a list of arguments. Here is the expected input:
argv[0] will store the name of the program (this happens automatically).
argv[1] should contain a filename, containing a .ppm.
argv[2] should contain a hexadecimal number (such as 0x1808). Note that this will be a string.
You may find the function strtol useful for this conversion.
If the input is not correct, a malloc fails, or any other error occurs, you should exit with code
-1. Otherwise, you should return from main with code 0. Make sure to free all memory before
returning!

You may find it useful to copy the code from steganography.c, to start.
*/
int main(int argc, char **argv) {
    // 参数个数必须是 3：程序名 + 文件名 + rule
    if (argc != 3) {
        printf("usage: ./gameOfLife filename rule\n");
        printf("filename is an ASCII PPM file (type P3) with maximum value 255.\n");
        printf("rule is a hex number beginning with 0x; Life is 0x1808.\n");
        return -1;
    }

    // 读取图片
    Image *inputImage = readData(argv[1]);
    if (inputImage == NULL) {
        return -1;
    }

    // 把字符串形式的十六进制转换成整数
    uint32_t rule = (uint32_t)strtol(argv[2], NULL, 16);

    // 计算下一代
    Image *outputImage = life(inputImage, rule);
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
