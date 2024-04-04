#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <conio.h>
#define N 5
	/*cette première fonction met aléatoirement deux 2 à différents endroits dans la matrice et met 0 dans le reste de la matrice
	i represente l'indice de la ligne et j celui de la colonne enfin le tableau pos permet de recuperer les endroits où les 2 doivent
	se positionner*/
	void initialisation(int tab[N][N])
	{
	    int i,j,pos[4];
	    for(i=0;i<N;i++)
	        {
	            for(j=0;j<N;j++)
	            {
	                tab[i][j]=0;
	            }
	        }
	    do{
	        for(i=0;i<4;i++)
	        pos[i]=rand()%N;
	        for(j=0;j<2;j++)
	        tab[pos[j]][pos[j+2]]=2;
	      }while((pos[0]==pos[1])&&(pos[2]==pos[3]));
	}
	//cette fonction chaque fois nous permettra de presenter la matrice après un deplacement

	void affichage(int tab[N][N])
	{
	    int i,j;
	    for(i=0;i<N;i++)
	{printf("\n");
	    for(j=0;j<N;j++)
	        printf("%d\t",tab[i][j]);
	}
	}
	/*i represente la ligne et k la colonne
	en effet je fais un deplacement case par case lorsque la case précédente contient 0.
	pour cela la première boucle for me permet de gérer les lignes la troisième boucle for gère les colonnes
	et enfin la deuxième boucle fot je l'utilise comme compteur car le dépacement peut se faire au plus N-1 pour chaque case*/
	void deplacementG(int t[N][N])
	{
	    int i, j, k;
	    for(i=0;i<N;i++)
	    {
	        for(j=0;j<N-1;j++)
	        {
	            for(k=1;k<N;k++)
	            {
	                if((t[i][k]!=0)&&(t[i][k-1]==0))
	                {
	                    t[i][k-1]=t[i][k];
	                    t[i][k]=0;
	                }
	            }
	        }
	    }
	}
	/*ici le raisonnement reste le même mais i represente dans ce cas la colonne et k la ligne*/
	void deplacementH(int t[N][N])
	{
	    int i, j, k;
	    for(i=0;i<N;i++)
	    {
	        for(j=0;j<N-1;j++)
	            {
	                for(k=1;k<N;k++)
	                {
	                    if((t[k][i]!=0)&&(t[k-1][i]==0))
	                    {
	                        t[k-1][i]=t[k][i];
	                        t[k][i]=0;
	                    }
	                }
	            }
	    }
	}
	/*dans ce cas, i represente la ligne et k la colonne.
	le déplacement va de la gauche pour la droite donc pour chaque ligne on commence par le dernier élement de la ligne*/
	void deplacementD(int t[N][N])
	{
	    int i, j, k;
	    for(i=N-1;i>=0;i--)
	    {
	        for(j=0;j<N-1;j++)
	        {
	            for(k=N-2;k>=0;k--)
	            {
	                if((t[i][k]!=0)&&(t[i][k+1]==0))
	                {
	                    t[i][k+1]=t[i][k];
	                    t[i][k]=0;
	                }
	            }
	        }
	    }
	}
	/*dans ce cas, k represente la ligne et i la colonne.
	le déplacement est semblable au déplacement droit*/
	void deplacementB(int t[N][N])
	{
	    int i, j, k;
	    for(i=0;i<N;i++)
	    {
	        for(j=0;j<N-1;j++)
	            {
	                for(k=N-2;k>=0;k--)
	                {
	                    if((t[k][i]!=0)&&(t[k+1][i]==0))
	                    {
	                        t[k+1][i]=t[k][i];
	                        t[k][i]=0;
	                    }
	                }
	            }
	    }
	}
	/* cette fonction après le déplacement complet ajout un deux aléatoirement dans la matrice à une position où il n y a zero*/
	void ajoute_2(int t[N][N])
	{ int pos[2],i,j=0;
	do{
	    for(i=0;i<2;i++)
	    pos[i]=rand()%N;
	    }while(t[pos[0]][pos[1]]!=0);
	        t[pos[j]][pos[j+1]]=2;
	}
	/*ici pour faire la somme, on fixe chaque fois la ligne , on compare une case à celle qui la précède et si elles
	contiennent la même valeur alors à la case précdente on affecte deux fois sa valeur. pour la somme gauche on commence au
	début de la ligne*/
	int sommeG(int t[N][N])
	{
	    int i,j,k, intern=0;
	     for(i=0;i<N;i++)
	            {
	                for(k=1;k<N;k++)
	                {
	                    if(t[i][k-1]==t[i][k])
	                    {
	                     t[i][k-1]=2*t[i][k-1];
	                        t[i][k]=0;
	                       intern+=t[i][k-1];
	                    }
	                }
	            }
	            return (intern);//la valeur retournée par la somme est la somme effectué qui permettra de gérer le score
	}
	/*ici pour faire la somme, on fixe chaque fois la colonne , on compare une case à celle qui la précède et si elles
	contiennent la même valeur alors à la case précdente on affecte deux fois sa valeur. pour la somme bas, on commence par
	la première colonne et et la dernière ligne*/
	int sommeB(int t[N][N])
	{
	    int i,j,k,intern=0;
	      for(i=0;i<N;i++)
	    {
	            for(k=N-2;k>=0;k--)
	                {
	                    if((t[k][i]==t[k+1][i]))
	                    {
	                        t[k+1][i]=t[k][i]*2;
	                        t[k][i]=0;
	                        intern+=t[k+1][i];
	                    }
	                }
	            }
	            return(intern);
	}
	/*ici pour faire la somme, on fixe chaque fois la colonne , on compare une case à celle qui la précède et si elles
	contiennent la même valeur alors à la case précdente on affecte deux fois sa valeur. pour la somme haut on commence par
	première colonne et la première ligne*/
	int sommeH(int t[N][N])
	{
	    int i, j, k,intern=0;
	    for(i=0;i<N;i++)
	    {
	                for(k=1;k<N;k++)
	                {
	                    if((t[k][i]==t[k-1][i]))
	                    {
	                        t[k-1][i]=2*t[k][i];
	                        t[k][i]=0;
	                        intern+=t[k-1][i];
	                    }
	                }
	            }
	            return(intern);
	}
	/*ici pour faire la somme, on fixe chaque fois la ligne , on compare une case à celle qui la précède et si elles
	contiennent la même valeur alors à la case précdente on affecte deux fois sa valeur. pour la somme bas on commence à
	la dernière ligne et dernière colonne*/
	int sommeD(int t[N][N])
	{
	    int i, j, k, intern=0;
	    for(i=N-1;i>=0;i--)
	    {
	                for(k=N-2;k>=0;k--)
	                {
	                    if(t[i][k]==t[i][k+1])
	                    {
	                        t[i][k+1]=2*t[i][k];
	                        t[i][k]=0;
	                        intern+=t[i][k+1];
	                    }
	                }
	    }
	            return(intern);
	}
	/*la fonction deplacementpossible vérifie si il y'a possiblité de faire un déplacement ou pas.
	il prend en paramètre le plateau et le sens de déplacement. l'idée est de copié les informations du plateau dans une autre
	 matrice, ensuite effectué le déplacement normalement dans cette matrice et comparer la matrice obtenu au plateau.
	 elle retourne 0 si donc il y'a eu changement et 1 si non */
	int deplacementpossible(int deplacement, int plateau[N][N])
	{
	    int t[N][N],i,j;
	    for(i=0;i<N;i++)
	    {
	        for(j=0;j<N;j++)
	            t[i][j]=plateau[i][j];
	    }
	    switch(deplacement)
	    {
	    case 75:
	        deplacementG(t);
	        sommeG(t);
	        deplacementG(t);
	        break;
	    case 77:
	        deplacementD(t);
	        sommeD(t);
	        deplacementD(t);
	        break;
	    case 80:
	        deplacementB(t);
	        sommeB(t);
	        deplacementB(t);
	        break;
	    case 72:
	        deplacementH(t);
	        sommeH(t);
	        deplacementH(t);
	        break;
	        }
	    for(i=0;i<N;i++)
	    {
	        for(j=0;j<N;j++)
	           if(t[i][j]!=plateau[i][j])
	           return(0);
	    }
	    return(1);
	}
	/*la fin de jeu ici est la fonction qui vérifie si le jeu est fini et précise si on a perdu ou gagné.
	elle retoune 0 si la partie est terminé et 1 si non.
	premièrement on vérifie chaque fois si dans une case on a atteint 2048, si tel est le cas
	on retourne 0 en affichant qu'il a gagné. ensuite on vérifie si la matrice est rempli de nombre différent de 0 si tel est le cas
	 on vérifie la possiblité de deplacement dans tous les sens. si c'est impossible on retourne 0 en affichant qu'il a perdu.
	  dans le cas contraire le jeu continue. la valeur retourner ici modifie la variable qui permet chaque foi de jouer */
		int findejeu(int t[N][N])
	{
	    int i,j,k=0,cmpt;
	   for(i=0;i<N;i++)
	    {
	        for(j=0;j<N;j++)
	        {
	            if(t[i][j]==2048)
	               {
	                printf("\nvous avez gagne");
	                return(0);
	               }
	        }
	    }
	    for(i=0;i<N;i++)
	    {
	         for(j=0;j<N;j++)
	        {
	            if(t[i][j]!=0)
	                k=k+1;
	        }
	    }
	    if(k==N*N)
	        {
	            for(i=0;i<N;i++)
	            {
	                for(j=1;j<N;j++)
	                   {
	                       if((t[i][j]==t[i][j-1])||(t[j][i]==t[j-1][i]))
	                        {
	                            return(1);
	                        }
	                    }
	            }
	        printf("\nvous avez perdu");
	        return 0;
	        }
	        return 1;
	}
	main()
	{
	    int plateau[N][N]={}, sens, jeu=1, score=0;
	    srand(time(NULL));
	    initialisation(plateau);
	    affichage(plateau);
	   do{
	   sens=getch();
	  // system("cls");
	if(deplacementpossible(sens,plateau)==0)
	{
	                 //system("cls");
	                 printf("\n");
	switch(sens)
	{
	  case 75:
	        deplacementG(plateau);
	        score=score+sommeG(plateau);
	        ajoute_2(plateau);
	        deplacementG(plateau);
	       affichage(plateau);
	        printf("\n\t\t score= %d",score);
	        break;
	    case 72:

	        deplacementH(plateau);
	        score=score+sommeH(plateau);
	        deplacementH(plateau);
	        ajoute_2(plateau);
	        affichage(plateau);
	        printf("\n\t\t score= %d",score);
	        break;
	    case 77:
	        deplacementD(plateau);
	        score=score+sommeD(plateau);
	        deplacementD(plateau);
	        ajoute_2(plateau);
	        affichage(plateau);
	        printf("\n\t\t score= %d",score);
	        break;
	    case 80:
	        deplacementB(plateau);
	        score=score+sommeB(plateau);
	        deplacementB(plateau);
	        ajoute_2(plateau);
	        affichage(plateau);
	        printf("\n\t\t score= %d",score);
	        break;
	        default: //affichage(plateau);
	                 printf("\n\t\t score= %d",score);
	                 break;
	   }
	                 }
	                // else;
	                 /*{
	                 	 affichage(plateau);
				printf("\n\t\t score= %d",score);
					 }*/
	    jeu=findejeu(plateau);
	        }while(jeu==1);

	}

