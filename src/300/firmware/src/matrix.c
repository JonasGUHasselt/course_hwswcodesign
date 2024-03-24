#include <stdint.h>
#include "matrix.h"

uint32_t multiply(uint32_t matrix_1, uint32_t matrix_2)
{
    MATRIX_A = matrix_1;
    MATRIX_B = matrix_2;
    CE = 1;
    CE = 0;
    while(RESULT_READY != 1){}
    
    return RESULT_MATRIX;
}