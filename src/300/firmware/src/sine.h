/*
 * sine.h
 */

#ifndef HAMMING_DISTANCE_DRIVER_H
#define HAMMING_DISTANCE_DRIVER_H

#define SINE_BASEADDRESS      0x81100000
#define SINE_REG0_ADDRESS     (SINE_BASEADDRESS + 0*4)
#define SINE_REG1_ADDRESS     (SINE_BASEADDRESS + 1*4)
      
#define ANGLE           (*(volatile unsigned int *) SINE_REG0_ADDRESS)
#define SINE_OUT        (*(volatile unsigned int *) SINE_REG1_ADDRESS)

uint32_t sine(uint32_t angle);

#endif
  