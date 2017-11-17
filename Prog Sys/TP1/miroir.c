#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int i,j;

	for(i=1;i<argc;i++)
	{
		// printf("%s\n",argv[i]);
		// printf("%d\n",(int)strlen(argv[i]));

		for(j=((int)strlen(argv[i])-1);j>=0;j--)
		{
			printf("%c",argv[i][j]);
		}
		printf(" ");
	}

	return 0;
}