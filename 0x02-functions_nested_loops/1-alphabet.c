#include "main.h"
/**
 * print_alphabet - Print alphabet in lowercase using only '_putchar'
 * Return: 0
 */
void print_alphabet(void)
{
	char c = 'a';

	while (c <= 'z')
	{
	putchar(c);
	c++;
	}
	putchar('\n');

	return (0);
}
