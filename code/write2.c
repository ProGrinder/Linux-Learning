#include "ch3.h"

int main()
{
	int n,i;
	int fd;
	char buf;

	//证明同时写一个文件共享
	fd = open("./test.dat", O_CREAT|O_TRUNC|O_WRONLY, 0644);
	for(int i = 0; i < 2; i++)
	{
		srand(time(0)); //设置随机种子
		n = rand() % 26;

		buf = (char)('A' + n); 
		write(fd, &buf, 1);

		lseek(fd, 10, SEEK_SET);
		sleep(27);
	}

	close(fd);

	return 0;
}
