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

int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }

void float_down(int a[], int i, int length)
{
  int max = i;
  int l = left(i);
  int r = right(i);
  if (l < length && a[l] > a[max])
    max = l;

  if (r < length && a[r] > a[max])
    max = r;

  if (max != i)
  {
    swap(&a[i], &a[max]);
    float_down(a, max, length);
  }
}

void build_max_heap(int a[], int length)
{
  // pseudo code is confusing.. just using length / 2 - 1 instead of parent(i)
  for (int i = length / 2 - 1; i >= 0; i--)
  {
    float_down(a, i, length);
  }
}

void Heap_sort(int a[], int length)
{
  build_max_heap(a, length);

  for (int i = length - 1; i >= 1; i--)
  {
    swap(&a[0], &a[i]);
    //heap_size is i actually.
    float_down(a, 0, i);
  }
}

int main()
{

  int arr[] = {7, 6, 4, 10, 3, 11, 8, 2, 9, 1, 5};
  int length = (int)(sizeof(arr) / sizeof(arr[0]));

  printf("Initial Array: ");
  printArray(arr, length);
  Heap_sort(arr, length);
  printf("After Heap sort: ");
  printArray(arr, length);
}
