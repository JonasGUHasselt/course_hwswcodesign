// This is free and unencumbered software released into the public domain.
//
// Anyone is free to copy, modify, publish, use, compile, sell, or
// distribute this software, either in source code form or as a compiled
// binary, for any purpose, commercial or non-commercial, and by any
// means.

#include "print.h"


void print_chr(char ch)
{
	*((volatile uint32_t*)OUTPORT) = ch;
}

void print_str(const char *p)
{
	while (*p != 0)
		*((volatile uint32_t*)OUTPORT) = *(p++);
}

void print_dec(unsigned int val)
{
	char buffer[10];
	char *p = buffer;
	while (val || p == buffer) {
		print_chr('c');

		*p = (unsigned char)(val % 10);
		p = p + 1;
		print_chr('l');
		val = val / 10;
		print_chr('a');
	}
	print_chr('i');
	while (p != buffer) {
		print_chr('n');
		*((volatile uint32_t*)OUTPORT) = '0' + *(--p);
	}
}

void print_hex(unsigned int val, int digits)
{
	for (int i = (4*digits)-4; i >= 0; i -= 4)
		*((volatile uint32_t*)OUTPORT) = "0123456789ABCDEF"[(val >> i) % 16];
}

