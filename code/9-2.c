#include "ch9.h"
int g = 1;

int main()
{
	pid_t pid;
	int l = 99;
	int *pt = malloc(sizeof(int));
	char *string = "test String!";
	*pt = 9999;

	printf("-----Before Fork-----");   //不能加\n，\n会立刻结束缓冲区,就复制不到子进程了
	pid = fork();
	if(pid < 0)
	{
		fprintf(stderr, "failed to fork. Reason(%s)\n", strerror(errno));
		exit(-1);
	}
	else if(pid == 0)
	{
		printf("child : pid = %d, ppid = %d, return from fork() = %d \n",
			        getpid(), getppid(), pid);
		printf("child : init g = %d, l = %d, *pt = %d\n", g, l, *pt);
		g++;
		l++;
		(*pt)++;
		/*地址是一样的，但改变值是独立的*/
		printf("child : g = %d   %x, l = %d   %x, *pt = %d   %x\n", g, &g, l,&l, *pt, pt);
		printf("string is %s\n", string);
	}
	else
	{
		sleep(2);
		printf("parent : pid = %d, ppid = %d return from fork() = %d \n",
				getpid(), getppid(), pid);
		printf("parent : init g = %d, l = %d, *pt = %d\n", g, l, *pt);
		g++;
		l++;
		(*pt)++;
		printf("parent : g = %d   %x, l = %d   %x, *pt = %d   %x\n", g, &g, l,&l, *pt, pt);
		printf("string is %s\n", string);
		return 0;
	}
}
