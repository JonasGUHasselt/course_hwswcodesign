#include "print.h"

extern unsigned int hwswcd_avg(unsigned int value1, unsigned int value2);

void main(void) {
	volatile unsigned int value1, value2, avg;

	value1 = 5;
	value2 = 9;

    avg = hwswcd_avg(value1, value2);

	print_str("AVG(0x");
	print_hex(value1, 2);
	print_str(", ");
	print_hex(value2, 2);	
	print_str(") = 0x");
	print_hex(avg, 2);
	print_str(".");
}
