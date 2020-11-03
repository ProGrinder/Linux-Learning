#include"../ch7.h"

void dynamic_lib_call(void)
{
	printf("Dynamic lib is called!\n");
}

void dsum(int max)
{
	int sum =0;
	for(int i = 1; i <= max; i++)
	{		
		sum += i;
	}

	printf("sum = %d\n", sum);
}
