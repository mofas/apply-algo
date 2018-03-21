#include <stdio.h>
#include <string.h>
#include <math.h>

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

int max(int a, int b)
{
  return a > b ? a : b;
}

int OPT(int priceList[], int n, int mem[])
{
  // mem[0] = priceList[0];

  // for ( i from 2 to n) {
  //       m = price_list[i]
  //       for ( j from 1 to i-1){
  //             m = max (m , price[j]+Mem[i-j])
  //       }
  //       Mem[i] = m
  // }
  // return Mem[n]

  if (n == 1)
  {
    mem[0] = priceList[0];
    return priceList[0];
  }
  else
  {
    if (mem[n - 1] >= 0)
    {
      // printf("read from cache: %d, %d\n", n, mem[n - 1]);
      return mem[n - 1];
    };

    int m = priceList[n - 1];
    for (int i = n; i > 0; i--)
    {
      for (int j = 1; j < i; j++)
      {
        // printf("i: %d, j: %d\n", i, j);
        m = max(m, priceList[j - 1] + OPT(priceList, i - j, mem));
      }
    }
    mem[n - 1] = m;
    return m;
  }
}

int main()
{

  int rodLength = 8;
  int priceList[] = {3, 4, 8, 9, 10, 17, 17, 20};
  int mem[rodLength];

  for (int i = 0; i < rodLength; i++)
  {
    mem[i] = -1;
  }

  int result = OPT(priceList, rodLength, mem);

  printArray(mem, rodLength);

  printf("Max Profit from cutting rod is : %d \n", result);
}
