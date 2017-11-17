#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int display = 0;

void interception(int signum)
{
	printf("INTERCEPTION\n");
	if(signum == SIGUSR1)
	{
		display = 1;
	}
	else if(signum == SIGUSR2)
	{
		display = 0;
	}
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
		signal(SIGUSR2,interception);
		while(1)
		{
			if(display)
			{
				sleep(1);
				printf("Fils\n");
			}
		}
		
	}
	else
	{
		/*Pere*/
		i = 1;
		while(1)
		{
			sleep(1);
			printf("Père : %i\n",i);
			if(i == 3)
			{
				kill(fils_pid,SIGUSR1);
			}
			else if(i==5)
			{
				kill(fils_pid, SIGUSR2);
			}
			i++;
		}

	}

	return 0;
}