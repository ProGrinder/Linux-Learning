#include "ch3.h"

int main(int argc,char* argv[])
{
	FILE *fp;

	if((fp = fopen("./test1.txt","w")) == NULL)
	{
		perror("open failed!\n");
		return 0;
	}

	printf("You input Content is: \n");
	for(int i = 1; i< argc; i++)
	{
		fprintf(fp,"%s", argv[i]);
		//fwrite(argv[i],1 ,strlen(argv[i]), fp);
		printf("[%d]:\t%s \t %ld bytes\n", i , argv[i], strlen(argv[i]));
	}

	fprintf(fp, "\n");

	fclose(fp);
	return 0;
}
