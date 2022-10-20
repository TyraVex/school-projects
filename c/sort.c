# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/ioctl.h>

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
  printTime(time);
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
  printTime(time);
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
  printTime(time);
  return time;

}


// main function
int main (void)
{

  // variable initialisations
  int arraySizes[50];
  int arrayLength, arraySizesLength = sizeof(arraySizes) / sizeof(arraySizes[0]);
  int i, j, tries;
  int Xsteps, Ysteps, Xmax, Ymax, Xscale, Yscale;
  for (i = 0; i < arraySizesLength; i++) { arraySizes[i] = i * 200 + 1000; };
  char answer;

  struct winsize size;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);

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

    // initialise procedure
    printf("\e[A\e[2K\e[A\e[2K");
    int array[arraySizes[arraySizesLength-1]], arrayBak[arraySizes[arraySizesLength-1]];
    int k = 0;
    unsigned long times[arraySizesLength*3];

    for (j = 0; j < arraySizesLength; j++)
    {

      // generate a random array
      for (i = 0; i < arraySizes[j]; i++)
      {
        array[i] = rand() % 10000;
        arrayBak[i] = array[i];
      }

      // print the array
      printf("\e[33mSIZE OF ARRAY : %d\e[0m\n", arraySizes[j]);
      printArray(array, arrayLength);

      // INSERTION SORT
      times[k] = insertionSort(array, arraySizes[j]); k++;

      // SELECTION SORT
      times[k] = selectionSort(array, arraySizes[j]); k++;
      for (i = 0; i < arraySizes[j]; i++) { array[i] = arrayBak[i]; }

      // BUBBLE SORT
      times[k] = bubbleSort(array, arraySizes[j]); k++;
      for (i = 0; i < arraySizes[j]; i++) { array[i] = arrayBak[i]; }

    }

    // tab representation
    printf("\n\e[31mRECAP (in µs) :\e[0m \n");
    for (i = 0; i < k; i = i + 3) { printf ("%8lu, %8lu, %8lu\n", times[i], times[i+1], times[i+2]); }

    // graphic representation

    // determine the maximum values for x and y
    Xmax = arraySizes[arraySizesLength-1];
    Ymax = times[arraySizesLength*3-1];
    // determine the number of steps for axis graduation
    Xsteps = (size.ws_col - 16) / 8;
    Ysteps = (size.ws_row - 8) / 3;
    // determine the scale
    Xscale = Xmax / (size.ws_col - 16) * 1.05;
    Yscale = Ymax / (size.ws_row - 8);

    // print the two axis and legend
    printf("\n\n\n\e[%dCY : Time in ms | X : Array size | \e[32mInsertion sort\e[0m | \e[33mSelection sort\e[0m | \e[31mBubble sort\e[0m\n", (size.ws_col - 79) / 2);
    printf("\n     Y ^"); for (i = 0; i < size.ws_row - 8; i++) { printf("\n       │"); }
    printf("\n       └");   for (i = 0; i < size.ws_col - 16; i++) { printf("─"); }
    printf(">  X\n");       for (i = 0; i <= Xsteps; i++) { printf("\e[C%7d\e[2D\e[A┴\e[B\e[C", i * Xmax / Xsteps); }
    printf("\n\e[2A\e[7C\e[s\e[7D");  for (i = 0; i <= Ysteps; i++) { printf("%6d ┼\e[10D\e[\e[3A", i * Ymax / Ysteps / 1000); }

//    printf("\e[0m\e[100B\n");
//    printf("Xmax : %d\n", Xmax);
//    printf("Ymax : %d\n", Ymax);
//    printf("Xsteps : %d\n", Xsteps);
//    printf("Ysteps : %d\n", Ysteps);
//    printf("Xscale : %d\n", Xscale);
//    printf("Yscale : %d\n", Yscale);

    // print the points
    j = 0;
    for (i = 0; i < k; i = i + 3)
    {
      printf ("\e[u\e[%dC\e[%luA\e[33m+", arraySizes[j] / Xscale, times[i] / Yscale);
      printf ("\e[u\e[%dC\e[%luA\e[31m+", arraySizes[j] / Xscale, times[i+1] / Yscale);
      printf ("\e[u\e[%dC\e[%luA\e[32m+", arraySizes[j] / Xscale, times[i+2] / Yscale);
//      printf ("x : %d, y : %lu\n", arraySizes[j] / Xscale, times[i] / Yscale);
//      printf ("x : %d, y : %lu\n", arraySizes[j] / Xscale, times[i+1] / Yscale);
//      printf ("x : %d, y : %lu\n", arraySizes[j] / Xscale, times[i+2] / Yscale);
      j++;
    }

    printf("\e[0m\e[100B\n");
    return 0;

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
    for (i = 0; i < arrayLength; i++)
    {
      array[i] = rand() % 10000;
      arrayBak[i] = array[i];
    }
  }

  // print the array
  printf("\n\e[31mARRAY VALUES :\e[0m\n\n");
  printArray(array, arrayLength);

  // SELECTION SORT
  printTime(selectionSort(array, arrayLength));

  // restore unsorted array
  for (i = 0; i < arrayLength; i++) { array[i] = arrayBak[i]; }

  // BUBBLE SORT
  printTime(bubbleSort(array, arrayLength));

  // restore unsorted array
  for (i = 0; i < arrayLength; i++) { array[i] = arrayBak[i]; }

  // INSERTION SORT
  printTime(insertionSort(array, arrayLength));

  return 0;

}
