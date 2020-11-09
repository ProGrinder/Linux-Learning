#include "./ch8.h"

int count = 1;

void stack()
{
	int a = 10, b  = 10;
	printf("local a = %x, b = %x, count = %d\n", &a, &b, count);
	count++;
	stack();
}


int main()
{
	stack();

	return 0;
}
