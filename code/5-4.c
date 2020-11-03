#include "ch4.h"

int main()
{
	int fd;
	FILE *fp;
	char *s = "Hello World!\n";
	//open只讲速度，不讲效率
	if((fd = open("./test1.txt", O_CREAT|O_WRONLY,0644)) == -1)
	{
		printf("Error to creat file!\n");
		exit(1);
	}
	if((fp = fopen("./test2.txt", "w+")) == NULL)
	{
		printf("Error to create file\n");
		exit(1);
	}

	sleep(15);
	write(fd, s, strlen(s));
	fwrite(s, sizeof(char), strlen(s), fp);
	printf("After write\n");
	sleep(15);
	close(fd);
	fclose(fp);

	return 0;
}