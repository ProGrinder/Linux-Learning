#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>

#define err_exit(MSG) {\
	printf("USAGE : %s is failed.\n", MSG);\
	exit(1);\
}

#ifndef MY_H
#define MY_H
typedef struct user{
    int id;  //唯一
    char name[8];
    char htel[12];
    char tel[12];
}recorder;

typedef struct userlist{
	int size;
	recorder *r;
}rclist;

recorder* input(void);   //从键盘中接受数据
int save(recorder* pt);    //指针和个数  //input函数中接受的数据追加写入user.dat
rclist* mysort(int type);  //对姓名按用户选择进行排序
void output(rclist* );  //接受其他函数传来的内容，列表方式显示

recorder* randdat();	//随机数据

void release();
rclist* readFile();


#endif
