#include "ch3.h"

int main()
{
	FILE *fp;

	fp = fopen(".test1.txt","w");
	printf("fd = %d\n", fp->_fileno); //fd封装在结构体fp中
	fclose(fp);

	return 0;
}
