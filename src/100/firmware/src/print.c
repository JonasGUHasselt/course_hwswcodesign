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
	print_chr('h');
	char buffer[50];
	int i = 0;
	print_chr('e');
	unsigned int absolute_value_number = val < 0 ? -val : val;
	print_chr('l');
	while(absolute_value_number!=0)
	{
		print_chr('w');
		buffer[i++] = absolute_value_number%10+'0';
		print_chr('o');
		absolute_value_number=absolute_value_number/10;
		print_chr('w');
	}
	print_chr('l');
	if(val < 0)
		buffer[i++] = '-';

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

