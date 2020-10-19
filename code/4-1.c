#include "ch3.h"

int main(int argc, char* argv[])
{
	int n, from, to;
	char buf[1024];

	//判断参数个数是否=3
	if(argc != 3) 
	{
		printf("Usage: %s from-file to-file\n", argv[0]);
		exit(1);
	}
	//只读打开文件from
	if((from = open (argv[1],O_RDONLY)) < 0)
	{
		printf("Usage: %s from-file to-file\n", argv[1]);
		exit(1);
		//err_exit(argv[1]);
	}

	//创建打开
	if((to = open(argv[2], O_WRONLY|O_CREAT|O_APPEND, 0644)) < 0)
	{
		printf("Usage: %s from-file to-file\n", argv[0]);
		exit(1);
		//err_exit(argv[2]);
	}
	//写入
	while((n = read(from, buf, sizeof(buf))) > 0)
	{
		write(to, buf, n);
	}

	//关闭文件
	close(from);
	close(to);

	return 0;
}
