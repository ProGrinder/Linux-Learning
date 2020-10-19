#include "ch3.h"

int main(int argc,char* argv[])
{
	FILE *fp;

	if((fp = fopen("./test1.txt","w")) == NULL)
	{
		perror("open failed!\n");
		return 0;
	}

	printf("You input Content is: \n");
	for(int i = 1; i< argc; i++)
	{
		fwrite(argv[i],1 ,strlen(argv[i]), fp);
		//为什么不直接用 fwrite(argv, 1, sizeof(argv), fp); ？
		/* 
			要注意argv和buf不同,argv是数组指针
			sizeof(argv)得到的是数组大小 = 数据类型 * argc,
			而strlen(argv[i])得到的才是真正的字符串bytes
			
			系统给的argv不好用memset初始化
		*/
		printf("[%d]:\t%s \t %ld bytes\n", i , argv[i], strlen(argv[i]));
	}
	
	fprintf(fp, "\n");

	fclose(fp);
	return 0;
}
