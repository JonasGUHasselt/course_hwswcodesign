#include <stdint.h>
#include "sine.h"

uint32_t sine(uint32_t angle)
{
    //modulo 360
    while (angle >= 360)
    {
        angle -= 360;
    }

    ANGLE = angle;
    
    return SINE_OUT;
}