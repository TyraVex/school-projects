# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>


// function to get time in microseconds
unsigned long getTime()
{
  struct timeval currentTime;
  gettimeofday(&currentTime, NULL);
  return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}


// function to print arrays in a convenient way
void printArray(int* array, int arrayLength)
{

  // if array is small
  if (arrayLength <= 20)
  {
    int i;
    for (i = 0; i < arrayLength; i++)
    {
      printf("array[%d]=%d\n", i, array[i]);
    }
    printf("\n");
  }

  // if array is regular
  else if (arrayLength > 20 && arrayLength <= 300)
  {
    int i;
    printf("[%d", array[0]);
    for (i = 1; i < arrayLength; i++)
    {
      printf(", %d", array[i]);
    }
    printf("]\n\n");
  }

  // if array is large
  else if (arrayLength > 300)
  {
    int i;
    printf("[%d", array[0]);
    for (i = 1; i < 3; i++)
    {
      printf(", %d", array[i]);
    }
    printf(", ...");
    for (i = arrayLength / 2 - 3; i < arrayLength / 2; i++)
    {
      printf(", %d", array[i]);
    }
    printf(", ...");
    for (i = arrayLength - 3; i < arrayLength; i++)
    {
      printf(", %d", array[i]);
    }
    printf("]\n\n");
  }

}

// function for selection sorting
unsigned long selectionSort(int* array, int arrayLength)
{

  int i, j, swap, minimum;
  unsigned long chrono, time;
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
  printArray(array, arrayLength);

  return time;

}


// function for bubble sorting
unsigned long bubbleSort(int* array, int arrayLength)
{

  int i, j, swap;
  unsigned long chrono, time;
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
  printArray(array, arrayLength);

  return time;

}


// function for insertion sorting
unsigned long insertionSort(int* array, int arrayLength)
{

  int i, j, swap;
  unsigned long chrono, time;
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
  printArray(array, arrayLength);

  return time;

}


// function to print sorting time in a convenient way
void printTime(unsigned long time)
{

  if (time < 1000)
  {
    printf("\e[32mDone in %lu µs\e[0m\n\n", time);
  }
  else if (time < 1000000)
  {
    printf("\e[32mDone in %.2f ms\e[0m\n\n", time / 1000.00);
  }
  else if (time < 1000000000)
  {
    printf("\e[32mDone in %.2f s\e[0m\n\n", time / 1000000.00);
  }

}

// main function
int main (void)
{

  // variable initialisations
  int arrayLength, tries, i;
  unsigned long chrono, time;
  char answer;


  // ask for manual or random input method
  printf("\n\n");
  tries = 0;
  do
  {
    printf("\e[A\e[2K1 - Input an array manually\n");
    printf("2 - Generate a random array\n");
    printf("3 - Generate multiple random arrays of different sizes\n\n");
    printf("Choice : ");
    scanf(" %c", &answer);
    printf("\e[A\e[2K\e[A\e[2K\e[A\e[2K\e[A\e[2K");
    tries++;
  }
  while((answer != '1' && answer != '2' && answer != '3') && tries < 3);


  // if wrong answer
  if (answer != '1' && answer != '2' && answer != '3')
  {
     printf("\e[A\e[2KWrong input. Cancelling...\n\n");
     return 1;
  }


  // if option 'input an array manually' is selected
  if (answer == '1')
  {

    // ask the array length
    tries = 0;
    do
    {
      printf("\e[A\e[2KArray length : ");
      scanf("%d", &arrayLength);
      tries++;
    }
    while ((arrayLength <= 0 || arrayLength > 20) && tries < 3);

    // input processing
    if (arrayLength < 1 || arrayLength > 20)
    {
      printf("\e[2K\nPlease input an integer between 1 and 20\n\n");
      return 1;
    }

  }


  // if option 'generate a random array' is selected
  if (answer == '2')
  {

    // ask the array length
    tries = 0;
    do
    {
      printf("\e[A\e[2KArray length : ");
      scanf("%d", &arrayLength);
      tries++;
    }
    while (arrayLength <= 0 && tries < 3);
    printf("\e[A\e[2K\e[A\e[2K");

    // input processing
    if (arrayLength <= 0)
    {
      printf("\e[2K\nPlease input a positive integer\n\n");
      return 1;
    }

  }


  // if option 'generate multiple random arrays' is selected
  if (answer == '3')
  {
    arrayLength = 5000;
    printf("\e[A\e[2K\e[A\e[2K");
  }


  // create the array and reset tries
  int array[arrayLength], arrayBak[arrayLength];
  tries = 0;


  // ask each value of array
  if (answer == '1')
  {

    // asking the array values
    for (i = 0; i < arrayLength; i++)
    {
      printf("\e[A\e[2KArray value at index %d : ", i);
      scanf("%d", &array[i]);
      arrayBak[i] = array[i];
      tries++;
    }
    printf("\e[A\e[2K\e[A\e[2K");

  }


  // generate the random array
  if (answer == '2')
  {
    chrono = getTime();
    for (i = 0; i < arrayLength; i++)
    {
      array[i] = rand() % 10000;
      arrayBak[i] = array[i];
    }
    time = getTime() - chrono;
  }


  // generate multiple random arrays
  if (answer == '3')
  {
    chrono = getTime();
    for (i = 0; i < arrayLength; i++)
    {
      array[i] = rand() % 10000;
      arrayBak[i] = array[i];
    }
    time = getTime() - chrono;
  }


  // print the array
  printf("\n\e[31mARRAY VALUES :\e[0m\n\n");
  printArray(array, arrayLength);
  printTime(time);


  // SELECTION SORT
  time = selectionSort(array, arrayLength);
  printTime(time);

  // restore unsorted array
  for (i = 0; i < arrayLength; i++)
  {
    array[i] = arrayBak[i];
  }


  // BUBBLE SORT
  time = bubbleSort(array, arrayLength);
  printTime(time);

  // restore unsorted array
  for (i = 0; i < arrayLength; i++)
  {
    array[i] = arrayBak[i];
  }


  // INSERTION SORT
  time = insertionSort(array, arrayLength);
  printTime(time);

  return 0;

}
