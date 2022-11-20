#include <stdio.h>
#include <stdlib.h>

/**
 * main - main block which contains functions and libraries
 * Documentation: Prints all possible combinations of single digit numbers
 *Return: 0
 */

int main(void)
{
int b = 0;
while (b < 10)
{
putchar(b + '0');
if (b < 9)
{
putchar(44);
putchar(32);
}
i++;
}
putchar('\n');
return (0);
}
