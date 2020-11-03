#include "ch7.h"

int main(int argc, char*argv[], char *env[])
{
	//系统变量--环境变量
	extern char** environ;
	int i;

	for(int i = 0; environ[i]; i++)
	{
		printf("environ[%d] = %s\n", i, environ[i]);
	}

	for(int i =0; env[i] != NULL; i++)
	{
		printf("env[%d] = %s\n", i, env[i]);
	}

	//单个环境变量的获取getenv()
	printf("PATH = %s\n", getenv("PATH"));

	return 0;
}
