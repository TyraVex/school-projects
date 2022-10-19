# include <stdio.h>
# include <sys/time.h>

unsigned long getMicrotime(){

  struct timeval currentTime;
  gettimeofday(&currentTime, NULL);
  return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;

}

int main (void)
{
  printf("%lu", getMicrotime());
}

