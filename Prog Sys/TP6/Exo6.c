#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void interception(int signum)
{
	printf("INTERCEPTION\n");
}

int main(int argc, char const *argv[])
{
	pid_t fils_pid;
	int i;

	fils_pid=fork();
	if(fils_pid == 0)
	{
		/*Fils*/
		signal(SIGINT,interception);
		for(;;)
		{
			sleep(1);
			printf("Fils\n");
		}


	}
	else
	{
		/*Pere*/
		for(i=0;i<3;i++)
		{
			sleep(1);
			printf("Père : %d\n",i);
		}

	}

	return 0;
}