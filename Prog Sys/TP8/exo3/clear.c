#include "shared.h"

struct shmid_ds buf;

int main()
{
	int shmid;
	int shmctl_ret;

	int mutex = semget(MUTEX_CLE,1,IPC_CREAT|0666);

	int sem1 = semget(SEM_CLE,1,IPC_CREAT|0666);
	int sem2 = semget(SEM2_CLE,1,IPC_CREAT|0666);



	shmid=shmget((key_t)MEM_CLE,MEM_SIZE,0);
	if(shmid==-1)
	{
		log_warning("La mémoire partagée n'existe pas\n");
		exit(1);
	}
	shmctl_ret = shmctl(shmid,IPC_RMID,NULL);
	if(shmctl_ret==-1)
	{
		log_error("La mémoire partagée ne peut être détruite\n");
		exit(1);
	}

	log_info("> mémoire partagée supprimée: clé: %d, ID: %d\n",(key_t)MEM_CLE, shmid);
	sem_delete(mutex);
	sem_delete(sem1);
	sem_delete(sem2);
	log_debug("Supression des sémaphores\n");

	return 0;
}
