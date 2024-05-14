/*
 * encoding.h
 */

#ifndef ENCODING_H
#define ENCODING_H

#define IMAGE_BASEADDRESS       0x40000000
#define IMAGE_REG0_ADDRESS      (IMAGE_BASEADDRESS + 0*4)
#define IMAGE_REG1_ADDRESS      (IMAGE_BASEADDRESS + 1*4)
#define IMAGE_REG2_ADDRESS      (IMAGE_BASEADDRESS + 2*4)

#define IMAGE_WIDTH             (*(volatile unsigned int *) IMAGE_REG0_ADDRESS)
#define IMAGE_HEIGHT            (*(volatile unsigned int *) IMAGE_REG1_ADDRESS)
#define IMAGE_PIXEL_VALUE(index)(*(volatile unsigned int *) (IMAGE_REG2_ADDRESS + index*4))

#define APB_QOI_BASEADDRESS    0x21000000 
#define APB_REG0_ADDRESS       (APB_QOI_BASEADDRESS + 0*4)
#define APB_REG1_ADDRESS       (APB_QOI_BASEADDRESS + 1*4)
#define APB_REG2_ADDRESS       (APB_QOI_BASEADDRESS + 2*4)
#define APB_REG3_ADDRESS       (APB_QOI_BASEADDRESS + 3*4)
#define APB_REG4_ADDRESS       (APB_QOI_BASEADDRESS + 4*4)

#define CURRENT_PIXEL                   (*(volatile unsigned int *) APB_REG0_ADDRESS)
#define PREVIOUS_PIXEL                  (*(volatile unsigned int *) APB_REG1_ADDRESS)
#define CURRENT_EQUALS_PREVIOUS_PIXEL   (*(volatile unsigned int *) APB_REG2_ADDRESS)

#define RLE                 (*(volatile unsigned int *) APB_REG3_ADDRESS)
#define INCREMENT_RLE       (*(volatile unsigned int *) APB_REG4_ADDRESS)

void encode_image(void);
void construct_header(void);
void construct_body(void);
void get_rgb_values(unsigned int pixel, unsigned char *rgb);
bool is_previous_pixel(unsigned int pixel);
void increase_run_length_encoding(void);
void save_run_length_encoding(void);
void reset_run_length_encoding(void);
bool is_present_in_running_array(unsigned int pixel);
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