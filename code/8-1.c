#include "./ch8.h"

// E L F 格式中变量分布情况

static g = 100, k;
void fun(void)
{
	int x,y;
	int *p = (int*)malloc(sizeof(int) * 1);
	printf("fun : address of x %x, y = %x\n", &x, &y);
	printf("fun : address of p = %x\n", p);
	sleep(10); //sleep让内存空间不立即释放
}


int main()
{
	int i = 0, j = 0, a[10] = { 1 };

	static int w = 100;
	int *pt = (int*)malloc(sizeof(int) * 10);

	printf("address of g = %x, k = %x\n", &g, &k);
	printf("address of i = %x, j = %x, a = %x\n", &i, &j, &a);
	printf("address of w = %x\n", &w);
	printf("address of pt = %x\n", pt);

	fun();

	return 0;
}
