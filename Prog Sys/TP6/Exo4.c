#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int i,n =0;

void interception()
{
	n=i*2;	
}

int main()
{
	pid_t fils_pid;

	signal(SIGCHLD,interception);
	l
	for(i=1;i<5;i++){

		fils_pid=fork();

		if(fils_pid >0)
		{
			pause();
			break;
		}
	}
	printf("%d\n",n);
	exit(1);
}