#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../lib/djikstra/djikstra.h"

#define CLE_1 1
#define CLE_2 2

void rdv2();

int main(int argc, char const *argv[])
{
	int sem1;
	int sem2;

	sem1 = sem_create(CLE_1, 0);
	printf("Création du sémaphore d'identificateur %d\n",sem1);
	sem2 = sem_create(CLE_2, 0);
	printf("Création du sémaphore d'identificateur %d\n",sem2);

	V(sem2);
	printf("Libération de sem2\n");
	printf("Attente de sem1\n");
	P(sem1);
	rdv2();
	sem_delete(sem1);
	sem_delete(sem2);
	return 0;
}

void rdv2()
{
	printf("Rendez-vous 2\n");
}
