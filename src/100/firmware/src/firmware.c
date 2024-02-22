#include "print.h"

unsigned int convert(unsigned int x);

void main(void) {
    print_chr('*');
	print_str("\nhello world\n");
    //print_dec(5);
    print_dec(64);
    print_dec(600);
    print_hex(64, 8);
}

unsigned int convert(unsigned int x) {
    return (x - 32) * (5/9);
}