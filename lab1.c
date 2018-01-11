#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifdef INFINITY
/* INFINITY is supported */
#endif

// Pseudo code:
//   int min = &infin /* in real code, you could assign a very large number to min*/
//   for a in array /*array stores the numbers you input*/
//       if a < min
//           min = a
//   print min

int main()
{
  int arr[] = {1, 5, 4, 3, 8, 2};
  for (int j = 0; j < 6; j++)
  {
    printf("Element[%d] = %d\n", j, arr[j]);
  }

  int min = INFINITY;
  for (int j = 0; j < 6; j++)
  {
    if (arr[j] < min)
    {
      min = arr[j];
    }
  }
  printf("The min is %d\n", min);
}