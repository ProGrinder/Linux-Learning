#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <dlfcn.h>
#include <setjmp.h>
#include <wait.h>
#include <errno.h>

#define INFILE "./in.txt"
#define OUTFILE "./out.txt"
#define MODE 664
void err_exit(char* s) {
	printf("USAGE : %s is failed.\n", s);
	exit(1);
}
