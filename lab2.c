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

// Pseudo Code : input : array A
// BubbleSort(A)
// {
//   for (int j = 0; j < length(A); j++)
//     for (int i = 0; i < length(A) - 1 - j; i++)
//       if
//         A[i] > A[i + 1] /*for the jth time, let the jth largest element go to the tail*/
//             swap(A[i], A[i + 1])
// }

void BubbleSort(int arr[], int length)
{
  for (int j = 0; j < length; j++)
  {
    for (int i = 0; i < length - 1 - j; i++)
    {
      if (arr[i] > arr[i + 1])
      {
        swap(&arr[i], &arr[i + 1]);
      }
    }
  }
}

// Pseudo Code : input : array A
// InsertSort(A)
// {
//   int hold; /* get the element to be sorted( seeking a right place to place it)*/
//   for (int i = 1; i < length(A); i++)
//     hold = array[i]; /*get a copy of the element to be sorted*/

//   /*****find a position to insert that element*****/
//   /* if the current element, that is array[j-1] is larger than "hold", then move array[j-1] backward*/
//   /*leaving the position for "hold" or the element even smaller than "hold"*/

//   /* if the current element array[j-1]is smaller than "hold", since the elements before array[j-1] are already sorted,*/
//   /*just stop, since "hold" is already in the right place*/
//   /*repeat this process*/

//   for (int j = i; j > 0 and array[j - 1] > hold; j--)
//   {
//     array[j] = array[j - 1];
//   }
//   array[j] = hold;
// }

void InsertSort(int arr[], int length)
{
  int hold, j;
  for (int i = 1; i < length; i++)
  {
    hold = arr[i];
    j = i;
    while (j > 0 && arr[j - 1] > hold)
    {
      arr[j] = arr[j - 1];
      j--;
    }
    arr[j] = hold;
  }
}

void Merge(int array[], int begin, int mid, int end)
{
  /*first part of the array*/
  int p = begin;
  int end1 = mid;
  /*second part of the array*/
  int q = mid + 1;
  int end2 = end;

  int i = 0;
  int temp[end - begin];
  /* store the sorted two parts*/
  // foreach p < -begin1 to end1 and q < -begin2 to end2 if array[p] < array[q] copy array[p] to temp else copy array[q] to temp
  while (p <= end1 && q <= end2)
  {
    if (array[p] < array[q])
      temp[i++] = array[p++];
    else
      temp[i++] = array[q++];
  }

  /*deal with the last elements still left in the first or second part of array*/
  while (p <= end1)
    temp[i++] = array[p++];

  while (q <= end2)
    temp[i++] = array[q++];

  // copy each element in temp to array,
  // starting from index = low;
  for (int j = begin; j <= end; j++)
    array[j] = temp[j - begin];
}

void MergeSort(int array[], int begin, int end)
{
  if (begin < end)
  {
    int mid = (begin + end) / 2;
    MergeSort(array, begin, mid);
    MergeSort(array, mid + 1, end);
    Merge(array, begin, mid, end);
  }
}

int main()
{
  int arr1[] = {1, 5, 4, 3, 8, 2};
  int length1 = (int)(sizeof(arr1) / sizeof(arr1[0]));
  printf("Initial Array: ");
  printArray(arr1, length1);
  printf("After Bubble sort: ");
  BubbleSort(arr1, length1);
  printArray(arr1, length1);

  int arr2[] = {7, 6, 4, 3, 8, 2, 1, 5};
  int length2 = (int)(sizeof(arr2) / sizeof(arr2[0]));
  printf("Initial Array: ");
  printArray(arr2, length2);
  printf("After Insert sort: ");
  InsertSort(arr2, length2);
  printArray(arr2, length2);

  int arr3[] = {11, 5, 4, 3, 8, 2, 7, 9};
  int length3 = (int)(sizeof(arr3) / sizeof(arr3[0]));
  printf("Initial Array: ");
  printArray(arr3, length3);
  printf("After Merge sort: ");
  MergeSort(arr3, 0, length3 - 1);
  printArray(arr3, length3);
}