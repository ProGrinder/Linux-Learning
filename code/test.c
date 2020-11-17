#include "ch9.h"

int main(int argc, char* argv[])
{
	extern char** environ;
	char **env = environ;
	int i;
	for(int i = 1; i <argc; i++)
	{
		printf("%s ", argv[i]);
	}

	//printf("\n");
	//printf("以下是环境变量:\n");
	while(*env)
	{
		printf("%s\n", *env);
		env++;
	}
	exit(EXIT_SUCCESS);
	//printf("%s %s", argv[1], argv[2]);
}
