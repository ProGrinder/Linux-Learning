#include "../ch7.h"

//extern void dynamic_lib_call(void);
int main(int argc, char* argv[])
{
	//dynamic_lib_call();
	void *dlib=dlopen("./libdlib.so", RTLD_NOW);
	if(!dlib)
	{
		printf("dlopen failed!\n");
		exit(-1);
	}
	else
	{
		
		void(*dfunc)(void)=dlsym(dlib,"dynamic_lib_call");
		void(*dfunc2)(int) = dlsym(dlib,"dsum");
		if(!dfunc)
		{
			printf("dfunc is failed!\n");
			exit(-1);
		}
		else
		{
			dfunc();
		}

		if(!dfunc2)
		{
			printf("dfunc2 is failed!\n");
			exit(-1);
		}
		else
		{
			if(argc != 2)
			{
				printf("Arguement input is failed!\n");
			}
			else
			{
				int a = atoi(argv[1]);
				dfunc2(a);
			}
			
		}
	
		dlclose(dlib);
	}

	return 0;
}
