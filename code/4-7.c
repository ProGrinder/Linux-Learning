#include "ch3.h"

int main()
{
	//fdopen 和fileno
	FILE *fp;
	int fd;

	fp = fopen("./ch3.h","r");
	fd = fileno(fp);

	printf("fd = %d\n", fd);

	fclose(fp);

	return 0;
}
