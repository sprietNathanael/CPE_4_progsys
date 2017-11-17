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

	signal(SIGINT,SIG_IGN);
	for(;;){printf("Boucle pid : %d\n",getpid());}
	return 0;
}
