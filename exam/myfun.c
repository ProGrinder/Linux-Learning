#include "my.h"

rclist *recorders = NULL;  


void release() {
	if (!recorders) {
		recorders = (rclist *) malloc(sizeof(rclist));
		recorders->r = NULL;
	}
	if (recorders->r) free(recorders->r);
	recorders->size = 0;
	recorders->r = NULL;
}



rclist* readFile()
{
	int cnt = 0;
	int tempid;
	char tempstr[15];
	FILE* fp = NULL;

	fp = fopen("./user.dat","r+");
	if(fp == NULL)
	{
		printf("open failed!\n");
        	exit(-1);
	}
	
	//初始化
	release();

	while(fscanf(fp, "%d %s %s %s\n", &tempid, tempstr,tempstr,tempstr) !=EOF)
	{
		cnt++;
	}

	recorders->size = cnt;

	recorders->r = (recorder* )malloc(sizeof(recorder) * (recorders->size));

	//回到开头
	fseek(fp, 0 ,SEEK_SET);
	for(int i = 0; i < recorders->size; i++){
		fscanf(fp,"%d %s %s %s\n",
			&(recorders->r)[i].id,
			(recorders->r)[i].name,
			(recorders->r)[i].htel,
			(recorders->r)[i].tel);
	}

	fclose(fp);
		
	return recorders;
}



recorder* input(void)
{
	FILE* fp = NULL;
	fp = fopen("./user.dat", "rb");
	if(fp == NULL)
	{
		printf("open failed!\n");
		exit(-1);
	} 	
	
    	recorder *pt;

    	pt = (struct user*)malloc(sizeof(struct user));  	

    	//提示输入
    	printf("请分别输入id[唯一], name, htel, tel:\n");

	scanf("%d",  &(pt->id));
	scanf("%s", pt->name);
	scanf("%s", pt->htel);
	scanf("%s", pt->tel);

	int tempid;
	char tempstr[15];
	
	while(fscanf(fp, "%d %s %s %s\n", &tempid, tempstr,tempstr,tempstr) !=EOF)
	{
		if(pt->id == tempid)
		{
			printf("该Id: %d 已存在.\n", tempid);
			fclose(fp);
			free(pt);
			return NULL;
		}
	}
	
	fclose(fp);

	return pt;
}


int save(recorder* pt)
{
	FILE *fp = NULL;

	if((fp = fopen("./user.dat","a+")) == NULL){
		perror("Open failed!\n");
		return -1;
	}
	
	fprintf(fp,"%d %s %s %s\n", pt->id, pt->name,pt->htel,pt->tel);

	fclose(fp);
	
	return 1;
}

//升序
int cmp1(const void *a, const void *b) {
    	return strcmp(((recorder* )a)->name, ((recorder* )b)->name) > 0 ? 1 : -1;
}
//降序
int cmp2(const void *a, const void *b) {
    	return strcmp(((recorder* )a)->name, ((recorder* )b)->name) > 0 ? -1 : 1;
}


rclist* mysort(int type) {

	readFile();

	if(type == 1)
	{
		qsort(recorders->r, recorders->size, sizeof(struct user), cmp1);
	}
	else if(type == 2)
	{	
		qsort(recorders->r, recorders->size, sizeof(struct user), cmp2);
	}
	else{
		return NULL;
	}


	return recorders;
}


//输出
void output(rclist* recorders)
{
	printf("%5s %8s %12s %12s\n", "userid", "name", "htel", "tel");
	for(int i = 0; i < recorders->size ; i++)
	{
		printf("%5d %8s %12s %12s\n",
			recorders->r[i].id,
			recorders->r[i].name,
			recorders->r[i].htel,
			recorders->r[i].tel);
	}
}


recorder* randdat()
{
	FILE *fp = fopen("./user.dat", "a+");

	recorder* pt = (struct user*)malloc(sizeof(struct user)); 


	srand(time(NULL));
	//id随机
	pt->id = rand();


	//name随机
	int namelen = rand() % 7 + 1; //获得>1位的名字长度
	for (int i = 0; i < namelen; i++) 
	{
        	pt->name[i] = (char)(rand() % 26 + 'a'); 
        	if (i == 0) pt->name[i] -= 32;//首字母大写
    	}
	pt->name[namelen] = '\0';

	
	//htel随机
	char qcode[2];	//区号
	qcode[0] = (char)(rand()%10 + '0');
	qcode[1] = '-';
	strncpy(pt->htel, qcode, 2);
	for(int i = 2; i < 11; i++)
	{
		pt->htel[i] = (char)(rand()%10 + '0');
	}
	pt->htel[11] = '\0';


	//tel随机
	char telnum_pre [4][3] = {"138","130","133","131"};
	strncpy(pt->tel, telnum_pre[rand() % 4], 3);
	for (int i = 3; i < 11; i++) 
	{
        	pt->tel[i] = (char)(rand() % 10 + '0');
    	}
	pt->tel[11] = '\0';

	printf("随机数据为:\n");
	printf("%5d %8s %12s %12s\n", pt->id, pt->name,pt->htel,pt->tel);

	fclose(fp);

	return pt;
}


