#include <stdio.h>
#include <string.h>
#include "libannu.h"

// Insertion d'un nom
int insererpers(Ttabpers Rep, int *der, Tchaine nom) {
    if (*der >= MAXPERS) return 0; // the list is full

    int i = *der + 1;
    while (i > 1 && strcmp(Rep[i-1], nom) > 0) {
        strcpy(Rep[i], Rep[i-1]);
        i--;
    }

    strcpy(Rep[i], nom);
    (*der)++;
    return i+1;
}

// Affichage de l'annuaire
void afficherrep(Ttabpers Rep, int der) {
    for (int i = 1; i <= der; i++) {
        printf("%d. %s\n", i, Rep[i]);
    }
}

// Recherche d'un nom
int chercherpers(Ttabpers Rep, int der, Tchaine nom) {
    int debut = 1; //premier element de la liste
    int fin = der; // dernier element de la liste
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
    if (position > *der + 1 || position < 1) return 0; // position non valide
    for (int i = position; i < *der + 1; i++) strcpy(Rep[i], Rep[i+1]);
    (*der)--;
    return position;
}
