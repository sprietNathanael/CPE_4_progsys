#include <stdio.h>

int main()
{
	int pid,ppid,retour,i;

	for(i=0 ; i<3 ; i++)
	{
		retour = fork();
		pid = getpid();
		ppid = getppid();
		printf("i: %d - processus: %d - mon pere est:%d - retour:%d\n",i,pid,ppid,retour);
		fflush(stdout);
	}

	return 0;
}