#include "main.h"

/**
 * print_alphabet_x10 - Prints all the aphabets  in small letters ten times
 */

void print_alphabet_x10(void)
{
	char c;
	int t;

	c = 'a';
	f = 0;
	
	do {
							
	for (c = 'a'; c <= 'z'; c++)
	{
	_putchar(c);
	}
	_putchar('\n');

	++f;
	} while (f < 10);

}
