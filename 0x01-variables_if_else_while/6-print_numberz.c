#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - main block
 * This program prints all single digits numbers in base ten starting from zero
 * Return: 0
 */

int main(void)
{
int b = '0';

while (b <= '9')
{
putchar(b);
b++;
}
putchar('\n');
return (0);
}
