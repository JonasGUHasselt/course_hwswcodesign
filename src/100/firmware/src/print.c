// This is free and unencumbered software released into the public domain.
//
// Anyone is free to copy, modify, publish, use, compile, sell, or
// distribute this software, either in source code form or as a compiled
// binary, for any purpose, commercial or non-commercial, and by any
// means.

#include "print.h"

void print_chr(char ch)
{
	*((volatile unsigned int*)OUTPORT) = ch;
}

void print_str(const char *p)
{
	while (*p != 0)
		*((volatile unsigned int*)OUTPORT) = *(p++);
}


void print_dec(unsigned int val)
{
	//laatste cijfer
	unsigned int number_of_digits = 0;
	char number_to_print[200];

	while (val > 0)
	{
		unsigned int number = val;
		unsigned int divison_result = 0;

		while (number >= 10)
		{
			divison_result++;
			number -= 10;
		}

		if (number_of_digits <= sizeof(number_to_print))
		{
			number_to_print[number_of_digits] = number;		
		}

		number_of_digits++;
		
		val = divison_result;
	}

	for (int i = number_of_digits-1; i >= 0; i--)
	{
		char number = 48 + number_to_print[i];
		print_chr(number);
	}
}


void print_hex(unsigned int val, int digits)
{
	for (int i = (4*digits)-4; i >= 0; i -= 4)
		*((volatile unsigned int*)OUTPORT) = "0123456789ABCDEF"[(val >> i) % 16];
	print_chr('\n');
}