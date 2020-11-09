#include "../ch8.h"

int main(int argc, char* argv[])
{
	//runtime load now
	void *fpt = dlopen("./libdlib.so", RTLD_NOW);

	if(!fpt){
		printf("dlopen failed!\n");
		exit(1);
	}
	//void (*fp)(void) = dlsym(fpt, "dynamic_lib_fun_call");
	void (*dlmysort)(int*, int) = dlsym(fpt, "mysort");

	if(!dlmysort)
	{
		printf("Dlsym Failed!\n");
		exit(1);
	}

	if(argc <= 1)
	{
		printf("Arguement input is failed!\n");
		exit(1);
	}
	int *a;
	a = (int *)malloc(sizeof(int) * (argc -1));
	for(int i= 0; i < argc -1; i++)
	{
		a[i] = atoi(argv[i + 1]);
		printf("%d " ,a[i]);
	}
	printf("\n");

	dlmysort(a, argc - 1);

	dlclose(fpt);

	return 0;
}
