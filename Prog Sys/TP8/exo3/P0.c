#include <string.h>
#include "shared.h"
#include <time.h> 

int main(int argc, char const *argv[])
{
	
	int shmid;
	char *mem;
	int flag = 0;

	int mutex = semget(MUTEX_CLE,1,IPC_CREAT|0666);

	int sem1 = semget(SEM_CLE,1,IPC_CREAT|0666);
	int sem2 = semget(SEM2_CLE,1,IPC_CREAT|0666);

	shmid=shmget((key_t)MEM_CLE,MEM_SIZE,0);
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
	int status = 0;
	while(status != -1)
	{
		P(sem2);
		P(sem2);
		P(mutex);
		if(mem[0] > mem[1])
		{
			int inter = mem[0];
			mem[0] = mem[1];
			mem[1] = inter;
		}
		else
		{
			status = -1;
			mem[2] = status;
		}
		V(mutex);
		
	}

	if(shmdt(mem) == -1)
	{
		log_error("Détachement de la mémoire impossible\n");
		exit(1);
	}

	return 0;
}
