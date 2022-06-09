#include "main.h"
/**
 * print_alphabet_x10 - print alphabet in lowercase 10 times
 * Return: 0
 */
void print_alphabet_x10(void);
int main()
{
	int i = 0;
        char c;

	while (i < 10)
	{
	c = 'a';
	while(c <= 'z')
	{
	putchar(c);
	c++;
	}
	putchar('\n');
	i++;
	}
}
