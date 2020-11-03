#include "ch7.h"

int main(int argc, char* argv[])
{
	printf("argv[0] = %s\n", argv[0]);
	printf("argv[1] = %s\n", argv[1]);
	printf("argv[2] = %s\n", argv[2]);
	printf("sum = %d\n", atoi(argv[1]) + atoi(argv[2]));
	
	return 0;
}

