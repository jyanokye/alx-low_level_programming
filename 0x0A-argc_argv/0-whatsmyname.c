#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - main block
 * @argc: number of command line arguments
 * @argv: array of pointers to strings
 * Return: 0
 */

int main(int argc, char **argv)
{
	(void) argc;

	printf("%s\n", *argv);
	return (0);
}
