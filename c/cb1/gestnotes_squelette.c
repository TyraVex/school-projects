/***********************************************************************************************/
/* NOM : BARUZIER     PRENOM : Thomas                                                          */
/* Application : gestnotes.c - Gestion de notes                								   */
/* Date : 19/11/2022                                                                           */
/* Version : 1.0                                                                               */
/* Compilation : gcc gestnotes.c -o gestnotes -lm 					        				   */
/* Utilisation : ./gestnotes                                                                   */
/***********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NBNOTES	70 // Defini le nombre maximal de notes que l'on peut gerer
#define NOTEMAX 20 // Defini la note maximale
#define NOTEMIN 0  // Defini la note minimale

typedef float Tnote; // Definition du type note
typedef int Tindice; // Definition du type indice (position) d'une note

//Prototypes des traitements
Tnote saisirnote();
void affichernote(const Tnote, const Tindice);
void listernotes(Tnote T[], const Tindice der);
Tindice ajouternote(Tnote T[], Tindice *der, const Tnote note);
Tnote minnotes(Tnote T[], const Tindice der);
Tnote maxnotes(Tnote T[], const Tindice der);
Tnote moyennenotes(Tnote T[], const Tindice der, const Tnote borneinf, const Tnote bornesup);
float ecarttypenotes(Tnote T[],const Tindice der, const Tnote moyenne);
Tindice lastnote=0;
float inf, sup, moyenne;

int main()
{
	Tnote Tab[NBNOTES+1]={10.3, 14.5, 7.2, 17.8, 2.7, 15.45, 4.8, 9.9, 6.29, 12.85, 19.1}; // Tableau de notes pre-rempli pour faciiter les tests
	Tindice lastnote=10; // Indique le nombre de notes deja saisies
	Tnote unenote; // Permet la saisie d'une nouvelle note
	Tnote mean ; //moyenne des notes
	Tnote sigma ; //ecart type
	int choix; // pour saisir le choix de l'utilisateur

do
{
	printf("\nAPPLICATION DE GESTION DES NOTES \n");
	printf("1 - Ajouter une note \n");
	printf("2 - Lister les notes \n");
	printf("3 - Afficher la note minimale \n");
	printf("4 - Afficher la note maximale \n");
	printf("5 - Afficher la moyenne des notes \n");
	printf("6 - Afficher l'ecart type \n");
	printf("99 - Quitter !!! \n");
	printf("\nVotre choix : ");
	scanf("%d", &choix);
  getchar();

switch (choix)
{
case 1 : //Ajouter une note

    unenote = saisirnote();
    if (unenote == -1)
    {
      printf("Ajout impossible\n");
      break;
    }
    ajouternote(Tab, &lastnote, unenote);
    affichernote(unenote, lastnote);
		break;

case 2 : //Lister les notes

    listernotes(Tab, lastnote);
		break;

case 3 : //Afficher la note minimale

    unenote = minnotes(Tab, lastnote);
    printf("Note minimale : %f\n", unenote);
		break;

case 4 : //Afficher la note maximale

    unenote = maxnotes(Tab, lastnote);
    printf("Note maximale : %f\n", unenote);
		break;

case 5 : //Afficher la moyenne des notes comprises dans un interval

	  printf("Borne inferieure : ");
  	scanf("%f", &inf);
    getchar();
	  printf("Borne superieure : ");
  	scanf("%f", &sup);
    getchar();
    moyenne = moyennenotes(Tab, lastnote, inf, sup);
	  if (moyenne == 0)
	  {
	    printf("Erreur\n");
	  }
	  else
	  {
	    printf("Moyenne des notes comprise entre %f et %f : %f\n", inf, sup, moyenne);
    }
		break;

case 6 : //Afficher l'ecart type des notes

		//A completer
		break;

case 99 : //Quitter

		//A completer
		break;

default : printf("\nARRET DE L'APPLICATION !!! \n\n");
	}
}
while (choix!=99);
} // fin du main


/*************************************************************************************************/
/* Fonction : saisirnote                                                                          */
/* Description : Permet de la saisie d'une note       											 */
/* Entrees :                                     												  */
/* Sorties :                                                                                      */
/* Retourne : La note saisie                                                                      */
/**************************************************************************************************/
Tnote saisirnote()
{

  int note;
  printf("\nEntrer la note ajouter : ");
  scanf("%d",&note);
  getchar();
  if(note < NOTEMIN || note > NOTEMAX) return -1;
  return note;

}

