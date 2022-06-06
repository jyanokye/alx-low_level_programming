#include <stdio.h>
/**
 * use putchar function to print thealphabet in lowercase
 */
int main (void)
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
