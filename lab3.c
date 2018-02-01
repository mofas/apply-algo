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

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
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

int randomizedPartition(int array[], int p, int r)
{
  int k = randRange(p, r);
  // int k = r;
  swap(&array[k], &array[r]);
  int x = array[r]; //pseudo code is WRONG!!!
  int i = p - 1;
  // printf("k=%d, x=%d, p=%d, i=%d\n", k, x, p, i);
  for (int j = p; j < r; j++)
  {
    if (array[j] <= x)
    {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[r]);
  return i + 1;
}

// RANDOMIZED_QUICK_SORT(A, p, r) : if p < r : q = RANDOMIZED_PARTITION(A, p, r)
// RANDOMIZED_QUICK_SORT(A, p, q - 1)
// RANDOMIZED_QUICK_SORT(A, q + 1, r)

void randomizedQucikSort(int array[], int p, int r)
{
  if (p < r)
  {
    int q = randomizedPartition(array, p, r);
    // printf("p=%d, q=%d r=%d\n", p, q, r);
    randomizedQucikSort(array, p, q - 1);
    randomizedQucikSort(array, q + 1, r);
  }
}

int main()
{
  srand(time(NULL)); // should only be called once

  int arr[] = {7, 6, 4, 3, 8, 2, 1, 5};
  int length = (int)(sizeof(arr) / sizeof(arr[0]));

  printf("Initial Array: ");
  printArray(arr, length);
  randomizedQucikSort(arr, 0, length - 1);
  printf("After Quick sort: ");
  printArray(arr, length);

  int bigArrLength = 100000;
  int bigArr[bigArrLength];
  for (int i = 0; i < bigArrLength; i++)
  {
    bigArr[i] = bigArrLength - i;
  }

  printf("Big Array: ");
  // printArray(bigArr, bigArrLength);
  randomizedQucikSort(bigArr, 0, bigArrLength - 1);
  printf("After Quick sort: ");
  // printArray(bigArr, bigArrLength);
}
