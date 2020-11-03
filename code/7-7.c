#include "ch7.h"

static void set_env_string(void)
{
	char test_nev[]="test_env=test";
	if(putenv(test_nev) != 0)
	{
		printf("Putenv is failed!\n");
	}
	else
	{
		printf("1.The test_env = %s\n", getenv("test_env"));
	}
}
static void show_env_string()
{
	printf("2.The test_env = %s\n", getenv("test_env"));
}

int main()
{
	//作业 为什么第二次null
	set_env_string();
	show_env_string();
	return 0;
}
