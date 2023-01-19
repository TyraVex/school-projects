#ifndef	_ANNU_H
#define _ANNU_H

// Variables
#define MAXCAR 30
#define MAXPERS 10000

// Structures
typedef char Tchaine[MAXCAR+1];
typedef Tchaine Ttabpers[MAXPERS+1];

// Fonctions
void afficherrep(Ttabpers Rep, int der);
int insererpers(Ttabpers Rep, int *der, Tchaine nom);
int chercherpers(Ttabpers Rep, int der, Tchaine nom);
int supprimerpers(Ttabpers Rep, int *der, int position);

#endif
