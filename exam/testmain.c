#include "my.h"

static void menu()
{
	printf("-------------------------\n");
	printf("1. Input a Record\n");
	printf("2. Add a Random Record\n");
	printf("3. ");
	printf("0. exit");
}



int main()
{
	/*
	char choice;

	recorder *r = NULL;


	printf("-------Here is a Telephone Directory-------\n");
	*/
	
    	recorder* pt = NULL;
	rclist* recorders = NULL;
    	
  	//
	while(pt == NULL)
	{
		pt = input();
	}
	
	save(pt);

	printf("save 成功!");
    	
	recorders  = readFile();
	printf("read 成功!");
 	//输出测试
	output(recorders);

	
	//排序测试
	int type;
	while(1)
	{
		printf("请输入排序方法(1-升序 2-降序): ");
		scanf("%d", &type);
		if(type == 1 || type == 2)
		{
			break;
		}
	}

	output(mysort(type));


	//随机生成数据	
	randdat();
	
	
    	return 0;
}
