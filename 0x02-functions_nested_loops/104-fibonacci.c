#include <stdlib.h>
#include <stdio.h>

/**
 * main - print the first 98 fibonacci numbers starting from 1 and 2
 * Return: 0
 */

int main(void)
{
	unsigned long int w;
	unsigned long int f = 1;
	unsigned long int s = 0;
	unsigned long int c;

	for (w = 0; w < 98; w++)
	{
		c = f + s;

		printf("%lu", c);

		if (w < 97)
		{
			printf(",");
			printf(" ");
		}
		s = f;
		f = c;
	}
	printf("\n");
	return (0);
}
