#include "print.h"

unsigned int get_hamming_weight(unsigned int x);

void main(void) {
    print_chr('*');
	print_str("\nhello world\n");
    print_dec(64);
    print_dec(600);
    print_hex(64, 8);

    unsigned int hamming_weight = get_hamming_weight(60);
    print_str("Hamming weight: ");
    print_dec(hamming_weight);
}

unsigned int get_hamming_weight(unsigned int x)
{
    unsigned int bit_counter = 0;
    unsigned int filter = 1;
    
    while (filter > 0)
    {

        if((x & filter) > 0)
        {
            bit_counter++;
        }

        filter <<= 1;
    }

    return bit_counter;
}