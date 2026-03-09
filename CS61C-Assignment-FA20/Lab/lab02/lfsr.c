#include "lfsr.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lfsr_calculate(uint16_t *reg) {
    /* YOUR CODE HERE */
    int bit0 = (*reg) & 1;
    int bit2 = (*reg >> 2) & 1;
    int bit3 = (*reg >> 3) & 1;
    int bit5 = (*reg >> 5) & 1;

    int newBit = bit0 ^ bit2 ^ bit3 ^ bit5;

    *reg = *reg >> 1 | newBit << 15;
}
