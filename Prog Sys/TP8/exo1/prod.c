#include <string.h>
#include "shared.h"

int main(int argc, char const *argv[])
{
	if(argc < 2)
	{
		log_warning("Aucun argument passé en paramètre\n");
		exit(1);
	}
	int shmid;
	char *mem;
	int flag = 0;

	int mutex = semget(MUTEX_CLE,1,IPC_CREAT|0666);

	int sem_prod = semget(SEM_PROD_CLE,1,IPC_CREAT|0666);
	int sem_conso = semget(SEM_CONSO_CLE,1,IPC_CREAT|0666);

	shmid=shmget((key_t)SHM_CLE,SIZE_BUFFER,0);
	if(shmid == -1)
	{
		log_warning("La mémoire partagée n'existe pas\n");
		exit(1);
	}

	mem= shmat(shmid,0,flag);
	if( mem  == (char*)-1)
	{
		log_error("Attachement de la mémoire impossible\n");
		exit(1);
	}

	log_debug("Attente d'un sem_prod\n");

	P(sem_prod);

	log_debug("Attente de l'accès à la mémoire\n");
	P(mutex);
	int curIndex = mem[0];
	if(curIndex == SIZE_BUFFER)
	{
		curIndex = SIZE_BUFFER-ENTRY_MAX_LEN;
	}
	mem[curIndex] = *argv[1];
	mem[0] = curIndex+1;
	log_debug("Liberation de l'accès à la mémoire\n");
	V(mutex);

	log_debug("Liberation de sem_conso\n");
	V(sem_conso);

	if(shmdt(mem) == -1)
	{
		log_error("Détachement de la mémoire impossible\n");
		exit(1);
	}

	return 0;
}
