#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>
#include <semaphore.h>

#define N 10
#define P(sem) sem_wait(sem)
#define V(sem) sem_post(sem)

sem_t semProd;
sem_t semConso;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
typedef struct prodcons{
	int prodIndex;
	int consoIndex;
	int buffer[N];

	int prodId;
	int consoId;	
} ProdCons;


void *prod(void *arg)
{
	
	int toWrite = 0;
	int id = prodId++;
	while(1)
	{
		// printf("PROD : Attente d'un jeton producteur\n");
		P(&semProd);
		// printf("PROD : Attente de l'accès buffer\n");
		pthread_mutex_lock(&lock);
		buffer[prodIndex++] = toWrite++;
		// printf("PROD : Libération de l'accès buffer\n");
		pthread_mutex_unlock(&lock);
		printf("P%d : Ecrit : %d\n",id, toWrite-1);
		// printf("PROD : Libération d'un jeton consommateur\n");
		V(&semConso);
		if(prodIndex >= N)
		{
			prodIndex = 0;
		}
	}
	
	return NULL;
}

void *conso(void *arg)
{
	int toRead;
	int id = consoId++;
	while(1)
	{
		// printf("CONSO : Attente d'un jeton consommateur\n");
		P(&semConso);
		// printf("CONSO : Attente de l'accès buffer\n");
		pthread_mutex_lock(&lock);
		toRead = buffer[consoIndex++];
		// printf("CONSO : Libération de l'accès buffer\n");
		pthread_mutex_unlock(&lock);
		printf("C%d : Lu : %d\n", id, toRead);
		sleep(1);
		// printf("CONSO : Libération d'un jeton producteur\n");
		V(&semProd);
		if(consoIndex >= N)
		{
			consoIndex = 0;
		}
	}
	return NULL;
}

int main(int argc, char const *argv[])
{
	int nConso = atoi(argv[1]);
	int nProd = atoi(argv[2]);
	pthread_t consommateurs[nConso];
	pthread_t producteurs[nProd];
	pthread_mutex_lock(&lock);
	sem_init(&semProd, 0, N);
	sem_init(&semConso, 0, 0);
	pthread_mutex_unlock(&lock);
	int i;

	int prodId = 0;
	int consoId = 0;
	int prodIndex = 0;
	int consoIndex = 0;

	ThreadData threadMessage;
	threadMessage.



	for(i = 0; i < nConso; i++)
	{
		pthread_create(&consommateurs[i],NULL,conso,(void *)threadMessage);
	}

	for(i = 0; i < nProd; i++)
	{
		pthread_create(&producteurs[i],NULL,prod,(void *)threadMessage);
	}

	for(i = 0; i < nConso; i++)
	{
		pthread_join(&consommateurs[i],NULL);
	}

	for(i = 0; i < nProd; i++)
	{
		pthread_join(&producteurs[i],NULL);
	}
	return 0;
}