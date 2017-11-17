#include <stdio.h>
#include <unistd.h>
#include <string.h>

char *replace_str(char *str, char *orig, char *rep);

int main(int argc, char *argv[])
{
	int i,j;
	char *tab[argc+3];

	for(i = 1; i < argc; i++)
	{
		if(!fork())
		{
			printf("Compilation de %s\n",argv[i]);
			execlp("gcc","gcc",argv[i],"-c",NULL);
			return 0;
		}
	}
	
	for(i = 1; i < argc; i++)
	{
		wait();
	}

	tab[0] = "gcc";
	for (j=1 ; j< argc; j++)
	{
		tab[j] = replace_str(argv[j],".c",".o");
	}
	tab[j++] = "-o";
	tab[j++] = "Exercice1";
	tab[j] = NULL;

	int test = 0;
	for(test = 0; test < argc+2; test++){
		printf("%d = %s\n",test, tab[test]);
	}


	execvp("gcc",tab);
	

	return 0;
}


char *replace_str(char *str, char *orig, char *rep)
{
  static char buffer[4096];
  char *p;

  if(!(p = strstr(str, orig)))  // Is 'orig' even in 'str'?
    return str;

  strncpy(buffer, str, p-str); // Copy characters from 'str' start to 'orig' st$
  buffer[p-str] = '\0';

  sprintf(buffer+(p-str), "%s%s", rep, p+strlen(orig));

  return buffer;
}