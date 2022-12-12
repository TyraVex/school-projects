/************************************************************************/
/* AUTEUR : 						                                                                                  */
/* DATE : 11/12/2021							                                                             */
/* VERSION : 1.3                                                                                               */
/* DESCRIPTION : Interpreteur de commande                                            */
/* NOM FICHIER : tp5.c						                                                            */
/************************************************************************/


//Includes

#include "chaine4.h"
#include "chaine5.h"
#define MAX 5

void menu();

int main()
{

//    char cde[MAX] ; // permet de saisir une commande
    Tchaine s1,s2; // Chaines de caracteres
                     /*0   4   8   12  16  20    24   28   32   36  */
//    char liste_cdes[]="pre-sfp-phr-der-sfd-mir-mmb-eff-hlp-fin"; //Definie la liste des commandes de l'interpreteur
    int termine=FAUX ;
    int pos ; // variable correspondant a la position de "cde" dans "liste_cdes"

    do
    {

        menu() ; // Affiche la liste des commandes (a realiser)
        printf("Choix : ");
        scanf("%d", &pos);
        // flush
        fgets(s1, 2, stdin);
        //saisir la commande et calculer sa position dans la liste des commandes

        switch (pos)
        {
            case 0 : //Commande premier (pre)

              break ;

            case 4 : //Commande saufpremier (sfp)

              break ;

            case 8 : //Commande phrase (phr)

                // A completer

              break ;

            case 12 : //Commande dernier (der)

              printf("Tapez une premiere chaine de caracteres (s1) : ");
              fgets(s1, MAXCAR, stdin); format(s1);
              printf("dernier = '%s'\n", dernier(s2, s1));
              break ;

            case 16 : //Commande saufdernier (sfd)

              printf("Tapez une premiere chaine de caracteres (s1) : ");
              fgets(s1, MAXCAR, stdin); format(s1);
              printf("sauf dernier = '%s'\n", saufdernier(s2, s1));
              break ;

            case 20: //Commande miroir (mir)

              printf("Tapez une premiere chaine de caracteres (s1) : ");
              fgets(s1, MAXCAR, stdin); format(s1);
              printf("mirroir = '%s'\n", mirroir(s2, s1));
              break ;

            case 24 : //Commande member (mmb)

              printf("Tapez une premiere chaine de caracteres (s1) : ");
              fgets(s1, MAXCAR, stdin); format(s1);
              printf("Tapez une premiere chaine de caracteres (s2) : ");
              fgets(s2, MAXCAR, stdin); format(s2);
              printf("isMatch = '%d'\n", member(s2, s1));
              break ;

            case 28 : //Commande effacer (eff)

              printf("Tapez une premiere chaine de caracteres (s1) : ");
              fgets(s1, MAXCAR, stdin); format(s1);
              printf("Tapez une premiere chaine de caracteres (s2) : ");
              fgets(s2, MAXCAR, stdin); format(s2);
              printf("invert regex = '%s'\n", efface(s2, s1));
              break ;

            case 32 :
              break ;

            case 36 :
              termine=VRAI;
              break ;

            default :
              printf("\007\007 Cde inconnue. Recommencez !!!\n") ;
        }
    }

    while (!termine) ;

}


void menu()
{
  printf("\n0 - Commande premier (pre)\n");
  printf("4 - Commande saufpremier (sfp)\n");
  printf("8 - Commande phrase (phr)\n");
  printf("12 - Commande dernier (der)\n");
  printf("16 - Commande saufdernier (sfd)\n");
  printf("20 - Commande miroir (mir)\n");
  printf("24 - Commande member (mmb)\n");
  printf("28 - Commande effacer (eff)\n");
  printf("32 - Ecrire ce menu\n");
  printf("36 - Quitter le programme\n\n");
}
