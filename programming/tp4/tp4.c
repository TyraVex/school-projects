# include <stdlib.h>
# include <stdio.h>
# define MAXCAR 80

char *format(char *ch)
{
    int i = 0, j;

    // skip white space at the beginning of the string
    while (ch[i] == ' ') {
        i++;
    }

    // traverse the whole string from end
    for (j = 0; ch[j + i] != '\0'; j++)
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

int strpos(char *mot, char *ch)
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

char *strmin(char *ch)
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

char *premier(char *mot, char *ch)
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

char *saufpremier(char *restch, char *ch)
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

char *phrase(char *dest, char *src)
{
    // dest = dest + src
    int i = 0, j = 0;
    while (dest[i])
    {
        i++;
    }
    dest[i] = ' ';
    i++;
    while (src[j] && i < MAXCAR)
    {
        dest[i] = src[j];
        i++; j++;
    }
    // add a null character at the end
    if (i+1 == MAXCAR) dest[i-1] = '\0';
    else dest[i] = '\0';
    return dest;
}

void printArray(const char* ch)
{
    int i = 0;
    printf("'");
    // for all the characters in the array
    while (ch[i]) {
        // for all the character
        printf("%c", ch[i]);
        i++;
    }
    printf("'\n");
}


int main()
{
    int opt, i;
    char Tchaine[MAXCAR];
    char auxTab[MAXCAR];

    while(1)
    {

        // print the menu
        printf("\nSelect an option :\n\n");
        printf("1 - Format a string\n");
        printf("2 - Search for a string\n");
        printf("3 - Convert a string to minuscules\n");
        printf("4 - Output the first word of a string\n");
        printf("5 - Output everything exept the first word of a string\n");
        printf("6 - Concatinate two arrays\n");
        printf("7 - Exit the program\n");
        printf("\nOption : ");
        scanf("%d", &opt);
        // flush stdin
        fgets(Tchaine, 2, stdin);
        printf("\n");

        switch (opt)
        {

            case 1:
                printf("Enter a string to format : ");
                fgets(Tchaine, MAXCAR, stdin);
                i = 0; while (Tchaine[i]!='\n') i++;
                Tchaine[i] = '\0';
                printf("Formatted result : ");
                printArray(format(Tchaine));
                break;

            case 2:
                printf("Enter a string to perform the search on : ");
                fgets(Tchaine, MAXCAR, stdin);
                i = 0; while (Tchaine[i]!='\n') i++;
                Tchaine[i] = '\0';
                printf("Enter a string to search the index of its position : ");
                fgets(auxTab, MAXCAR, stdin);
                i = 0; while (auxTab[i]!='\n') i++;
                auxTab[i] = '\0';
                printf("Position of match : %d\n", strpos(auxTab, Tchaine));
                break;

            case 3:
                printf("Enter a string to convert in lowercases : ");
                fgets(Tchaine, MAXCAR, stdin);
                i = 0; while (Tchaine[i]!='\n') i++;
                Tchaine[i] = '\0';
                printf("In lowercases : ");
                printArray(strmin(Tchaine));
                break;

            case 4:
                printf("Enter a string to output its first word : ");
                fgets(Tchaine, MAXCAR, stdin);
                i = 0; while (Tchaine[i]!='\n') i++;
                Tchaine[i] = '\0';
                printf("First word : ");
                printArray(premier(auxTab, Tchaine));
                break;

            case 5:
                printf("Enter a string to output everything exept its first word : ");
                fgets(Tchaine, MAXCAR, stdin);
                i = 0; while (Tchaine[i]!='\n') i++;
                Tchaine[i] = '\0';
                printf("Everything exept the first word : ");
                printArray(saufpremier(auxTab, Tchaine));
                break;

            case 6:
                printf("Enter string number 1 : ");
                fgets(auxTab, MAXCAR, stdin);
                i = 0; while (auxTab[i]!='\n') i++;
                auxTab[i] = '\0';
                printf("Enter string number 2 : ");
                fgets(Tchaine, MAXCAR, stdin);
                i = 0; while (Tchaine[i]!='\n') i++;
                Tchaine[i] = '\0';
                printf("Concatinated arrays : ");
                printArray(phrase(auxTab, Tchaine));
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice. Please try again\n");
                break;

        }

    }

    return 0;

}
