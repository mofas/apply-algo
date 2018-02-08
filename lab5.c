#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node_struct
{
  double d;
  struct node_struct *next;
} node;

void printArray(double arr[], int length)
{
  printf("[");
  for (int i = 0; i < length; i++)
  {
    printf("%f", arr[i]);
    if (i < length - 1)
    {
      printf(",");
    }
  }
  printf("]\n");
}

void generateRandomNumbers(double a[], int n)
{
  int i;
  for (i = 0; i < n; ++i)
  {
    a[i] = rand() / (double)RAND_MAX;
  }
}

void insert(double value, int index, node *B[])
{
  // This function insert a new node with value into the B[index] linked list. The function
  // inserts the new node in the correct place of the linked list so that the link list is sorted
  node *t;
  if (B[index] == NULL)
  {
    // No elements in the linked list, create and insert the node at the beginning of the list
    t = (node *)malloc(sizeof(node));
    t->d = value;
    t->next = NULL;
    B[index] = t;
  }
  else
  {
    // Take two pointers p0 and p1. p0 always stays one node behind p1
    // The new node t will be inserted either on the end of the linked list
    // or before a node that has a value greater than the new node value.
    node *p0, *p1;
    p0 = B[index];
    p1 = p0->next;

    // PSEUDO CODE MISS this PART..
    if (p0->d > value)
    {
      t = (node *)malloc(sizeof(node));
      t->d = value;
      t->next = p0;
      B[index] = t;
    }
    else
    {
      while (p1 != NULL)
      {
        if (p1->d > value)
        {
          break;
        }
        // Advance both node pointer one node ahead to compare with next element in the linked list
        p1 = p1->next;
        p0 = p0->next;
      }
      // Create new node t and insert at the appropriate place
      t = (node *)malloc(sizeof(node));
      t->d = value;
      t->next = p1;
      p0->next = t;
    }
  }
}

// BUCKET-SORT(A)
// 	let B[0...n-1] be a new array
// 	n = A.length
// 	for i = 0 to n-1
// 		make B[i] an empty list
// 	for i = 1 to n
// 		insert A[i] into the slot B[index] in sorted order using insertion sort, where index=floor(n*A[i])
// 	print out the list values of B[0...n-1] to output the sorted numbers

void BuckerSort(double a[], int length)
{
  int i;
  int index;
  node *B[length];
  for (i = 0; i < length; i++)
    B[i] = NULL;

  for (i = 1; i <= length; i++)
  {
    index = floor(length * a[i]);
    insert(a[i], index, B);
  }
  // well, here we put the sorted number back to array.

  index = 0;
  for (i = 0; i < length; i++)
  {
    node *t = B[i];
    while (t != NULL)
    {
      printf("%d, %f\n", i, t->d);
      a[index++] = t->d;
      t = t->next;
    }
  }
}

void generateAndTest(int length)
{
  double arr[length];
  generateRandomNumbers(arr, length);

  printf("Initial Array: ");
  printArray(arr, length);

  printf("\n");

  BuckerSort(arr, length);
  printf("After Bucker sort: ");
  printArray(arr, length);

  printf("\n\n");
}

int main()
{
  generateAndTest(10);
  generateAndTest(20);
  generateAndTest(30);
}
