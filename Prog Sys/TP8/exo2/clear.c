#include "shared.h"

struct shmid_ds buf;

int main()
{
	int shmid;
	int shmctl_ret;

	int mutex = semget(MUTEX_CLE,1,IPC_CREAT|0666);

	int sem_server = semget(SERVER_CLE,1,IPC_CREAT|0666);



	shmid=shmget((key_t)SERVER_CLE,SERVER_NUMBER,0);
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

	log_info("> mémoire partagée supprimée: clé: %d, ID: %d\n",(key_t)SERVER_CLE, shmid);
	sem_delete(mutex);
	sem_delete(sem_server);
	log_debug("Supression des sémaphores\n");

	return 0;
}
