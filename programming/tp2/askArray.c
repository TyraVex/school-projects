# include <stdio.h>

int main (void)
{

  // variable initialisations
  int arrayLength, tries = 0, i;

  // asking the array length
  printf("\n");
  do
  {
    printf("Array length : ");
    scanf("%d", &arrayLength);
    tries++;
  }
  while ((arrayLength <= 0 || arrayLength > 20) && tries < 3);

  // input processing
  if (arrayLength < 1 || arrayLength > 20)
  {
    printf("Input failed to process\n");
    printf("Please input an integer between 1 and 20\n\n");
    return 1;
  }

  // create the array and reset tries
  int array[arrayLength];
  tries = 0;

  // asking the array values
  printf("\n");
  for (i = 0; i < arrayLength; i++)
  {
    printf("Array value at index %d : ", i);
    scanf("%d", &array[i]);
    tries++;
  }

  // print the array
  printf("\nArray values : \n\n");
  for (i = 0; i < arrayLength; i++)
  {
    printf("array[%d]=%d\n", i, array[i]);
  }
  printf("\n");
  return 0;

}
