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