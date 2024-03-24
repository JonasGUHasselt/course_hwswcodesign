#include <stdint.h>
#include "matrix.h"

uint32_t multiply(uint32_t matrix_1, uint32_t matrix_2)
{
    uint32_t temp;
    uint32_t result = ((matrix_1 & 0xff000000) >> 24) * ((matrix_2 & 0xff000000) >> 24);
    result += ((matrix_1 & 0x00ff0000) >> 16) * ((matrix_2 & 0x0000ff00) >> 8);
    result <<= 24;

    temp = ((matrix_1 & 0xff000000) >> 24) * ((matrix_2 & 0x00ff0000) >> 16);
    temp += ((matrix_1 & 0x00ff0000) >> 16) * ((matrix_2 & 0x000000ff));
    result += temp << 16;

    temp = ((matrix_1 & 0x0000ff00) >> 8) * ((matrix_2 & 0xff000000) >> 24);
    temp += ((matrix_1 & 0x000000ff)) * ((matrix_2 & 0x0000ff00) >> 8);
    result += temp << 8;

    result += ((matrix_1 & 0x0000ff00) >> 8) * ((matrix_2 & 0x00ff0000) >> 16);
    result += ((matrix_1 & 0x000000ff)) * ((matrix_2 & 0x000000ff));

    return result;
}