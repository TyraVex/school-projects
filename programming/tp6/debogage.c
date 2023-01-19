/************************************************************************B1**/
/*Fichier: annuaire.c							   	*/
/*NOM :						 						*/
/* Version : 1.0									*/
/*Date : 02/01/2022							   		*/
/***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "libannu.h"

/***************************************************************************/
/* NOM FONCTION : menu						           */
/* DESCRIPTION :  Affiche le menu et saisi le choix de l'utilisateur       */
/* Retourne : le choix de l'utilisateur          			   */
/* Effets de bords : Saisie au clavier                                     */
/* Parametres en entree : 						   */
/* Parametres en sortie :                                                  */
/***************************************************************************/
int menu();
unsigned long getTime();

int main() {

  srand(time(0)); // nombres aléatoires
  Ttabpers Rep; // Repertoire de personne
  Tchaine nom; //Variable pour saisir le nom de la personne
  char rep; // Réponse du menu
  int dernier = 0; //Position du dernier entre. Mais le 0 c'est pour la sentinnelle
  int trouv; // drapeau utilise pour savoir si l'insertion a ete faite
  int monchoix; // Variable pour saisir les reponses de l'utilisateur pour traiter les options du menu
  int pos; // Pour la position de la suppression
  char randoms[MAXPERS][12]; // Pour la position de la suppression
  int randomInt[MAXPERS]; // Pour la position de la suppression
  unsigned long chrono; // Test des performances

  //Traitement de la reponse de la l'utilisateur
  while (1) //On arrete quand l'utilisateur choisi l'option 4
  {
      rep=menu();
      switch (rep)
      {
          case 1 : printf("Saisir un nom : ");
                   scanf("%s", nom);
                   printf("Nom saisi : '%s'\n", nom);
                   if (!chercherpers(Rep, dernier, nom)) trouv=insererpers(Rep, &dernier, nom);
                   if (!trouv) printf("\nLe repertoire est plein !!!\n");
                   continue;

          case 2 : printf("Saisir un nom : ");
                   scanf("%s", nom);
                   printf("La position est %d !!!\n", chercherpers(Rep, dernier, nom));
                   continue;

          case 3 : printf("Saisir une position à supprimer : ");
                   scanf("%d", &pos);
                   supprimerpers(Rep, &dernier, pos);
                   continue;

          case 4 : printf("\nContenu de l'annuaire :\n");
                   afficherrep(Rep, dernier);
                   continue;

          case 5 : for (int i=1; i < MAXPERS; i++) sprintf(randoms[i], "%d", rand());

                   printf("\nAjout de %d éléments", MAXPERS);
                   chrono = getTime();
                   for (int i=1; i < MAXPERS; i++) {
                       if (!chercherpers(Rep, dernier, randoms[i]))
                          insererpers(Rep, &dernier, randoms[i]);
                   }
                   printf("\nFait en %lu µs\n", getTime() - chrono);

                   printf("\nRecherche de %d éléments", MAXPERS);
                   chrono = getTime();
                   for (int i=1; i < MAXPERS; i++) chercherpers(Rep, dernier, randoms[i]);
                   printf("\nFait en %lu µs\n", getTime() - chrono);

                   printf("\nSuppression de %d éléments", MAXPERS);
                   chrono = getTime();
                   for (int i=1; i < MAXPERS; i++) {
                       pos = chercherpers(Rep, dernier, randoms[i]);
                       supprimerpers(Rep, &dernier, pos);
                   }
                   printf("\nFait en %lu µs\n", getTime() - chrono);
                   continue;

          case 6 : printf("FIN !!!\n\n");
                   return 1;

          default : printf("Cas imprevu !!!\n");
                    continue;
      }
  }

}

/***************************************************************************/
/* NOM FONCTION : menu						           */
/* DESCRIPTION :  Affiche le menu et saisi le choix de l'utilisateur       */
/* Retourne : le choix de l'utilisateur          			   */
/* Effets de bords : Saisie au clavier                                     */
/* Parametres en entree : 						   */
/* Parametres en sortie :                                                  */
/***************************************************************************/
int menu() {

   int choix; //Permet de saisir la reponse de l'utilisateur
   printf("\n1 - Entrer un nom de client");
   printf("\n2 - Rechercher la position d'un client");
   printf("\n3 - Supprimer un client par position");
   printf("\n4 - Afficher l'annuaire ");
   printf("\n5 - Test des performances");
   printf("\n6 - Quitter");
   printf("\n\nVotre choix : ");
   scanf("%d", &choix);
   getchar();
   return choix;

}

// get time in microseconds
unsigned long getTime()
{
  struct timeval currentTime;
  gettimeofday(&currentTime, NULL);
  return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}
