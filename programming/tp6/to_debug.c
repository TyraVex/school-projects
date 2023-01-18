/************************************************************************B1**/
/*Fichier: annuaire.c							   	*/
/*NOM :						 						*/
/* Version : 1.0									*/
/*Date : 02/01/2022							   		*/
/***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCAR 30
#define MAXPERS 10000

typedef char Tchaine[MAXCAR+1];
typedef Tchaine Ttabpers[MAXPERS+1];
void afficherrep(Ttabpers Rep, int der);
int insererpers(Ttabpers Rep, int *der, Tchaine nom);
int chercherpers(Ttabpers Rep, int der, Tchaine nom);
int supprimerpers(Ttabpers Rep, int *der, int position);


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

  Ttabpers Rep; // Repertoire de personne
  Tchaine nom; //Variable pour saisir le nom de la personne
  char rep; // Réponse du menu
  int dernier = 1; //Position du dernier entre. Mais le 0 c'est pour la sentinnelle
  int trouv; // drapeau utilise pour savoir si l'insertion a ete faite
  int monchoix; // Variable pour saisir les reponses de l'utilisateur pour traiter les options du menu
  int pos; // Pour la position

  //Traitement de la reponse de la l'utilisateur
  while (1) //On arrete quand l'utilisateur choisi l'option 4
  {
      rep=menu();
      switch (rep)
      {
          case 1 : printf("Saisir un nom : ");
                   scanf("%s", &nom);
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

          case 5 : printf("FIN !!!\n\n");
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
   printf("\n5 - Quitter");
   printf("\n\nVotre choix : ");
   scanf("%d", &choix);
   getchar();
   return choix;

}

// Insertion d'un nom
int insererpers(Ttabpers Rep, int *der, Tchaine nom) {
    if (*der >= MAXPERS) return 0; // the list is full

    int i = *der;
    while (i > 0 && strcmp(Rep[i-1], nom) > 0) {
        strcpy(Rep[i], Rep[i-1]);
        i--;
    }

    strcpy(Rep[i], nom);
    (*der)++;
    return i+1;
}

// Affichage de l'annuaire
void afficherrep(Ttabpers Rep, int der) {
    for (int i = 1; i < der; i++) {
        printf("%d. %s\n", i, Rep[i]);
    }
}

// Recherche d'un nom
int chercherpers(Ttabpers Rep, int der, Tchaine nom) {
    int debut = 1; //premier element de la liste
    int fin = der-1; // dernier element de la liste
    while (debut <= fin) {
        int milieu = (debut + fin) / 2;
        int comp = strcmp(Rep[milieu], nom);
        if (comp == 0) return milieu;
        else if (comp < 0) debut = milieu + 1;
        else fin = milieu - 1;
    }
    return 0;
}

// Supprimer un nom
int supprimerpers(Ttabpers Rep, int *der, int position) {
    if (position > *der || position < 1) return 0; // position non valide
    for (int i = position; i < *der; i++) strcpy(Rep[i], Rep[i+1]);
    (*der)--;
    return position;
}

