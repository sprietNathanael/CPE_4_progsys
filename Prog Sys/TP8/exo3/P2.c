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

	int array[ARRAY_SIZE];
	srand(time(NULL));
	for(int i = 0; i < ARRAY_SIZE; i ++)
	{
		array[i] = rand();
	}

	P(mutex);
	status = mem[2];
	V(mutex);
	while(status != -1)
	{
		min = array[0];
		minIndex = 0;
		for(int i = 0; i < ARRAY_SIZE; i++)
		{
			if(array[i] < min)
			{
				min = array[i];
				minIndex = i; 
			}
		}
		P(mutex);
		mem[0] = min;
		V(mutex);
		V(sem2);
		P(sem1);
		status = mem[2];
	}

	P(mutex);
	for(int i = 0; i < ARRAY_SIZE; i++)
	{
		printf("P1 : %d",array[i]);
	}
	printf("\n");
	V(mutex);

	if(shmdt(mem) == -1)
	{
		log_error("Détachement de la mémoire impossible\n");
		exit(1);
	}

	return 0;
}
