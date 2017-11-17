#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>


int fin(){
	printf("SIGINT pour processus %d\n",getpid());
	exit(1);
}


int main()
{

	signal(SIGQUIT,SIG_IGN);
	signal(SIGINT,fin);
	for(;;){printf("Boucle pid : %d\n",getpid());}
	return 0;
}
