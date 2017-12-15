#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>

#define MAX 40


void *affCompt(void *arg)
{
	int *compteur = (int *) arg;
	int i = 0;

	for(i = 0; i < MAX-1;i++)
	{
		*compteur = *compteur + 1;
		usleep(10);
	}
	return NULL;
}

void *consommateur(void *arg)
{
	int *compteur = (int *) arg;
	while(*compteur < MAX-1)
	{
		printf("%d\n",*compteur);
		usleep(1);
	}
	return NULL;
}

int main()
{
	pthread_t thread_1, thread_2;
	int compt = 0;

	pthread_create(&thread_1,NULL,affCompt,&compt);
	pthread_create(&thread_2,NULL,consommateur,&compt);


	pthread_join(thread_1,NULL);
	pthread_join(thread_2,NULL);



	return 0;
}