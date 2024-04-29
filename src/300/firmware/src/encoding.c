#include <stdbool.h>
#include "encoding.h"
#include "print.h"

#define MAX_RLE_SIZE 0x3F

unsigned char previous_pixel[4] = {0x00, 0x00, 0x00, 0xFF}; 
unsigned int running_array[64] = {};
long run_length_encoding = -1;

void encode_image(void)
{
    construct_header();
    construct_body();
}

void construct_header(void)
{
    // encode 'qoif' 0x716F6966
    print_hex(0x716F6966, 8);

    // width of image 32 bits
    print_hex(IMAGE_WIDTH, 8);

    // height of image 32 bits
    print_hex(IMAGE_HEIGHT, 8);

    // number of channels 0x03
    print_hex(0x03, 2);

    // colorspace 0x00
    print_hex(0x00, 2);
}

void construct_body(void)
{
    bool pixel_handled = false;
    int number_of_pixels = IMAGE_WIDTH * IMAGE_HEIGHT;
    for (int i=0; i < number_of_pixels ; i++)
    {
        pixel_handled = false;
        unsigned int pixel = IMAGE_PIXEL_VALUE(i);
        print_chr('\n');
        print_chr('p');
        print_hex(pixel, 8);
        print_chr('\n');
        print_chr('\n');
        
        if (is_previous_pixel(pixel))
        {
            increase_run_length_encoding();
            pixel_handled = true;
        } else {
            save_run_length_encoding();
            reset_run_length_encoding();
        }

        if (pixel_handled) {continue;}
        print_chr('y');
        if (is_present_in_running_array(pixel))
        {
            save_running_array_encoding(pixel);
            set_pixel_as_previous_pixel(pixel);
            pixel_handled = true;
        } else {
            add_pixel_to_running_array(pixel);
        }

        if(pixel_handled) {continue;}
        print_chr('e');
        if(can_calculate_difference(pixel))
        {
            print_chr('d');
            unsigned int difference = calculate_difference(pixel);
            save_difference_encoding(difference);
        } else {
            print_chr('r');
            save_rgb_encoding(pixel);
        }

        set_pixel_as_previous_pixel(pixel);
        print_chr('s');
    }

    if (run_length_encoding != -1)
    {
        save_run_length_encoding();
        reset_run_length_encoding();
    }

    print_hex(0x0000000000000001, 16);
}

void get_rgb_values(unsigned int pixel, unsigned char *rgb)
{
    rgb[0] =  pixel >> 24 & 0xFF;
    rgb[1] = (pixel >> 16) & 0xFF;
    rgb[2] = (pixel >> 8) & 0xFF;
    rgb[3] = pixel & 0xFF;
}

bool is_previous_pixel(unsigned int pixel)
{
    unsigned char current_pixel[4];

    get_rgb_values(pixel, current_pixel);

    bool is_same_pixel = current_pixel[0] == previous_pixel[0] 
                        && current_pixel[1] == previous_pixel[1] 
                        && current_pixel[2] == previous_pixel[2]
                        && current_pixel[3] == previous_pixel[3];
    
    return is_same_pixel;
}

void increase_run_length_encoding(void)
{
    bool is_max_size = run_length_encoding == MAX_RLE_SIZE;

    if (is_max_size) {return;}

    run_length_encoding++;
}

void save_run_length_encoding(void)
{
    bool is_run_length_encoding = run_length_encoding != -1;
    
    if(!is_run_length_encoding) {return;}

    unsigned char rle_chunk = (0b11 << 6) + run_length_encoding; 
    
    print_hex(rle_chunk, 2);
}

void reset_run_length_encoding(void)
{
    run_length_encoding = -1;
}

bool is_present_in_running_array(unsigned int pixel)
{
    unsigned char index = get_index(pixel);
    if (index != 0 && running_array[index] == 0)
    {
        return false;
    }

    return true;
}

unsigned char get_pixel_hash(unsigned char *pixel)
{
    unsigned char red_value = pixel[0];
    unsigned char green_value = pixel[1];
    unsigned char blue_value = pixel[2];
    unsigned char alpha_value = pixel[3];

    unsigned char hash = (
                            red_value * 3 
                            + green_value * 5 
                            + blue_value * 7 
                            + alpha_value * 11
                            ) % 64;

    return hash;
}

unsigned char get_index(unsigned int pixel)
{
    unsigned char rgb_pixel[4]; 
    get_rgb_values(pixel, rgb_pixel);

    return get_pixel_hash(rgb_pixel); 
}

void save_running_array_encoding(unsigned int pixel)
{
    unsigned char index = get_index(pixel);

    unsigned char chunk = index;

    print_hex(chunk, 2);
}

void add_pixel_to_running_array(unsigned int pixel)
{
    unsigned char index = get_index(pixel);
    running_array[index] = pixel;
}

bool can_calculate_difference(unsigned int pixel)
{
    for (char i = 0; (pixel >> i) > 0; i+=2)
    {
        char value = (pixel >> i) & 0xFF;
        print_chr('\n');
        print_chr('i');
        print_hex(i, 2);
        print_chr('\n');
        print_hex(value, 2);
        print_chr('\n');
        print_chr('\n');
        if (value != (char)0xFF && value !=(char)0x00){return false;}
    }   
    
    return true;
}

unsigned int calculate_difference(unsigned int pixel)
{
    unsigned char current_pixel[4];
    unsigned int difference;

    get_rgb_values(pixel, current_pixel);

    unsigned char red_value = current_pixel[0]; 
    unsigned char green_value = current_pixel[1];
    unsigned char blue_value = current_pixel[2];

    difference += (unsigned char)(red_value - previous_pixel[0]);
    difference <<= 8;
    difference += (unsigned char)(green_value - previous_pixel[1]);
    difference <<= 8;
    difference += (unsigned char)(blue_value - previous_pixel[2]);
    return difference;
}

void save_difference_encoding(unsigned int difference)
{
    unsigned char difference_chunk = 0b01 << 2;

    difference_chunk += ((char)((difference >> 16) & 0xFF)) + 2;
    difference_chunk <<= 2;
    difference_chunk += ((char)((difference >> 8) & 0xFF)) + 2;
    difference_chunk <<= 2;
    difference_chunk += ((char) (difference & 0xFF)) + 2;

    print_hex(difference_chunk, 2);
}

void save_rgb_encoding(unsigned int pixel)
{
    unsigned char current_pixel[4];
    unsigned int rgb_chunk = 0b11111110 << 8;
    get_rgb_values(pixel, current_pixel);
    rgb_chunk += current_pixel[0];
    rgb_chunk <<= 8;
    rgb_chunk += current_pixel[1];
    rgb_chunk <<= 8;
    rgb_chunk += current_pixel[2];

    print_hex(rgb_chunk, 8);
}

void set_pixel_as_previous_pixel(unsigned int pixel)
{
    unsigned char current_pixel[4];
    get_rgb_values(pixel, current_pixel);

    previous_pixel[0] = current_pixel[0];
    previous_pixel[1] = current_pixel[1];
    previous_pixel[2] = current_pixel[2];
    previous_pixel[3] = current_pixel[3];
}