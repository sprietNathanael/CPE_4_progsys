#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem1;
sem_t sem2;
sem_t sem3;

void *Tache1()
{
	printf("Debut Tache 1\n");
	sleep(1);
	sem_post(&sem1);
	sem_post(&sem1);
	printf("Tache 1 : Je suis là !\n");
	printf("Tache 1 : J'attends 2 !\n");
	sem_wait(&sem2);
	printf("Tache 1 : J'attends 3 !\n");
	sem_wait(&sem3);
	printf("Fin Tache 1\n");
	return NULL;
}

void *Tache2()
{
	printf("Debut Tache 2\n");
	sleep(2);
	sem_post(&sem2);
	sem_post(&sem2);
	printf("Tache 2 : Je suis là !\n");
	printf("Tache 2 : Je suis là !\n");
	printf("Tache 2 : J'attends 3 !\n");
	sem_wait(&sem3);
	printf("Tache 2 : J'attends 1 !\n");
	sem_wait(&sem1);
	printf("Fin Tache 2\n");
	return NULL;	
}

void *Tache3()
{
	printf("Debut Tache 3\n");
	sleep(3);
	sem_post(&sem3);
	sem_post(&sem3);
	printf("Tache 3 : Je suis là !\n");
	printf("Tache 3 : Je suis là !\n");
	printf("Tache 3 : J'attends 1 !\n");
	sem_wait(&sem1);
	printf("Tache 3 : J'attends 2 !\n");
	sem_wait(&sem2);
	printf("Fin Tache 3\n");
	return NULL;	
}

int main()
{
	pthread_t th1, th2, th3;

	sem_init(&sem1, 0,0);
	sem_init(&sem2, 0,0);
	sem_init(&sem3, 0,0);


	if(pthread_create(&th1,NULL,Tache1,NULL)==0){
		if(pthread_create(&th2,NULL,Tache2,NULL)==0)
		{
			if(pthread_create(&th3,NULL,Tache3,NULL)==0)
			{
				pthread_join(th1,NULL);
				pthread_join(th2,NULL);
				pthread_join(th3,NULL);
				
				return 0;
			}
		}
	}
	return 1;
}