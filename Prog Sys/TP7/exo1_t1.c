#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "djikstra/djikstra.h"

#define CLE 1

int main(int argc, char const *argv[])
{
	int sem;
	sem = sem_create(CLE, 0);
	printf("Création du sémaphore d'identificateur %d\n",sem);
	printf("je suis T1 et je travaille\n");
	sleep(5);
	printf("je libère le sémaphore\n");
	V(sem);
	return 0;
}