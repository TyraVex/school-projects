# include <stdio.h>
# include <sys/time.h>

// get time in microseconds
unsigned long getTime(){

  struct timeval currentTime;
  gettimeofday(&currentTime, NULL);
  return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;

}


// main function
int main (void)
{

  // variable initialisations
  int arrayLength, tries = 0, i, j, minimum, swap;
  unsigned long chrono, time;
  char answer;

  // aking for manual or random input method
  printf("\n");
  do
  {
    printf("Use random array values ? : ");
    scanf(" %c", &answer);
    tries++;
  }
  while((answer != 'y' && answer != 'n' && answer != 'Y' && answer != 'N') && tries < 3);

  if (answer == 'y' || answer == 'Y')
  {

     printf("Generating array with random values...\n\n");
     return 1;

  }
  else if (answer == 'n' || answer == 'N')
  {

    // asking the array length
    printf("\n");
    tries = 0;
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
    int array[arrayLength], arrayBak[arrayLength];
    tries = 0;

    // asking the array values
    printf("\n");
    for (i = 0; i < arrayLength; i++)
    {
      printf("Array value at index %d : ", i);
      scanf("%d", &array[i]);
      arrayBak[i] = array[i];
      tries++;
    }

  }
  else
  {

     printf("Wrong input. Cancelling...\n\n");
     return 1;

  }


  int array[0], arrayBak[0];

  // print the array
  printf("\n\e[31mARRAY VALUES :\e[0m\n\n");
  for (i = 0; i < arrayLength; i++)
  {
    printf("array[%d]=%d\n", i, array[i]);
  }
  printf("\n");

  // SELECTION SORT
  chrono = getTime();
  for (i = 0; i < arrayLength-1; i++)
  {

    // scan array for minimum
    minimum = i;
    for (j = i+1; j < arrayLength; j++)
    {
      if (array[j] < array[minimum]) { minimum = j; }
    }

    // swap a new minimum if found
    if (minimum != i)
    {
      swap = array[minimum];
      array[minimum] = array[i];
      array[i] = swap;
    }

  }
  time = getTime() - chrono;

  // print the sorted values
  printf("\e[31mSELECTION SORT : \e[0m\n\n");
  for (i = 0; i < arrayLength; i++)
  {
    printf("array[%d]=%d\n", i, array[i]);
  }
  printf("\n\e[32mDone in %lu µs\e[0m\n\n", time);

  // restore unsorted array
  for (i = 0; i < arrayLength; i++)
  {
    array[i] = arrayBak[i];
  }

  // BUBBLE SORT
  chrono = getTime();
  for (i = 0; i < arrayLength; i++)
  {
    for (j = 0; j < arrayLength-1; j++)
    {

      // swap adjacent unsorted values
      if (array[j] > array[j+1])
      {
        swap = array[j+1];
        array[j+1] = array[j];
        array[j] = swap;
      }
    }
  }
  time = getTime() - chrono;

  // print the sorted values
  printf("\e[31mBUBBLE SORT : \e[0m\n\n");
  for (i = 0; i < arrayLength; i++)
  {
    printf("array[%d]=%d\n", i, array[i]);
  }
  printf("\n\e[32mDone in %lu µs\e[0m\n\n", time);

  // restore unsorted array
  for (i = 0; i < arrayLength; i++)
  {
    array[i] = arrayBak[i];
  }

  // INSERTION SORT
  chrono = getTime();
  for (i = 1; i < arrayLength; i++)
  {
    j = i;
    while (j > 0 && array[j-1] > array[j])
    {
      swap = array[j-1];
      array[j-1] = array[j];
      array[j] = swap;
      j = j - 1;
    }
  }
  time = getTime() - chrono;

  // print the sorted values
  printf("\e[31mINSERTION SORT : \e[0m\n\n");
  for (i = 0; i < arrayLength; i++)
  {
    printf("array[%d]=%d\n", i, array[i]);
  }
  printf("\n\e[32mDone in %lu µs\e[0m\n\n", time);

  return 0;

}
