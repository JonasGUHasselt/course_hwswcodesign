#include "print.h"
#include "counter.h"
//#include "hamming_distance.h"
#include "sine.h"


void main(void) {

	uint32_t counter;
	//uint32_t hamming_distance;
	uint32_t result;
	print_str("hello world");
	print_chr('\n');

	counter_clear();
	counter_start();
	counter_stop();

	counter = counter_get_value();
	print_hex((unsigned int)(counter), 8);
	print_chr('\n');

/*
	hamming_distance = get_hamming_distance(4294967295, 4294967294);
	print_hex((unsigned int)(hamming_distance), 8);
	print_chr('\n');
*/

	result = sine(15);
	print_hex((unsigned int)(result), 8);
	result = sine(25);
	print_hex((unsigned int)(result), 8);
	result = sine(275);
	print_hex((unsigned int)(result), 8);
	print_chr('\n');

}
