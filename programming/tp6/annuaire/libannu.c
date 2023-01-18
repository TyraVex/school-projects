
#include <stdio.h>
#include <string.h>
#include "libannu.h"

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
