#ifndef	_ANNU_H
#define _ANNU_H

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

#endif
