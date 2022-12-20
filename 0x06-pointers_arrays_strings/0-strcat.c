#include <stdio.h>

int main(void)
{
	int s;
	int b[5];
	int *r;
	b[2] = 102;
	r = &s;
	*(r + 5) = 98;
	printf("b[2] = %d\n", b[2]);
	return (0);
}
