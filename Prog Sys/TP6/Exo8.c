#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int ask = 1;
void interception(int signum);
int convert(char* input);

void interception(int signum)
{
	printf("INTERCEPTION\n");
	if(signum == SIGUSR1)
	{
		ask = 0;
	}
}

int convert(char* input)
{
	int isDigit
	while(j<strlen(input) && isDigit == 0)
	{
	  isDigit = isdigit(input[j]);
	  j++;
	}
	if(isDigit)
}

int main(int argc, char const *argv[])
{
	pid_t fils_pid;
	int i;

	fils_pid=fork();

	if(fils_pid == 0)
	{
		/*Fils*/
		signal(SIGUSR1,interception);
		char input[255];
		printf("Entrez un entier en moins de 5 secondes\n");
		while(ask)
		{
			printf("Svp un entier : ");
			scanf("%s\n",input);
			convert(input);
		}

		
	}
	else
	{
		/*Pere*/
		for(i = 0; i < 5; i++)
		{
			sleep(1);
			// printf("Père : %i\n",i);
			i++;
		}
		kill(fils_pid, SIGUSR1);

	}

	return 0;
}