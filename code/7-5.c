#include "ch7.h"

static void __attribute__((constructor))before_main()
{
	printf("--------Before Main---------\n");
}

static void __attribute__((destructor))after_main()
{
	printf("--------After Main---------\n");
}


static void callback1(void)
{
	printf("--------CallBack1---------\n");
}

static void callback2(void)
{
	printf("--------CallBack2---------\n");
}

static void callback3(void)
{
	printf("--------CallBack3---------\n");
}

int main(void)
{
	atexit(callback1);
	atexit(callback2);
	atexit(callback3);
	printf("--------Main Exit----------\n");
	return 0;
	//exit(0);
	//_exit(0);
}
