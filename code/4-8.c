#include "ch3.h"

int main()
{
	//使用fcntl()  替代dup2进行重定向[4-6.c]
	FILE* fp;
	int fd;
	int newfd;

	fd = open("./out.info", O_CREAT|O_TRUNC|O_WRONLY, 0644);

	//dup2(d1, 1);
	close(1); //先关闭标准输入流
	newfd = fcntl(fd, F_DUPFD, 1);//指定到标准输入流

	printf("Redirect stdout file for 4-8.c!\n");

	return 0;
}
