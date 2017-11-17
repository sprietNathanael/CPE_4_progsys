#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int fin = 0;

void finish(int sig)
{
	if(sig=SIGINT)
	{
		fin=1;
	}
}

int main()
{
	signal(SIGINT,finish);
	while(fin == 0)
	{
		printf("fin = %d et pid = %d\n",fin,getpid(;
	}
	return 0;
}
