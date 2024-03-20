#include <stdint.h>
#include "hamming_distance.h"
#include "counter.h"

uint32_t get_hamming_distance(uint32_t x, uint32_t y)
{
    uint32_t counter = 0;

    HAMMING_DISTANCE_OPERAND_X = x;
    HAMMING_DISTANCE_OPERAND_Y = y;
    CALCULATE = 1;
    /*counter_start();
    while (counter < 32)
    {
        counter = counter_get_value();
    }
    counter_stop();
*/
    CALCULATE = 0;
    return HAMMING_DISTANCE_OUT;
}