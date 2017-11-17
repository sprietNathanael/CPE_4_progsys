#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i=1,j, continueWhile = 1;
	float temp,moy = 0.0, total=0.0;
	int res;

	if(argc <= 1)
	{
		printf("Aucune moyenne à calculer \n");

	}
	else
	{
		while (i<argc && continueWhile)
		{
			//printf("%d :%s \n",i,argv[i]);

			res = sscanf(argv[i],"%f",&temp); //on convertit un string en float


			//printf("%f\n",temp);
	
			if((temp<0 ||temp>20) || res==0)
			{
				continueWhile = 0;

			}
			else
			{
				total += temp;
			}

			i++;
		}
		if(continueWhile)
		{
			moy = total/(argc-1) ;
			printf("%1.2f\n", moy);
		}
		else
		{
			printf("Note non valide\n");
		}
	}


	return 0;
}