/************************************************************************B1**/
/*Fichier: annuaire.c							   	*/
/*NOM :						 						*/
/* Version : 1.0									*/
/*Date : 02/01/2022							   		*/
/***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXPERS 100
#define MAXCAR 100

// Insertion d'un nom
int insererpers(char *Rep, int *der, char *nom) {
    int i = 0, j;
    while (i < *der && strcmp(Rep[i], nom) < 0) i++;
    if (i < *der && strcmp(Rep[i], nom) == 0) return i;
    for (j = *der; j > i; j--) Rep[j] = Rep[j-1];
    strcpy(Rep[i], nom);
    (*der)++;
    return i;
}

// Affichage de l'annuaire
void afficherrep(char Rep, int der) {
    int i;
    printf("\nAnnuaire :\n");
    for (i = 1; i <= der; i++) {
        printf("%s\n", Rep[i]);
    }
}

// Recherche d'un nom
int chercherpers(char Rep, int der, char *nom) {
    int deb, fin, milieu;
    deb = 1;
    fin = der;
    while (deb <= fin) {
        milieu = (deb + fin) / 2;
        if (strcmp(Rep[milieu], nom) == 0) return milieu;
        else if (strcmp(Rep[milieu], nom) < 0) deb = milieu + 1;
        else fin = milieu - 1;
    }
    return 0;
}

// Supression d'une position
int supprimerpers(char Rep, int *der, int position) {
    int i;
    if (position > *der || position < 1) return 0;
    for (i = position; i < *der; i++)
        Rep[i] = Rep[i + 1];
    (*der)--;
    return position;
}

/***************************************************************************/
/* NOM FONCTION : menu						           */
/* DESCRIPTION :  Affiche le menu et saisi le choix de l'utilisateur       */
/* Retourne : le choix de l'utilisateur          			   */
/* Effets de bords : Saisie au clavier                                     */
/* Parametres en entree : 						   */
/* Parametres en sortie :                                                  */
/***************************************************************************/
int menu();

int main() {

  char Repert[MAXPERS][MAXCAR]; // Repertoire de personne
  char nom[MAXCAR]; //Variable pour saisir le nom de la personne
  char rep=menu(); // Réponse du menu
  int dernier; //Position du dernier entre. Mais le 0 c'est pour la sentinnelle
  int trouv; // drapeau utilise pour savoir si l'insertion a ete faite
  int monchoix; // Variable pour saisir les reponses de l'utilisateur pour traiter les options du menu 

  //Traitement de la reponse de la l'utilisateur
  switch (rep)
  {
      case 1 : printf("\nSaisir un nom : ");
               scanf("%s", &nom);
               printf("\nNom saisi : '%s'", nom);
               if (!chercherpers(nom, *Repert, dernier))
                  insererpers(nom, *Repert, dernier);
               if (!trouv) printf("\nLe repertoire est plein !!!\n\n");
               break;
      case 2 : printf("\nSaisir un nom :");
               scanf("%s", &nom);
               printf("\nLa position est %d !!!", chercherpers(nom, Repert, dernier));
               break;
      case 3 : afficherrep(Repert, dernier);
               break;
      case 4 : printf("\nFIN !!!\n\n");
               exit(0);
      default : printf("\nCas imprevu !!!\n\n");
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
   printf("\n3 - Afficher l'annuaire ");
   printf("\n4 - Quitter");
   printf("\nVotre choix : ");
   scanf("%d", &choix);
   getchar();
   return choix;

}
