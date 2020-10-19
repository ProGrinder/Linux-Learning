#include "ch3.h"

int main()
{
	FILE *fp;
	char buf[80];

	memset(buf,0, sizeof(buf));

	fp = fopen("./test1.txt", "a+");
	fputs("\tappend new infomation!", fp);

	fp = freopen("./test1.txt", "r", fp); //read不存在的文件会出现段错误
	fgets(buf, sizeof(buf),fp);
	printf("Content of file: %s\n", buf);

	fclose(fp);

	return 0;
}
