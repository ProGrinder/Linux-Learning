#include "ch4.h"

int main()
{
	//流设置为无缓冲，缓冲区
	setvbuf(stdout, NULL ,_IONBF, 0);

	printf("hello world!");
	while(1)
	{
	}

	return 0;
}
