#include <stdio.h>

int main()
{
  int i = 0;
  int sum = 0;
  int step = 200000;
  int loop_times = 1000000;

  int capacity = sizeof(int);
  printf("%d", capacity);
  for (i = 0; i < loop_times; i++)
  {
    sum += step;
  }
  printf("%d\t%d", sum, i);
  return 0;
}