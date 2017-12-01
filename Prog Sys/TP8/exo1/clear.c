#include "shared.h"

struct shmid_ds buf;

int main()
{
	int shmid;
	int shmctl_ret;

	int mutex = semget(MUTEX_CLE,1,IPC_CREAT|0666);

	int sem_prod = semget(SEM_PROD_CLE,1,IPC_CREAT|0666);
	int sem_conso = semget(SEM_CONSO_CLE,1,IPC_CREAT|0666);


	shmid=shmget((key_t)SHM_CLE,SIZE_BUFFER,0);
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

	log_info("> mémoire partagée supprimée: clé: %d, ID: %d\n",(key_t)SHM_CLE, shmid);
	sem_delete(mutex);
	sem_delete(sem_prod);
	sem_delete(sem_conso);
	log_debug("Supression des sémaphores\n");

	return 0;
}
