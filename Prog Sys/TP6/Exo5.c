#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>



int main(int argc, char const *argv[])
{
	pid_t fils_pid;
	int i;

	fils_pid=fork();
	if(fils_pid == 0)
	{
		/*Fils*/
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
			printf("Père : %i\n",i);
			i++;
		}

		kill(fils_pid,SIGKILL);

	}

	return 0;
}