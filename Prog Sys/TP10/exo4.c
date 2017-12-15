#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>

pthread_mutex_t arriveA = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t arriveB = PTHREAD_MUTEX_INITIALIZER;

void *Tache1()
{
	printf("Debut Tache 1\n");
	pthread_mutex_unlock(&arriveA);
	pthread_mutex_lock(&arriveB);
	printf("Fin Tache 1\n");
	return NULL;
}

void *Tache2()
{
	printf("Debut Tache 2\n");
	pthread_mutex_unlock(&arriveB);
	pthread_mutex_lock(&arriveA);
	printf("Fin Tache 2\n");
	return NULL;	
}

int main()
{
	pthread_t th1, th2;
	pthread_mutex_lock(&arriveA);
	pthread_mutex_lock(&arriveB);

	if(pthread_create(&th1,NULL,Tache1,NULL)==0){
		if(pthread_create(&th2,NULL,Tache2,NULL)==0)
		{
			pthread_join(th1,NULL);
			pthread_join(th2,NULL);
			return 0;
		}
	}
	return 1;
}