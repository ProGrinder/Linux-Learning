#include "ch7.h"

/*
putenv函数：
putenv 函数会将参数 string 直接填写到环境表中，不会再为 "name=value" 这个字符串再去分配内存。如果是在一个函数中定义的string，那么在调用该函数后，string 指向的内容可能会被释放，就找不到name环境变量的值了。
setenv 函数：
setenv 函数和 putenv 函数不同，它会将name和value指向的内容复制一份并为其分配内存，形成 "name=value" 的字符串，并将其地址写入到环境表中。所以就不会出现上面putenv 的情况，就算函数返回了，name 和 value指向的内容被释放了，仍然有一份拷贝在。
*/

static void set_env_string(void)
{
	//char test_env[]="test_env=test";
	char test_env[]="test";

	//使用setenv即可
	if(setenv("test_env", test_env, 0) != 0)
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
	//解决 为什么第二次null
	set_env_string();
	show_env_string();
	return 0;
}
