#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - main - block
 * This program prints the alphabets in reverse
 * Return: 0
 */

int main(void)
{
char h = 'z';

while (h >= 'a')
{
putchar(h);
h--;
}	
putchar('\n');
return (0);
}
