#include <stdint.h>
#include "hamming_distance.h"
#include "counter.h"

unsigned int get_hamming_weight(unsigned int x)
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

unsigned int get_hamming_distance(unsigned int x, unsigned int y)
{
    return get_hamming_weight(x ^ y);
}