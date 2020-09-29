#include "ch2.h"

int main()
{
	int ret;
	char buf[101];
	int fd;
	memset(buf,0,sizeof(buf));//初始化
	fd = open("./test.data", O_CREAT|O_TRUNC|O_RDWR,0644); //绑定流,不存在则默认创建，存在则清空，给予可读可写权限
	printf("New fule description %d\n", fd);
	printf("%d: 2-3 is running!\n", getpid());
	ret = write(1,"Hello World!\n",13);
	printf("ret = %d\n", ret);

	sleep(10);//睡眠10秒
	printf("PLease input data <=100:\n");
	fgets(buf,100,stdin); //从键盘读取数据到buffer
	ret=write(fd,buf,sizeof(buf)); //将buf内的数据写入到文件
	printf("ret = %d\n", ret);
	exit(0);
}
