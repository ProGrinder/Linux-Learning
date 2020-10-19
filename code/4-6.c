#include "ch3.h"

int main()
{
	int d1;
	d1 = open("./out.info", O_CREAT|O_TRUNC|O_WRONLY, 0644);

	//dup2指向标准输出1 => 屏幕
	dup2(d1, 1);//通过dup2进行输出重定向,屏幕重定向到out.info文件
	//d1 = dup(STDOUT_FILENO);

	printf("Redirect stdout file for 4-6.c!\n");

	return 0;
}
