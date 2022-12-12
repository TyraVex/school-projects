/************************************************************************/
/* AUTEUR : A. TOGUYENI							*/
/* DATE : 05/01/2020							*/
/* FICHIER : chaine4.h						        */
/* DESCRIPTION : Entete de la bibliotheque de fonctions avancee de      */
/* traitement des chaines de caracteres                                 */
/************************************************************************/

#ifndef CHAINE4_H
#define CHAINE4_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  MAXCAR 	80
//Definitions de VRAI et FAUX si besoin 
#define	VRAI	1
#define	FAUX	0

typedef char Tchaine[MAXCAR+1];


/***************************************************************************/
/* NOM FONCTION : format						   */
/* DESCRIPTION :  Realise le formatage d'une chaine de manière a           */
/* ce qu'elle respecte les spécifications imposées au début de cet énoncé. */
/* Retourne :un pointeur sur la chaine lue			   	   */
/* Effets de bords : 			                                   */
/* Paramètres en entree : une variable pour recupere la chaine saisie	   */
/* Paramètres en sortie : la chaine modifiee    			   */
/***************************************************************************/
char * format(char * ch)
{
    int i = 0, j;

    // skip white space at the beginning of the string
    while (ch[i] == ' ') {
        i++;
    }

    // traverse the whole string from end
    for (j = 0; ch[j + i] != '\0' && ch[j + i] != '\n'; j++)
        ch[j] = ch[j + i];

    // remove trailing white space
    j--;
    while (ch[j] == ' ') {
        j--;
    }

    // set the new null character
    ch[j + 1] = '\0';

    return ch;
}


/***************************************************************************/
/* NOM FONCTION : strpos						   */
/* DESCRIPTION :  retourne la position du mot pointe par mot dans la chaine*/ 
/* pointee par ch                                                          */
/* Retourne : la position de mot 			   	           */
/* Effets de bords :                                    		   */
/* Paramètres en entree :  mot et ch                                       */
/* Paramètres en sortie :                                  		   */
/***************************************************************************/
int strpos(const char * mot, const char * ch)
{
    int i=0, j=0, flag=0, pos;
    while (ch[i])
    {
        // if there is a first match between ch[i] and mot[j]
        if (ch[i] == mot[j]) {
            pos=i;
//            printf("> Found first match between ch[%d]=%c and mot[%d]=%c\n", i, ch[i], j, mot[j]);
            // check if the rest of the characters of mot are matching with next characters of ch
            while (mot[j])
            {
//                printf("> Cheking ch[%d]=%c with mot[%d]=%c\n", i, ch[i], j, mot[j]);
                if (ch[i] != mot[j])
                {
//                    printf("> It's different! cancelling...\n");
                    flag=1;
                    break;
//                } else {
//                    printf("> It's matching! continuing...\n");
                }
                j++; i++;
            }
            // if match, return the position
            if (flag == 0) return pos;
            else flag=0;
        }
        i++;
    }
    return -1;
}


/***************************************************************************/
/* NOM FONCTION : strmin						   */
/* DESCRIPTION :  Elle convertit en miniscule les caractères de la chaine  */
/* pointée par ch.                                                         */
/* Retourne : Retourne un pointeur sur le début de cette chaine 	   */
/* Effets de bords :                                    		   */
/* Paramètres en entree : ch (avec des caracteres pouvant etre en majuscule*/
/* Paramètres en sortie : ch                                		   */
/***************************************************************************/
char * strmin(char * ch)
{
    int i = 0;
    // for all the characters in the array
    while (ch[i])
    {
        // if it is a majuscule
        if (ch[i] >= 'A' && ch[i] <= 'Z')
            // convert it into a minuscule
            ch[i] = ch[i] + 32;
        i++;
    }
    return ch;
}


/***************************************************************************/
/* NOM FONCTION : premier						   */
/* DESCRIPTION : Crée une chaine avec le premier mot de ch qui ne doit pas */
/* modifie.                                                                */
/* Retourne : Retourne un pointeur sur une chaine contenant le premier mot */
/* ou NULL si la chaine ch est vide                                        */
/* Effets de bords :                                    		   */
/* Paramètres en entree : ch chaine dont on veut extraire le premier mot   */
/* Paramètres en sortie : mot (chaine contenant le premier mot)            */
/***************************************************************************/
char *premier(char mot[],const char ch[])
{
    int i = 0;
    // for all the characters until a space or the end
    while (ch[i] != '\0' && ch[i] != ' ')
    {
        // copy the next characters to a new array
        mot[i]=ch[i];
        i++;
    }
    // add a null character at the end
    mot[i] = '\0';
    return mot;
}

/***************************************************************************/
/* NOM FONCTION : saufpremier						   */
/* DESCRIPTION : Crée une chaine avec tous les mots de ch sauf le premier  */
/* modifie.                                                                */
/* Retourne : Retourne un pointeur sur le reste de la chaine               */
/* ou NULL si la chaine ch est vide ou est composee d'un seul mot          */
/* Effets de bords :                                    		   */
/* Paramètres en entree : ch (chaine dont on veut extraire le premier mot) */
/* Paramètres en sortie : restch (chaine contenant le reste de ch)         */
/***************************************************************************/
char *saufpremier(char restch[], const char ch[])
{
    int i = 0, j = 0;
    // for all the characters until a space or the end
    while (ch[i] != ' ')
    {
        if (ch[i] == '\0')
        {
            restch[0] = '\0';
            return restch;
        }
        i++;
    }
    if (ch[i+1] != '\0') i++;
    // copy the next characters to a new array
    while (ch[i] != '\0')
    {
        restch[j]=ch[i];
        i++; j++;
    }
    // add a null character at the end
    restch[i-2] = '\0';
    return restch;
}

/***************************************************************************/
/* NOM FONCTION : phrase						   */
/* DESCRIPTION : Concatenation de ch et ch2 dans la limite des MAXCAR      */
/* caracteres. Le resutant est mis dans ch qui est modifie                 */
/* Retourne : Retourne un pointeur sur la chaine concatenee                */
/* ou NULL si ch et ch2 sont vides                                         */
/* Effets de bords :                                    		   */
/* Paramètres en entree : ch et ch2                                        */
/* Paramètres en sortie : ch qui contient les deux chaines concatenee      */
/***************************************************************************/
char *phrase (char * ch, const char * ch2)
{
    // ch = ch + ch2
    int i = 0, j = 0;
    while (ch[i])
    {
        i++;
    }
    ch[i] = ' ';
    i++;
    while (ch2[j] && i < MAXCAR)
    {
        ch[i] = ch2[j];
        i++; j++;
    }
    // add a null character at the end
    if (i+1 == MAXCAR) ch[i-1] = '\0';
    else ch[i] = '\0';
    return ch;
}


#endif
