#include <stdint.h>
#include "sine.h"

uint32_t sine(uint32_t angle)
{
    ANGLE = angle;
    return SINE_OUT;
}