#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>


int main(int argc, char const *argv[])
{
	int val = atoi(argv[1]);
	int listetube[val][2]; //on défnit le nombre de processus que l'utilisateur veut créer
	int processus0; // Processus initial qui est commun à tous les lancers 
	int pid,r,j=0,numero=0;



	for(int i=0; i< val ;i++)
	{
		pipe(listetube[i]);
	}


	for(j=0;j<val;j++)
	{

		if(fork()==0)
		{	
			//Fils
			numero++;
			close(listetube[j][1]);
			srand(getpid()); 
			r = rand()%10000;  //Génération du nombre aléatoire
			pid = getpid();
			printf("processus pid %d numéro %d valeur = %d\n",pid,numero,r);
			//exit(0);
		}
		else
		{
			//Pere
		}

	}	

	return 0;
}
