# include <stdio.h>

int main (void)
{


  // variable initialisations
  int matrixLength, matrixHight, tries, i, j;


  // asking the matrix length
  printf("\n");
  tries = 0;
  do
  {
    printf("Matrix length : ");
    scanf("%d", &matrixLength);
    tries++;
  }
  while ((matrixLength <= 0 || matrixLength > 20) && tries < 3);

  // input processing
  if (matrixLength < 1 || matrixLength > 20)
  {
    printf("Input failed to process\n");
    printf("Please input an integer between 1 and 20\n\n");
    return 1;
  }


  // asking the matrix hight
  tries--;
  do
  {
    printf("Matrix hight : ");
    scanf("%d", &matrixHight);
    tries++;
  }
  while ((matrixHight <= 0 || matrixHight > 20) && tries < 3);

  // input processing
  if (matrixHight < 1 || matrixHight > 20)
  {
    printf("Input failed to process\n");
    printf("Please input an integer between 1 and 20\n\n");
    return 1;
  }


  // create the matrix and reset tries
  int matrix[matrixHight][matrixLength];
  tries = 0;


  // asking the matrix values
  printf("\n");
  for (i = 0; i < matrixHight; i++)
  {
    for (j = 0; j < matrixLength; j++)
    {
      printf("Matrix value at row %d, column %d : ", i, j);
      scanf("%d", &matrix[i][j]);
      tries++;
    }
  }


  // print the matrix
  printf("\nMatrix representation : \n\n");
  for (i = 0; i < matrixHight; i++)
  {
    printf("[%d", matrix[i][0]);
    for (j = 1; j < matrixLength; j++)
    {
      printf(", %d", matrix[i][j]);
    }
    printf("]\n");
  }
  printf("\n");
  return 0;


}
