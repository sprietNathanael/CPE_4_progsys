#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/shm.h>


void *traitement(void *arg)
{
	char* path = (char *)arg;

	FILE *fp1,*fp2;
	int  c = '\0';

	fp1 = fopen(path,"r"); 
	fp2 = fopen(path,"r+");


	if((fp1==NULL)||(fp2==NULL))
	{
		perror("fopen");
		exit(1);
	}
	

	while(c!=EOF){
		c=fgetc(fp1);
		if(c!=EOF)fputc(toupper(c),fp2);
	}


	fclose(fp1);
	fclose(fp2);


	return NULL;
}

int main(int argc, char **argv)
{
	int i;
	pthread_t threads[argc-1];

	for (i = 0; i < argc-1; i++)
	{
		printf("%s\n",argv[i+1]);
		pthread_create(&threads[i],NULL,traitement,(void *)argv[i+1]);
	}

	for (i = 0; i < argc-1; i++)
	{

		pthread_join(threads[i], NULL);

	}
	return 0;
}