#include "ch9.h"

int main()
{
	pid_t i;
	i = vfork();
	if(i < 0)
	{
		perror("Vfork failed!\n");
		exit(-1);
	}
	else if(i == 0)
	{
		printf("child : pid = %d, ppid = %d, i = %d\n",
			       	getpid(), getppid(), i);
		//return 0;
		_exit(0);
	}
	else
	{
		wait(NULL);//自我阻塞，等待任何一个子进程结束
		printf("parent : pid = %d, ppid = %d, i = %d\n",
				getpid(), getppid(), i);
		return 0;
	}
	
}
