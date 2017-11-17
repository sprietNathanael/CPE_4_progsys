#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>


int main()
{
	int pfd[2];
	int pfd2[2];
	int fils1,fils2;
	pipe(pfd); 	// création du tube1
	pipe(pfd2); // création du tube2

	fils1 = fork();
	if(fils1 == 0){ 
		//fils 1
		printf("Fils1 !\n");
		close(pfd2[1]);				//ferme l'entrée du tube
		dup2(pfd2[0],0);			//copie la sortie verds l'entrée standard
		close(pfd2[0]);				//ferme le descripteur de la sortie du tube
		int sortie = open("test2.txt",O_WRONLY);
		dup2(sortie,1);
		close(sortie);	
		execlp("tail","tail","-n", "5",NULL);		
		}
	else
	{	
		fils2 = fork();
		if(fils2 == 0)
		{
			//fils 2
			printf("Fils2 !\n");
			close(pfd2[0]);									
			dup2(pfd2[1],1);									
			close(pfd2[1]);	

			close(pfd[1]);				
			dup2(pfd[0],0);				
			close(pfd[0]);				
			execlp("grep","grep","un",NULL);		
		}
		else
		{

			//pere
			printf("Père !\n");
			close(pfd[0]);									
			dup2(pfd[1],1);									
			close(pfd[1]);									
			execlp("sort","sort","test.txt",NULL);		
		}
	}

	return 0;
}