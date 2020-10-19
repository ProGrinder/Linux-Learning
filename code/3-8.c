#include "ch3.h"

int main()
{
	FILE* fp;

	fp = fdopen(1, "w+");//指向标准输入流添加
	fprintf(fp, "test data %s\n", "hello world!");

	fclose(fp);

	return 0;
}
