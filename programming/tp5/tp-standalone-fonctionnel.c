
#include <stdio.h>
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


// Fonction principale
int main() {
    Ttabpers Rep;
    char nom[MAXCAR];
    int der = 1;

    // Ajout de quelques noms à l'annuaire
    strcpy(nom, "Bob");
    printf("\nPosition de %s : %d\n", nom, insererpers(Rep, &der, nom));
    strcpy(nom, "Alice");
    printf("Position de %s : %d\n", nom, insererpers(Rep, &der, nom));
    strcpy(nom, "Charly");
    printf("Position de %s : %d\n", nom, insererpers(Rep, &der, nom));

    // Afficher l'annuaire complet
    afficherrep(Rep, der);

    // Chercher une personne
    strcpy(nom, "Bob");
    printf("Position de %s : %d\n", nom, chercherpers(Rep, der, nom);

    // Supprimer une personne
    strcpy(nom, "Alice");
    int pos = supprimerpers(Rep, &der, chercherpers(Rep, der, nom));
    if (pos == '0') printf("Suppression de %s impossible\n", nom);
    else printf("Suppression de %s à la position %d\n", nom, pos);
    afficherrep(Rep, der);

    return 0;
}

// Insertion d'un nom
int insererpers(Ttabpers Rep, int *der, char *nom) {
    int i = 0, j;
    while (i < *der && strcmp(Rep[i].nom, nom) < 0) i++;
    if (i < *der && strcmp(Rep[i].nom, nom) == 0) return i;
    for (j = *der; j > i; j--) Rep[j] = Rep[j-1];
    strcpy(Rep[i].nom, nom);
    (*der)++;
    return i;
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
