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
	char buffer[50];
	int i = 0;
	unsigned int current_number = val;

	while(current_number!=0)
	{
		unsigned int test = current_number%10;
		print_chr('c');
		char test2 = test + (int) '0';
		print_chr('r');
		buffer[i++] = test2;
		print_chr('a');

		buffer[i++] = current_number%10+'0';
		print_chr('o');
		current_number=current_number/10;
		print_chr('w');
	}
	
	print_chr('l');

	buffer[i] = '\0';
	print_chr('o');
	for(int t = 0; t < i/2; t++)
	{
		buffer[t] ^= buffer[i-t-1];
		buffer[i-t-1] ^= buffer[t];
		buffer[t] ^= buffer[i-t-1];
	}

	if(val == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
	}   

	print_str(buffer);
}


void print_hex(unsigned int val, int digits)
{
	for (int i = (4*digits)-4; i >= 0; i -= 4)
		*((volatile unsigned int*)OUTPORT) = "0123456789ABCDEF"[(val >> i) % 16];
	print_chr('\n');
}

