#include "main.h"
/**
 * print_binary - Entry Point
 * @n: dec input
 * Return: 0
 */
void print_binary(unsigned long int n)
{
	int i = 0, con, k, tem;

	if (n == 0)
	{
		printf("0");
		return;
	}

	tem = n;

	while (tem != 0)
	{
		i++;
		tem = tem >> 1;
	}

	for (con = i - 1; con >= 0; con--)
	{
		k = n >> con;
		if (k & 1)
			printf("1");
		else
			printf("0");
	}
}