/*************************************************************************************************/
/* Fonction :affichernote                                                                        */
/* Description : Permet d'aficher une note tableau de notes       							     */
/* Entrees : La note a afficher  et sa position de le tableau de notes                           */
/* Sorties :                                                                                      */
/* Retourne : 				                                                                     */
/**************************************************************************************************/
void affichernote(const Tnote note, const Tindice i)
{

  printf("\nTab[%d]=%lf\n", i, note);

}

/*************************************************************************************************/
/* Fonction :listernotes                                                                         */
/* Description : Affiches toutes les notes       							     				 */
/* Entrees : le tableau de notes Tnote et le nombre de notes a afficher                          */
/* Sorties :                                                                                     */
/* Retourne : 				                                                                     */
/**************************************************************************************************/
void listernotes(Tnote T[], const Tindice der)
{

  printf("\n");
  int position;
  for (position = 0; position < der+1; position++) printf("T1[%d]=%lf\n", position, T[position]);

}

/*************************************************************************************************/
/* Fonction :ajouternote                                                                         */
/* Description : Ajoute une note au catalogue des notes      							     	 */
/* Entrees : le tableau de notes T Tnote et le nombre de notes deja presentes dans le tableau    */
/* Sorties : T le tableau de note modifie et *der le nombre de notes                             */
/* Retourne : La position de la note qi vient d'etre rajoutée ou 0 si l'ajout est impossible	 */
/*************************************************************************************************/
Tindice ajouternote(Tnote T[], Tindice *der, const Tnote note)
{

  if (*der == NBNOTES)
    return 0;
  else
  {
    *der = *der + 1;
    T[*der] = note;
    return *der;
  }

}

/*************************************************************************************************/
/* Fonction :minnotes                                                                            */
/* Description : Donne la note minimale de l'ensemble des notes      							 */
/* Entrees : le tableau de notes T Tnote et le nombre de notes du tableau    					*/
/* Sorties :                                                                                    */
/* Retourne : La note minimale du tableau de notes											 	 */
/**************************************************************************************************/
Tnote minnotes(Tnote T[], const Tindice der)
{

  int indice = 0;
  float minimum = T[indice];
  for (indice = 1; indice != der+1; indice++)
  {
    if (T[indice] < minimum) minimum = T[indice];
  }
  return minimum;

}


/*************************************************************************************************/
/* Fonction :maxnotes                                                                            */
/* Description : Donne la note maximale de l'ensemble des notes      							 */
/* Entrees : le tableau de notes T Tnote et le nombre de notes du tableau    					 */
/* Sorties :                             						 								 */
/* Retourne : La note maximale du tableau de notes											 	 */
/**************************************************************************************************/
Tnote maxnotes(Tnote T[], const Tindice der)
{
  int indice = 0;
  float maximum = T[indice];
  for (indice = 1; indice != der+1; indice++)
  {
    if (T[indice] > maximum) maximum = T[indice];
  }
  return maximum;

}


/*************************************************************************************************/
/* Fonction :moyennenotes                                                                        */
/* Description : Donne la moyenne des notes comprises entre une borneinf et une bornemax qui sont */
/* comprises dans cette moyenne																	*/
/* Entrees : le tableau de notes T Tnote,le nombre de notes du tableau, la borne inf et la borne max */
/* Sorties :                             						 								 */
/* Retourne :la moyenne des notes de l'interval	ou 0 si cette moyenne n'a pas de sens		      */
/**************************************************************************************************/
Tnote moyennenotes(Tnote T[], const Tindice der, const Tnote borneinf, const Tnote bornesup)
{

  if (bornesup > der || borneinf > der || bornesup < 0 || borneinf < 0 || borneinf > bornesup) return 0;
  int indice, count = 0;
  float moyenne = 0;
  for (indice = 0; indice < der; indice++)
  {
    if (T[indice] <= bornesup && T[indice] >= borneinf)
    {
      moyenne += T[indice];
      count++;
    }
  }
  moyenne = moyenne / count;
  return moyenne;

}

/*************************************************************************************************/
/* Fonction :ecarttypenotes                                                                      */
/* Description : Donne l'ecart type des notes de l'ensemble de notes 							 */
/* comprises dans cette moyenne																	 */
/* Entrees : le tableau de notes T Tnote,le nombre de notes du tableau et la moyenne des notes    */
/* Sorties :                             						 								 */
/* Retourne :l'ecart type des notes du tabeau											 	     */
/**************************************************************************************************/
float ecarttypenotes(Tnote T[], const Tindice der, const Tnote moyenne)
{
		//A completer

return 0;	
}
