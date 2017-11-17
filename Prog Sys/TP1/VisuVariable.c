#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int nbarg, char **arg)
{
	extern char **environ;
	int i=0, continueWhile = 1;
	printf("%s\n",getenv("LESS"));
	if(nbarg<=1)
	{
		printf("Il y a rien\n");
	}
	else
	{
		while(environ[i] != NULL && continueWhile)
		{
			if(strstr(environ[i], arg[1]) != NULL)
			{
				printf("%s\n",environ[i]);
				continueWhile = 0;
			}
			i++;

		}
	}s



	return 0;
}
