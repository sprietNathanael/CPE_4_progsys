#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int fils1,fils2,n,m;
	int tube[2];
	char buffer[256];

	if(pipe(tube)!=0)
	{
		perror("Problème - création du tube \n");
		exit(1);
	}

	fils1 = fork();

	if((fils1 == 0)){
		close(tube[0]);
		printf("Je suis le fils producteur \n");
		printf("Je dépose 5 caractères dans le pipe \n");
		write(tube[1],"abcde",5);
		close(tube[1]);
		exit(3);

	}
	else 
	{

		fils2 = fork();
		if(fils2==0)
		{
			printf("Je suis le fils consommateur");
			close(tube[1]);
			read(tube[0],buffer,5);
			printf("Voici les caractères lus : %s\n",buffer);
			exit(3);
		}
		else
		{
			printf("Le processeur père se termine");
			close(tube[0]);

		}

	}

	return 0;
}