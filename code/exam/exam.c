#include "./ch9.h"

int g = 0;
pid_t pid[2];

int main() {
	int i, j;

	FILE *fp;
	fp = fopen("./out.dat", "w+");
	
	for (i = 0; i < 2; i++) {
		pid[i] = fork();
		
		if (pid[i] == 0) {
			printf("I am %d, my parent is %d\n", getpid(), getppid());
			//g++;
			//fprintf(fp, "%d: g = %d\n", getpid(), g);

			if (i == 0) {

					for (j = 0; j < 2; j++) {
						 pid[j] = fork();
						 if (pid[j] == 0) {
							 g++;
							 fprintf(fp, "%d: g = %d\n", getpid(), g);
							 printf("I am %d, my parent is %d\n", getpid(), getppid());
							 exit(0);
						 }
					 }

					 for(j = 0;j < 2; ++j) {
             			   		waitpid(pid[j],NULL,0);
            				 }

      
			}
			g++;
			fprintf(fp, "%d: g = %d\n", getpid(), g);

			exit(0);
		}

	}

	for (i = 0; i < 2; i++) {
		waitpid(pid[i], NULL, 0);
	}

	printf("I am parent %d\n", getpid());
	g++;
	fprintf(fp, "%d: g = %d\n", getpid(), g);
	return 0;
}
