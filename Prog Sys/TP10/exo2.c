#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>

pthread_mutex_t verrou = PTHREAD_MUTEX_INITIALIZER;

void *liberation(void*arg)
{
	printf("Bonjour\n");
	pthread_mutex_lock(&verrou);
	printf("JE SUIS LIBRE\n");
	pthread_mutex_unlock(&verrou);
	printf("Au revoir\n");
	return NULL;
}

int main(int argc, char const *argv[])
{
	int  n = atoi(argv[1]);
	pthread_t threads[n];
	int i;
	pthread_mutex_lock(&verrou);
	for (i = 0; i < n; i++)
	{
		pthread_create(&threads[i],NULL,liberation,NULL);
	}
	scanf("%*c");
	pthread_mutex_unlock(&verrou);

	for (i = 0; i < n; i++)
	{
		pthread_join(threads[i],NULL);

	}

	return 0;
}