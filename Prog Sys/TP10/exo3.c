#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>

pthread_mutex_t verrou = PTHREAD_MUTEX_INITIALIZER;


void *Tache1()
{
	printf("Debut Tache 2\n");
	pthread_mutex_lock(&verrou);
	printf("Traitement tache 2\n");
	printf("Fin Traitement tache 2\n");
	printf("Fin Tache 2\n");
	return NULL;
}

void *Tache2()
{
	printf("Debut Tache 1\n");
	printf("traitement Tache 1\n");
	sleep(1);
	printf("Fin traitement Tache 1\n");
	pthread_mutex_unlock(&verrou);
	printf("Fin Tache 1\n");
	return NULL;	
}


int main()
{
	pthread_t th1, th2;
	pthread_mutex_lock(&verrou);

	pthread_create(&th1,NULL,Tache1,NULL);
	pthread_create(&th2,NULL,Tache2,NULL);

	pthread_join(th1,NULL);
	pthread_join(th2,NULL);

	return 0;
}