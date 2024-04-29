/*
 * encoding.h
 */

#ifndef ENCODING_H
#define ENCODING_H

#define IMAGE_BASEADDRESS       0x40000000
#define IMAGE_REG0_ADDRESS      (IMAGE_BASEADDRESS + 0*4)
#define IMAGE_REG1_ADDRESS      (IMAGE_BASEADDRESS + 1*4)
#define IMAGE_REG2_ADDRESS      (IMAGE_BASEADDRESS + 2*4)

#define IMAGE_REG3_ADDRESS      (IMAGE_BASEADDRESS + 3*4)
#define IMAGE_REG4_ADDRESS      (IMAGE_BASEADDRESS + 4*4)
#define IMAGE_REG5_ADDRESS      (IMAGE_BASEADDRESS + 5*4)
#define IMAGE_REG6_ADDRESS      (IMAGE_BASEADDRESS + 6*4)

#define IMAGE_WIDTH             (*(volatile unsigned int *) IMAGE_REG0_ADDRESS)
#define IMAGE_HEIGHT            (*(volatile unsigned int *) IMAGE_REG1_ADDRESS)
#define IMAGE_PIXEL_VALUE      ((volatile unsigned int *) IMAGE_REG2_ADDRESS)

#define IMAGE_PIXEL_VALUE1      ((volatile unsigned int *) IMAGE_REG3_ADDRESS)
#define IMAGE_PIXEL_VALUE2      ((volatile unsigned int *) IMAGE_REG4_ADDRESS)
#define IMAGE_PIXEL_VALUE3      ((volatile unsigned int *) IMAGE_REG5_ADDRESS)
#define IMAGE_PIXEL_VALUE4      ((volatile unsigned int *) IMAGE_REG6_ADDRESS)

void encode_image(void);
void construct_header(void);
void construct_body(void);
void get_rgb_values(unsigned int pixel, unsigned char *rgb);
bool is_previous_pixel(unsigned int pixel);
void increase_run_length_encoding(void);
void save_run_length_encoding(void);
void reset_run_length_encoding(void);
bool is_present_in_running_array(unsigned char pixel);
unsigned char get_pixel_hash(unsigned char *pixel);
unsigned char get_index(unsigned int pixel);
void save_running_array_encoding(unsigned int pixel);
void add_pixel_to_running_array(unsigned int pixel);
bool can_calculate_difference(unsigned int pixel);
unsigned int calculate_difference(unsigned int pixel);
void save_difference_encoding(unsigned int difference);
void save_rgb_encoding(unsigned int pixel);
void set_pixel_as_previous_pixel(unsigned int pixel);

#endif