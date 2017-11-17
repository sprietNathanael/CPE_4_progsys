#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int IdProcessus;
	char donnee;
	int df1 = open("entree",O_RDONLY);
	int df2 = creat("sortie",0666);
	FILE *trace = fopen("trace","w");
	fprintf(trace, "Le caractère '#' indique que c'est le processus fils qui s'exécute \n");
	fprintf(trace, "Le caractère '$' indique que c'est le processus père qui s'exécute \n");
	fflush(trace);
	IdProcessus=fork();
	printf(("Création de processus \n"));
	while(read(df1,&donnee,sizeof(char))>0)
	{
		if(IdProcessus == 0)
		{
			fprintf(trace, "#%c",donnee);
		}
		else
		{
			fprintf(trace,"$%c",donnee);
		}
		fflush(trace);
		write(df2,&donnee,sizeof(char));
	}
	printf("Fin de la boucle while \n");
	close(df1);close(df2);
	return 0;
}

