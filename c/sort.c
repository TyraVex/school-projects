# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <sys/ioctl.h>


// function to get time in microseconds
unsigned long getTime()
{
  struct timeval currentTime;
  gettimeofday(&currentTime, NULL);
  return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}


// function for asking array length
int askArrayLength(int answer)
{

  // variables
  int scanfCheck, arrayLength, tries = 0;

  while (1)
  {

    // ask array length
    printf("\nArray length : ");
    scanfCheck = scanf("%d", &arrayLength);
    tries++;

    // input processing
    if (tries != 3 && ((scanfCheck != 1 && answer == 1) || (answer == 1 && (arrayLength > 20 || arrayLength < 1))))
    {
      printf("\n\e[31mERROR : Please provide a value between 0 and 20\e[0m\n");
      getchar();
    }
    else if (tries != 3 && (scanfCheck != 1 || arrayLength < 1))
    {
      printf("\n\e[31mERROR : Please provide an integer greater or equal than 0\e[0m\n");
      getchar();
    }
    else if ((answer == 1 && (arrayLength <= 20 || arrayLength > 0)) || arrayLength > 0)
    {
      return arrayLength;
    }
    else if (tries == 3)
    {
      printf("\n\e[31mERROR : Too many invalid inputs\e[0m\n\n");
      exit(1);
    }

  }

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
  else if (arrayLength > 20 && arrayLength <= 100)
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
  else if (arrayLength > 100)
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
    printf("\e[33m%lu µs\e[0m\n", time);
  }
  else if (time < 1000000)
  {
    printf("\e[33m%.2f ms\e[0m\n", time / 1000.00);
  }
  else if (time < 1000000000)
  {
    printf("\e[33m%.2f s\e[0m\n", time / 1000000.00);
  }

}


