#include "holberton.h"
/**
 * flip_bits - Entry Point
 * @n: input
 * @m: bits
 * Return: 0
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int con = 0;

	while (n != 0 || m != 0)
	{
		if ((n & 1) != (m & 1))
			con++;
		m = m >> 1;
		n = n >> 1;
	}

	return (con);

}
