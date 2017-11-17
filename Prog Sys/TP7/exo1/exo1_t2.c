#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../lib/djikstra/djikstra.h"

#define CLE 1

int main(int argc, char const *argv[])
{
	int sem;
	sem = sem_create(CLE, 0);
	printf("Création du sémaphore d'identificateur %d\n",sem);
	printf("je suis T2 et j'attends que le sémaphore soit libre\n");
	P(sem);
	printf("Le sémaphore est libre, je travaille\n");
	sleep(5);
	sem_delete(sem);
	return 0;
}
