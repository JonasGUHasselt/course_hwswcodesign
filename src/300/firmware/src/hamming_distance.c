#include <stdint.h>
#include "hamming_distance.h"

uint32_t get_hamming_distance(uint32_t x, uint32_t y)
{
    HAMMING_DISTANCE_OPERAND_X = x;
    HAMMING_DISTANCE_OPERAND_Y = y;
    CALCULATE = 1;
    CALCULATE = 0;
    return HAMMING_DISTANCE_OUT;
}