// function for bubble sorting
unsigned long bubbleSort(int* array, int arrayLength, int loglevel)
{

  // variables
  int i, j, swap;
  unsigned long chrono, time;
  chrono = getTime();

  // sorting
  for (i = 0; i < arrayLength; i++)
  {
    for (j = 0; j < arrayLength - 1; j++)
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
  printf("\e[31mBUBBLE SORT : \e[0m"); printTime(time);
  if (loglevel == 1) { printArray(array, arrayLength); }

  return time;

}


// function for selection sorting
unsigned long selectionSort(int* array, int arrayLength, int loglevel)
{

  // variables
  int i, j, swap, minimum;
  unsigned long chrono, time;
  chrono = getTime();

  // sorting
  for (i = 0; i < arrayLength - 1; i++)
  {

    // scan array for minimum
    minimum = i;
    for (j = i + 1; j < arrayLength; j++)
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
  printf("\e[31mSELECTION SORT : \e[0m"); printTime(time);
  if (loglevel == 1) { printArray(array, arrayLength); }

  return time;

}


// function for insertion sorting
unsigned long insertionSort(int* array, int arrayLength, int loglevel)
{

  // variables
  int i, j, swap;
  unsigned long chrono, time;
  chrono = getTime();

  // sorting
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
  printf("\e[31mINSERTION SORT : \e[0m"); printTime(time);
  if (loglevel == 1) { printArray(array, arrayLength); }

  return time;

}


// MAIN FUNCTION
int main (void)
{

  // variables
  int arrayLength, tries, answer, scanfCheck, testNum, loglevel, i = 0, j = 0;
  int arraySizes[75], arraySizesLength, arrayHighestSize;
  int Xsteps, Ysteps, Xmax, Ymax, Xscale, Yscale;


  // initlisation
  arraySizesLength = sizeof(arraySizes) / sizeof(arraySizes[0]);
  for (i = 0; i < arraySizesLength; i++) { arraySizes[i] = i * 50 + 100; };
  arrayHighestSize = arraySizes[arraySizesLength-1];
  unsigned long times[arraySizesLength*3-1];


  // print menu
  printf("\n1 - Input an array manually\n");
  printf("2 - Generate a random array\n");
  printf("3 - Generate multiple random arrays of different sizes\n");


  // ask answer
  tries = 0;
  while (1)
  {

    // get answer
    printf("\nChoice : ");
    scanfCheck = scanf("%d", &answer);
    tries++;

    // input processing
    if (tries != 3 && (scanfCheck != 1 || (answer != 1 && answer != 2 && answer != 3)))
    {
      printf("\n\e[31mERROR : Wrong input\e[0m\n");
      getchar();
    }
    if (answer == 1 || answer == 2)
    {
      arrayLength = askArrayLength(answer);
      arraySizes[0] = arrayLength;
      loglevel = 1;
      break;
    }
    else if (answer == 3)
    {
      arrayLength = arrayHighestSize;
      loglevel = 0;
      break;
    }
    else if (tries == 3)
    {
      printf("\n\e[31mERROR : Too many invalid inputs\e[0m\n\n");
      return 1;
    }

  }


  // array declaration
  int array[arrayLength], arrayBak[arrayLength];


  for (testNum = 0; testNum < arraySizesLength; testNum++)
  {

    // if option 'Input an array manually' is selected
    if (answer == 1)
    {

      printf("\n");
      for (i = 0; i < arrayLength; i++)
      {
        // ask the array values
        printf("Array value at index %d : ", i);
        scanfCheck = scanf("%d", &array[i]);

        // input processing
        if (scanfCheck != 1)
        {
          printf("\n\e[31mERROR : Wrong input\e[0m\n");
          exit(1);
        }
        arrayBak[i] = array[i];
        tries++;
      }

    }


    // if option 'Generate a random array' or 'Generate multiple random arrays' is selected
    if (answer == 2 || answer == 3)
    {
      // generate a random array
      for (i = 0; i < arraySizes[testNum]; i++)
      {
        array[i] = rand() % 10000;
        arrayBak[i] = array[i];
      }
    }


    // print the array
    printf("\n\e[32mARRAY SIZE : %d\e[0m\n", arraySizes[testNum]);
    if (loglevel == 1) { printArray(array, arraySizes[testNum]); }

    // bubble sort
    times[j] = bubbleSort(array, arraySizes[testNum], loglevel); j++;
    for (i = 0; i < arraySizes[testNum]; i++) { array[i] = arrayBak[i]; }

    // selection sort
    times[j] = selectionSort(array, arraySizes[testNum], loglevel); j++;
    for (i = 0; i < arraySizes[testNum]; i++) { array[i] = arrayBak[i]; }

    // insertion sort
    times[j] = insertionSort(array, arraySizes[testNum], loglevel); j++;

    if (answer == 1 || answer == 2) { return 0; }

  }


  // get number of columns and rows
  struct winsize size;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);


  // table representation
  printf("\n\n\e[34mRECAP (in µs) :\e[0m \n\n");
  printf(" Array Size │     Bubble │  Selection │  Insertion\n");
  printf(" ───────────┼────────────┼────────────┼────────────\n");
  for (i = 0; i < testNum; i++)
  {
    printf ("%11d │%11lu │%11lu │%11lu\n", arraySizes[i], times[i*3], times[i*3+1], times[i*3+2]);
  }


  // graphic representation
  Xmax = arrayHighestSize;
  Ymax = times[arraySizesLength*3-3];
  Xsteps = (size.ws_col - 16) / 8;
  Ysteps = (size.ws_row - 8) / 3;
  Xscale = Xmax / (size.ws_col - 16) * 1.05;
  Yscale = Ymax / (size.ws_row - 8);

  // print the graph
  printf("\n\n\n\e[%dCY : Time in ms | X : Array size | \e[32mInsertion sort\e[0m | \e[33mSelection sort\e[0m | \e[31mBubble sort\e[0m\n", (size.ws_col - 79) / 2);
  printf("\n     Y ^"); for (i = 0; i < size.ws_row - 8; i++) { printf("\n       │"); }
  printf("\n       └");   for (i = 0; i < size.ws_col - 16; i++) { printf("─"); }
  printf(">  X\n");       for (i = 0; i <= Xsteps; i++) { printf("\e[C%7d\e[2D\e[A┴\e[B\e[C", i * Xmax / Xsteps); }
  printf("\n\e[2A\e[7C\e[s\e[7D");  for (i = 0; i <= Ysteps; i++) { printf("%6d ┼\e[10D\e[\e[3A", i * Ymax / Ysteps / 1000); }

  // print the points
  for (i = 0; i < testNum; i++)
  {
    printf ("\e[u\e[%dC\e[%luA\e[31m+", arraySizes[i] / Xscale, times[i*3] / Yscale);
    printf ("\e[u\e[%dC\e[%luA\e[33m+", arraySizes[i] / Xscale, times[i*3+1] / Yscale);
    printf ("\e[u\e[%dC\e[%luA\e[32m+", arraySizes[i] / Xscale, times[i*3+2] / Yscale);
  }

  printf("\e[%dB\n", size.ws_row);
  return 0;

}
