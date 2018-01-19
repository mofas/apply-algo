#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int length)
{
  printf("[");
  for (int i = 0; i < length; i++)
  {
    printf("%d", arr[i]);
    if (i < length - 1)
    {
      printf(",");
    }
  }
  printf("]\n");
}

int randRange(int from, int to)
{
  int r = rand();
  r = r % (to - from + 1);
  r = r + from;
  return r;
}

// RANDOMIZED_PARTITION(A,p,r):
//   k = Rand(p,r)  //pick a random pivot index between p and r
//   swap(A[k],A[r]) // put the pivot at the end of the subarray
//   x = A[k]
//   i = p - 1
//   for j = p to i:
// {
//   if (A[j] <= x):
//       i = i + 1
//       swap(A[i],A[j])
// }
// swap(A[i + 1], A[r]) return i + 1 // return the new postion of the pivot element

void randomizedPartition(int array[], int p, int r)
{
}

// RANDOMIZED_QUICK_SORT(A, p, r) : if p < r : q = RANDOMIZED_PARTITION(A, p, r)
// RANDOMIZED_QUICK_SORT(A, p, q - 1)
// RANDOMIZED_QUICK_SORT(A, q + 1, r)

void randomizedQucikSort(int array[], int p, int r)
{
}

int main()
{
  srand(time(NULL)); // should only be called once

  // for (int i = 0; i < 100; i++)
  //   printf("%d\n", randRange(1, 3));
}
