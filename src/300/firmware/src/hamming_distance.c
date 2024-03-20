#include <stdint.h>
#include "hamming_distance.h"
#include "counter.h"

uint32_t get_hamming_weight(uint32_t x)
{
    unsigned int hamming_weight = 0;
    
    for (unsigned int i=0; i<32; i++)
    {
        if (x & 0x00000001)
        {
            hamming_weight++;
        }

        x >>= 1;
    }

    return hamming_weight;
}

uint32_t get_hamming_distance(uint32_t x, uint32_t y)
{
    return get_hamming_weight(x ^ y);
}