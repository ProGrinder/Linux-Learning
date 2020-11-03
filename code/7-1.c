#include"./ch7.h"

static void __attribute__((constructor)) before_main()
{
	printf("--------Before Main---------\n");
}

int main()
{
	printf("--------Main Function---------\n");
	return 0;
}

static void __attribute__((destructor)) before_main()
{
	printf("--------After Main---------\n");
}



