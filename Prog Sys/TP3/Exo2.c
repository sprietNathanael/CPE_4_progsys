#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int pfd[2];
	int pid;
	pipe(pfd); // création du tube
	pid = fork();
	if(pid == 0){ 	//fils
		printf("Fils !\n");
		close(pfd[1]);				//ferme l'entrée du tube
		dup2(pfd[0],0);				//copie la sortie verds l'entrée standard
		close(pfd[0]);				//ferme le descripteur de la sortie du tube
		execlp("wc","wc",NULL);		//recouvre avec wc
	}
	else
	{				//pere
		printf("Père !\n");
		close(pfd[0]);									//ferme la sortie du tube
		dup2(pfd[1],1);									//copie la sortie verds la sortie standard
		close(pfd[1]);									//ferme le descripteur de l'entrée du tube
		execlp("cat","cat","test.txt",NULL);		//recouvre avec cat test.txt
	}

	return 0;
}