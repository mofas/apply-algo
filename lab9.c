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

void printCutPiece(int arr[], int n)
{
  int i = n;
  int m = 0;
  while (i > 0 && arr[i] != 0)
  {
    printf("%d, ", arr[i]);
    i -= arr[i];
    m += arr[i];
  }
  if (i > 0 && arr[i] == 0)
  {
    printf("%d ", i + 1);
  }
  else
  {
    printf("1 ");
  }
}

int max(int a, int b)
{
  return a > b ? a : b;
}

int OPT(int priceList[], int n, int mem[], int match[], int cost)
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
    match[0] = 0;
    return priceList[0];
  }
  else
  {
    if (mem[n - 1] >= 0)
    {
      return mem[n - 1];
    };

    int m = priceList[n - 1];
    for (int i = n; i > 0; i--)
    {
      for (int j = 1; j < i; j++)
      {
        int newResult = priceList[j - 1] + OPT(priceList, i - j, mem, match, cost) - cost;
        if (newResult > m)
        {
          m = newResult;
          match[n - 1] = j;
        }
      }
    }
    if (m == priceList[n - 1])
    {
      match[n - 1] = 0;
    }
    mem[n - 1] = m;
    return m;
  }
}

int main()
{

  int rodLength = 8;
  int priceList[] = {3, 4, 8, 9, 10, 17, 17, 20};
  int match[rodLength];
  int mem[rodLength];
  int cost = 1;

  for (int i = 0; i < rodLength; i++)
  {
    mem[i] = -1;
    match[i] = -1;
  }

  int result = OPT(priceList, rodLength, mem, match, cost);

  // printArray(mem, rodLength);
  // printArray(match, rodLength);

  printf("Max Profit from cutting rod is : %d \n", result);

  printf("We cut the rod by [ ");
  printCutPiece(match, rodLength - 1);
  printf("]\n\n");
}
