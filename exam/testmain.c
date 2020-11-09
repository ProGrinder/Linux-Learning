#include "my.h"

static void menu()
{
	printf("-------------------------\n");
	printf("1. Input a Record\n");
	printf("2. Add a Random Record\n");
	printf("3. Show the Directory\n");
	printf("4. Show the Directory by Order\n");
	printf("0. exit\n");
	printf("-------------------------\n");
}



int main()
{
	
	char choice;
	recorder* pt = NULL;
	rclist* recorders = NULL;



	printf("Here is a Telephone Directory\n");
	
		
	do
	{
		menu();
		printf("please input your choice: ");
		choice = getc(stdin);
		getc(stdin);

		switch(choice - '0')
		{
			case 1: 
			{
				while(pt == NULL)
				{
					pt = input();
				}
				if(save(pt) == 1)
				{
					printf("保存成功！\n");
				}
				else
				{
					printf("找不到文件！\n");
				}
				break;
			}

			case 2:
			{
				if(save(randdat()) == 1)
				{
					printf("保存成功！\n");
				}
				break;
			}

			case 3:
			{
				recorders  = readFile();
				output(recorders);
				break;
			}
			case 4:
			{
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
				break;
			}

			case 0:
			{
				exit(0);
				break;
			}
			
		}
	}while(1);

    	return 0;
}
