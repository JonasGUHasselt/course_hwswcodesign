#include "print.h"

unsigned int get_hamming_weight(unsigned int x);
unsigned int get_hamming_distance(unsigned int x, unsigned int y);
unsigned int get_factorial(unsigned int x);
unsigned int convert(unsigned int x);

void main(void) {
    print_chr('*');
	print_str("\nhello world\n");
    print_dec(64);
    print_dec(600);
    print_hex(64, 8);

    unsigned int hamming_weight = get_hamming_weight(60);
    print_str("Hamming weight: ");
    print_dec(hamming_weight);

    unsigned int number_1 = 40;
    unsigned int number_2 = 60;

    print_str("Hamming distance: ");
    print_dec(get_hamming_distance(number_1, number_2));

    unsigned int number = 5;
    print_str("Factorial: ");
    print_dec(get_factorial(number));
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

unsigned int get_hamming_distance(unsigned int x, unsigned int y)
{
    return get_hamming_weight(x ^ y);
}

unsigned int get_factorial(unsigned int x)
{
    unsigned int temp, i;

    if(x==1) return 1;
    if(x==2) return 2;

    temp = 1;

    for(i=2;i<=x;i++) {
        temp = temp * i;
    }

    return temp;
}

unsigned int convert(unsigned int x)
{
    unsigned int product = 0;
    unsigned int result = 0;
    unsigned int division_counter = 0;

    x-=32;

    for (unsigned int i = 0; i < 5; i++)
    {
        product += x;
    }
    
    while (product >= 9)
    {
        product-=9;
        division_counter++;
    }
    
    result = division_counter;
    return result;
}