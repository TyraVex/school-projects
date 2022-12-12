#include <stdio.h>
#include <string.h>

int VIDE(char ch[])
{
  if (strlen(ch) == 0) return 1; // array is empty
  else return 0; // array is not empty
}

int EGAL(char ch1[], char ch2[])
{
  if (strcmp(ch1, ch2) == 0) return 1; // strings are equal
  else return 0; // strings are not equal
}

char *dernier(char mot[], const char ch[])
{
    // find the length of the input string
    int len = strlen(ch);
    // initialize an empty string
    mot[0] = '\0';

    // if the input string is empty, return the empty string
    if (len == 0)
    {
        return mot;
    }

    // find the last space in the input string
    int lastSpace = -1;
    for (int i = 0; i < len; i++)
    {
        if (ch[i] == ' ')
        {
            lastSpace = i;
        }
    }

    // if there is no space in the input string, return the entire string
    if (lastSpace == -1)
    {
        strcpy(mot, ch);
        return mot;
    }

    // otherwise, copy the last word to the output string using strcpy
    strcpy(mot, ch + lastSpace + 1);

    return mot;
}

char *saufdernier(char mot[], const char ch[])
{
    // find the last space in the input string
    int lastSpace = -1;
    for (int i = 0; i < (int)strlen(ch); i++)
    {
        if (ch[i] == ' ')
        {
            lastSpace = i;
        }
    }

    // if there is no space in the input string, return the empty string
    if (lastSpace == -1)
    {
        mot[0] = '\0';
        return mot;
    }

    // otherwise, copy all characters before the last space to the output string
    int i = 0;
    while (i < lastSpace && ch[i] != '\0')
    {
        mot[i] = ch[i];
        i++;
    }

    return mot;
}

char *mirroir(char mirch[], const char ch[])
{
    // get the length of the string
    int len = strlen(ch);
    // if the string is empty, return an empty string
    if (len == 0) {
        mirch[0] = '\0';
        return mirch;
    }

    // mirror the string by copying the characters from 'ch' in reverse
    for (int i = 0; i < len; i++) {
        mirch[i] = ch[len - 1 - i];
    }
    // set the null terminator
    mirch[len] = '\0';

    return mirch;
}

int member(const char ssch[], const char ch[])
{
  int ssch_len = strlen(ssch);
  int ch_len = strlen(ch);

  // iterate through each character in ch
  for (int i = 0; i < ch_len; i++) {
    // check if the current character in ch is the first character of ssch
    if (ch[i] == ssch[0]) {
      // check if the remaining characters in ch starting from this point match ssch
      int match = 1;
      for (int j = 0; j < ssch_len; j++) {
        if (ch[i + j] != ssch[j]) {
          match = 0;
          break;
        }
      }
      if (match) return 1;
    }
  }

  // if no match
  return 0;
}

char *efface(const char mot[], char ch[]) {
  // Set up an empty string that will be used to store the modified version of ch
  char *result = "";

  // Use strpos to find the position of the first occurence of mot in ch
  int pos = strpos(mot, ch);
  printf("Pos : %d\n", pos);

  // While a match was found
  while (pos >= 0) {
  printf("Match found\n");
    // Add the characters before the match to the result string
    printf("strcpy(%s + %ld, %s)\n", result, strlen(result), ch);
    strcpy(result + strlen(result), ch);
    result[strlen(result) + pos] = '\0';

    // Add the characters after the match to the result string, skipping over the matched string
    strcpy(result + strlen(result), ch + pos + strlen(mot));

    // Use strpos to find the next occurence of mot in ch
    pos = strpos(mot, ch);
  }

  // Return the modified version of ch
  return result;
}
