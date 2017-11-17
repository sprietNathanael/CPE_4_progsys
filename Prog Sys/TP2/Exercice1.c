#include <stdio.h>

int main()
{
	int pid1,status;

	printf("pere = %d\n",getpid());
	fflush(stdout);
	//sleep(1);
	pid1 = fork();
	if(!pid1)
	{
		printf("fils = %d\n",getpid());
		return 0;
	}

	pid1 = wait(&status);
	printf("pere = %d ; %d\n",getpid(), pid1);

	return 0;
}
