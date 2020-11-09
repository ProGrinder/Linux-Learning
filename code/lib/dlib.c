#include "../ch8.h"

void dynamic_lib_fun_call()
{
	printf("Dynamic Lib Fun Called!\n");
}



int* mysort(int Arr[], int size)
{
	int Counts = size - 1; // 排序总轮数
	for (int i = 0; i < Counts; i++)
	{
		for (int j = 0; j < Counts - i; j++) 
		{
			if (Arr[j] > Arr[j + 1])
			{
				int tmp = Arr[j + 1];
				Arr[j + 1] = Arr[j];
				Arr[j] = tmp;
			}
		}
	}

        //排序后输出元素顺序
	for (int i = 0; i < size; i++)
	{
		printf("%d ", Arr[i]);
	}
	printf("\n");


	return Arr;
}
