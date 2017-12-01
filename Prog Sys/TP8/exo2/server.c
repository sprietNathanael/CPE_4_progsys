#include "shared.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	
	int shmid;
	char *mem;
	int flag = 0;
	int id;

	if(argc < 2)
	{
		log_warning("Aucun argument passé en paramètre\n");
		exit(1);
	}

	int sem_server = semget(SERVER_CLE,1,IPC_CREAT|0666);
	int mutex = semget(MUTEX_CLE,1,IPC_CREAT|0666);

	shmid=shmget((key_t)SERVER_CLE,SERVER_NUMBER,0);
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

	P(mutex);
	id = mem[0];
	mem[0]++;
	V(mutex);

	log_info("Bonjour je suis le server %d\n",id);
	if(id == SERVER_NUMBER-1)
	{
		P(mutex);
		mem[0] = 0;
		V(mutex);
		V(sem_server);
	}
	else
	{
		P(sem_server);
		V(sem_server);
	}

		
	log_info("Je suis %d et je travaille\n",id);
	execlp(argv[1],argv[1], NULL);

	if(shmdt(mem) == -1)
	{
		log_error("Détachement de la mémoire impossible\n");
		exit(1);
	}

	
	return 0;
}