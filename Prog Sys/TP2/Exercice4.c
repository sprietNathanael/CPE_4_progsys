#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{

	if(!fork())
	{

		if(!fork())
		{
			sleep(3);
			execlp("who","who",NULL);
			return 0;
		}
		wait();
		sleep(3);
		execlp("ps","ps",NULL);
		return 0;
	}
	wait();
	sleep(3);
	execlp("ls","ls","-l",NULL);
	return 0;

}