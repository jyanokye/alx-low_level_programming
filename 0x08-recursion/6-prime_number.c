#include "main.h"

int _sqrt(int x, int i);
int james(int a, int b);

/**
 * is_prime_number -  returns 1 if the input integer is a prime number,
 * otherwise return 0.
 * @n: number to be checked
 * Return: 1 if prime, 0 if otherwise
 */

int is_prime_number(int n)
{
	if (n < 2)
		return (0);
	if (n < 4)
		return (1);
	return (james(n, 2));
}

/**
 * _sqrt - return square root of number
 * @x: number
 * @i: number incrementer acting as divisor
 * Return: square root of `x`
 */

int _sqrt(int x, int i)
{
	int square;
	
	square = i * i;
	if (square >= x)
		return (i);
	else
		return (_sqrt(x, i + 1));
}

/**
 * james - helper function, recursive steps taken
 * @a: number given to original function is_prime_number
 * @b: incrementer divisor
 * Return: 0 if not prime, 1 if prime
 */

int james(int a, int b)
{
	if (a % b == 0)
		return (0);
	else if (_sqrt(a, 1) < b)
		return (1);
	else
		return (james(a, b + 1));
}
