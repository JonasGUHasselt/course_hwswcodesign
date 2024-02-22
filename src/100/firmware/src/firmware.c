#include "print.h"

unsigned int convert(unsigned int x);

void main(void) {
    print_chr('*');
	print_str("\nhello world\n");
    //print_dec(5);
    print_dec(64);
    print_dec(600);
    print_hex(64, 8);
    print_dec(convert(86));
}

unsigned int convert(unsigned int x) {
    return (unsigned int)((x - 32) * (5.0/9.0));
}