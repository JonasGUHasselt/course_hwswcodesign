#include <stdint.h>
#include "matrix.h"
#include "counter.h"

uint32_t multiply(uint32_t matrix_1, uint32_t matrix_2)
{
    MATRIX_A = matrix_1;
    MATRIX_B = matrix_2;
    CE = 1;
    counter.start();
    counter.stop();
    CE = 0;
    
    return RESULT_MATRIX;
}