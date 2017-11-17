#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int nombresPairs[2];
	int nombresImpairs[2];
	int sommePairs[2];
	int sommeImpairs[2];

	int filtrePair,filtreImpair;
	pipe(nombresPairs); 
	pipe(nombresImpairs); 	
	pipe(sommePairs); 	
	pipe(sommeImpairs);
	int r = 0;
	int n = 6; 
	int end = -1; 
	int increment = 0;
	int entreeImpaire = 0;
	int entreePaire = 0;
	int sommePaire_value = 0;
	int sommeImpaire_value = 0;
	int resImpaire = 0;
	int resPaire = 0;


	srand(time(NULL)); 


	
	filtrePair = fork();
	if(filtrePair == 0)
	{
		printf("filtrePair\n");
		close(nombresImpairs[1]);
		close(nombresImpairs[0]);
		close(sommePairs[0]);
		close(sommeImpairs[1]);
		close(sommeImpairs[0]);
		close(nombresPairs[1]);
		while(entreePaire != -1)
		{
			read(nombresPairs[0],&entreePaire, sizeof(int));
			printf("Entrée paire %d\n", entreePaire);
			if(entreePaire >= 0)
			{
				sommePaire_value += entreePaire;
			}
		}
		printf("send somme paire = %d\n",sommePaire_value);
		write(sommePairs[1], &sommePaire_value, sizeof(int));

	}
	else
	{
		printf("père filtrePair\n");
		filtreImpair = fork();
		if(filtreImpair == 0)
		{
			printf("filtreImpair\n");
			close(nombresImpairs[1]);
			close(sommePairs[1]);
			close(sommePairs[0]);
			close(sommeImpairs[0]);
			close(nombresPairs[1]);	
			close(nombresPairs[0]);	
			while(entreeImpaire != -1)
			{
				read(nombresImpairs[0],&entreeImpaire, sizeof(int));
				printf("Entrée impaire = %d\n",entreeImpaire);
				if(entreeImpaire >= 0)
				{
					sommeImpaire_value += entreeImpaire;
				}
			}
			printf("send somme impaire = %d\n",sommeImpaire_value);
			write(sommeImpairs[1], &sommeImpaire_value, sizeof(int));

		}
		else
		{
			close(nombresImpairs[0]);
			close(sommePairs[1]);
			close(sommeImpairs[1]);
			close(nombresPairs[0]);		
			printf("père filtreImpair\n");
			for(increment = 0; increment < n; increment++)
			{

				r = rand()%100;  //Génération du nombre aléatoire
				printf("%d = %d\n",increment,r);
				if(r % 2 == 0)
				{ // Pair
								//ferme l'entrée du tube
					write(nombresPairs[1],&r,sizeof(int));
					
				}
				else
				{ //Impair
					write(nombresImpairs[1],&r,sizeof(int));
					
				}
			}
			write(nombresImpairs[1],&end,sizeof(int));
			write(nombresPairs[1],&end,sizeof(int));
			

			read(sommePairs[0],&resPaire,sizeof(int));
			read(sommeImpairs[0],&resImpaire,sizeof(int));
			printf("rec sommePairs = %d\n",resPaire);
			printf("rec sommeImpairs = %d\n",resImpaire);
			
			printf("%d\n",resPaire+resImpaire);
		}
	}


	return 0;
}