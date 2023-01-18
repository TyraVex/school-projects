#include <stdio.h>

////////////////////////////////////////////////////////////////////////////:
#include <string.h>

#define MAXPERS 100
#define MAXCAR 100

// Structures
typedef struct {
    char nom[50];
} Tpers;
typedef Tpers Ttabpers[MAXPERS+1];

// Déclaration de fonctions
int supprimerpers(Ttabpers Rep, int *der, int position);
int insererpers(Ttabpers Rep, int *der, char *nom);
int chercherpers(Ttabpers Rep, int der, char *nom);
void afficherrep(Ttabpers Rep, int der);

//int insererpers(Ttabpers Rep, int *der, char *nom) {
//    if (*der == MAXPERS - 1) return 0;
//    int i = *der + 1;
//    printf("\nDer : %d | Nom : %s\n", i, nom);
//    while (i >= 0 && strcmp(Rep[i].nom, nom) > 0) {
//        printf("Rep[%d]=%s\n", i, Rep[i]);
//        Rep[i+1] = Rep[i];
//        i--;
//    }
//    (*der)++;
//    printf("Name attrib : Rep[%d]=%s\n", i, nom);
//    strcpy(Rep[i].nom, nom);
//    return i;
//}

int insererpers(Ttabpers Rep, int *der, char *nom) {

    if (*der == MAXPERS - 1) return 0;
    *der = *der + 1;
    printf("\nder : %d", *der);
    for(int i = *der; i > 1; i--) {
        printf("Rep[%d]=%s\n", i, Rep[i]);
        Rep[i] = Rep[i+1];
    }
    strcpy(Rep[*der].nom, nom);
    return *der;

//    int i = *der + 1;
//    printf("\nDer : %d | Nom : %s\n", i, nom);
//    for(; strcmp(Rep[i].nom, nom); i--)
//    {
//        printf("Rep[%d]=%s\n", i, Rep[i]);
//        Rep[i] = Rep[i+1];
//        if(i < 1) break;
//    }
//    (*der)++;
//    printf("Name attrib : Rep[%d]=%s\n", i, Rep[i]);
//    strcpy(Rep[i].nom, nom);
//    Rep[i] = Rep[i+1];
//    return i;

}

// Affichage de l'annuaire
void afficherrep(Ttabpers Rep, int der) {
    int i;
    printf("\nAnnuaire :\n");
    for (i = 1; i <= der; i++) {
        printf("%s\n", Rep[i].nom);
    }
}

// Recherche d'un nom
int chercherpers(Ttabpers Rep, int der, char *nom) {
    int deb, fin, milieu;
    deb = 1;
    fin = der;
    while (deb <= fin) {
        milieu = (deb + fin) / 2;
        if (strcmp(Rep[milieu].nom, nom) == 0) return milieu;
        else if (strcmp(Rep[milieu].nom, nom) < 0) deb = milieu + 1;
        else fin = milieu - 1;
    }
    return 0;
}

// Supression d'une position
int supprimerpers(Ttabpers Rep, int *der, int position) {
    int i;
    if (position > *der || position < 1) return 0;
    for (i = position; i < *der; i++)
        Rep[i] = Rep[i + 1];
    (*der)--;
    return position;
}
////////////////////////////////////////////////////////////////////////////:

int menu() {

   int choix;  //Permet de saisir la reponse de l'utilisateur
   printf("\n 1-  Entrer un nom de client");
   printf("\n 2-  Rechercher la position d'un client");
   printf("\n 3-  Afficher l'annuaire ");
   printf("\n 4-  Quitter");
   printf("\n  Votre choix :");
   scanf("%d",&choix);
   getchar();
   return choix;

}

int main() {

  char Repert[MAXPERS][MAXCAR]; // Repertoire de personne
  char nom[MAXCAR]; //Variable pour saisir le nom de la personne
  int dernier; //Position du dernier entre. Mais le 0 c'est pour la sentinnelle
  int trouv; // drapeau utilise pour savoir si l'insertion a ete faite
  int monchoix; // Variable pour saisir les reponses de l'utilisateur pour traiter les options du menu

  //Affichage du menu
  char rep=menu();

  //Traitement de la reponse de la l'utilisateur
  switch (rep)
  {
      case 1 : printf("\n Saisir un nom :");
               scanf("%s",&nom);
               printf("\n Nom saisi : '%c'",nom);
               if (!chercherpers(&nom,Repert,dernier))
                  insererpers(&nom,Repert,dernier);
               if (!trouv) printf("\n Le repertoire est plein !!!\n\n");
               break;
      case 2 : printf("\n Saisir un nom :");
               scanf("%d",&nom);
               printf("\n La position est %d !!! ", chercherpers(&nom,Repert,dernier));
               break;
      case 3 : afficherrep(Repert,dernier);
               break;
      case 4 : printf("\n FIN !!!\n\n");
               break;
      default : printf("\n Cas imprevu !!!\n\n");
  }

  while (monchoix!=4); //On arrete quand l'utilisateur choisi l'option 4

  return 1;
}

