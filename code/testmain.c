#include "ch3.h"

int main(int argc, char *argv[])
{
	int i;
	for(int i = 0; i < argc; i++)
	{
		printf("[%d]: %s\n", i , argv[i]);
	}

}