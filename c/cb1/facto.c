/***********************************************************************************************/
/* NOM : BARUZIER           PRENOM : Thomas                                                            */
/* Application : facto.c - Calcul de la factoriel d'un nombre              					   */
/* Date : 19/11/2022                                                                           */
/* Version : 1.0                                                                               */
/* Compilation : gcc facto.c -o facto		    					        				   */
/* Utilisation : ./facto	                                                                   */
/***********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

//Protototype
long fact(int nb);

int main()
{

  int n;
  char rep;

  do
  {
    printf("\nSaisir un entier positif : ");
    scanf("%d", &n);
    getchar();
    printf("\n%d! = %ld\n", n, fact(n));
    printf("\nVoulez vous recommencer (O/N)? ");
    scanf("%c", &rep);
    getchar();
  } while (rep=='o' || rep=='O');

  return EXIT_SUCCESS;

}

/**************************************************************************************************/
/*Fonction : fact                                                                             	  */
/* Description : Calcule la factorielle d'un nombre						       					  */
/* Entrees : nb, le nombre dont on doit calculer la factorielle                                   */
/* Sorties :                                                                                      */
/* Retourne :nb !                                                                                    */
/**************************************************************************************************/
long fact(int nb)
{

  long P=1 ; // valeur partielle

  if (nb <= 0) return 0;
	for( ; nb != 0; nb--) P=P*nb;
	return P;

}
