/*
 * matrix.h
 */

#ifndef MATRIX_DRIVER_H
#define MATRIX_DRIVER_H

#define SINE_BASEADDRESS      0x81100000
#define SINE_REG0_ADDRESS     (SINE_BASEADDRESS + 0*4)
#define SINE_REG1_ADDRESS     (SINE_BASEADDRESS + 1*4)
#define SINE_REG2_ADDRESS     (SINE_BASEADDRESS + 2*4)
#define SINE_REG3_ADDRESS     (SINE_BASEADDRESS + 3*4)
#define SINE_REG4_ADDRESS     (SINE_BASEADDRESS + 4*4)
      
#define CE              (*(volatile unsigned int *) SINE_REG0_ADDRESS)
#define MATRIX_A        (*(volatile unsigned int *) SINE_REG1_ADDRESS)
#define MATRIX_B        (*(volatile unsigned int *) SINE_REG2_ADDRESS)
#define RESULT_MATRIX   (*(volatile unsigned int *) SINE_REG3_ADDRESS)
#define RESULT_READY    (*(volatile unsigned int *) SINE_REG4_ADDRESS)

uint32_t multiply(uint32_t matrix_1, uint32_t matrix_2);

#endif
  