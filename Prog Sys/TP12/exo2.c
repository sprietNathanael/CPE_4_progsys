#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/shm.h>

pthread_mutex_t verrou = PTHREAD_MUTEX_INITIALIZER;

typedef struct threadMessage{
	int index;
	int max;
	char **files;	
} ThreadMessage;

void *traitement(void *arg)
{
	ThreadMessage* message = (ThreadMessage*)arg;

	while(message->index < message->max-1)
	{
		pthread_mutex_lock(&verrou);

		FILE *fp1,*fp2;
		int  c = '\0';
		printf("%s\n",message->files[message->index]);
		printf("debut fopen\n");

		fp1 = fopen(message->files[message->index],"r"); 
		printf("fopen1 passe\n");
		fp2 = fopen(message->files[message->index],"r+");
		printf("fopen2 passe\n");
		message->index++;

		pthread_mutex_unlock(&verrou);

		if((fp1==NULL)||(fp2==NULL))
		{
			perror("fopen");
			exit(1);
		}
		

		printf("while\n");
		while(c!=EOF){
			c=fgetc(fp1);
			if(c!=EOF)fputc(toupper(c),fp2);
		}


		printf("close\n");
		fclose(fp1);
		fclose(fp2);
		printf("closed\n");
	}


	return NULL;
}

int main(int argc, char **argv)
{
	int i;
	int threadNumber = 2;
	pthread_t threads[threadNumber];

	ThreadMessage message;
	message.index = 1;
	message.max = argc;
	message.files = argv;

	for (i = 0; i < threadNumber; i++)
	{
		pthread_create(&threads[i],NULL,traitement,(void *)&message);
	}

	for (i = 0; i < threadNumber; i++)
	{

		pthread_join(threads[i], NULL);

	}
	return 0;
}