#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "shared.h"
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int shmid;

	shmid=shmget((key_t)MEM_CLE,MEM_SIZE,0);
	if(shmid!=-1)
	{
		pid_t clear_pid = fork();
		int status;
		if(clear_pid == 0)
		{
			execlp("./clear","clear",NULL);
		}

		wait(&status);
	}

	int mutex = sem_create(MUTEX_CLE,1);
	sem_create(SEM_CLE,0);
	sem_create(SEM2_CLE,0);
	int flag = 0;

	shmid=shmget((key_t)MEM_CLE,MEM_SIZE,IPC_CREAT|IPC_EXCL|0666);
	if(shmid==-1)
	{
		log_error("La mémoire partagée créée n'existe pas\n");
		exit(1);
	}

	char * mem= shmat(shmid,0,flag);
	if( mem  == (char*)-1)
	{
		log_error("Attachement de la mémoire impossible\n");
		exit(1);
	}

	log_debug("Attente de l'accès à la mémoire\n");
	P(mutex);
	mem[0] = 0;
	mem[1] = 0;
	mem[2] = 0;
	log_debug("Libération de l'accès à la mémoire\n");
	V(mutex);

	log_info("> mémoire partagée: clé: %d, ID: %d\n",(key_t)MEM_SIZE, shmid);

	return 0;
}
