#include <stdio.h>
#include <string.h>
#include <math.h>

const int MATCH_CASE = 0;
const int DECREASE_FIRST_STRING = 1;
const int DECREASE_SECOND_STRING = 2;

// void printArray(int m, int n, int arr[][n])
// {
//   printf("[\n");
//   for (int i = 0; i < m; i++)
//   {
//     for (int j = 0; j < n; j++)
//     {
//       printf("%d", arr[i][j]);
//       printf(",");
//     }
//     printf("\n");
//   }
//   printf("]\n");
// }

void printPath(int m, int n, char seq[], int dn, int match[][dn])
{
  if (match[m][n] == MATCH_CASE)
  {
    printPath(m - 1, n - 1, seq, dn, match);
    printf("%c", seq[m]);
  }
  else if (match[m][n] == DECREASE_FIRST_STRING)
  {
    printPath(m - 1, n, seq, dn, match);
  }
  else if (match[m][n] == DECREASE_SECOND_STRING)
  {
    printPath(m, n - 1, seq, dn, match);
  }
}

int max(int a, int b)
{
  return a > b ? a : b;
}

int LCS(char x[], char y[], int m, int n, int dn, int cache[][dn], int match[][dn])
{
  int mi = m - 1, ni = n - 1;
  if (m == 0 || n == 0)
    return 0;

  if (cache[mi][ni] != -1)
  {
    return cache[mi][ni];
  }

  if (x[mi] == y[ni])
  {
    match[mi][ni] = MATCH_CASE;
    cache[mi][ni] = 1 + LCS(x, y, mi, ni, dn, cache, match);
    return cache[mi][ni];
  }
  else
  {
    int v1 = LCS(x, y, mi, n, dn, cache, match);
    int v2 = LCS(x, y, m, ni, dn, cache, match);
    if (v1 > v2)
    {
      match[mi][ni] = DECREASE_FIRST_STRING;
      cache[mi][ni] = v1;
    }
    else
    {
      match[mi][ni] = DECREASE_SECOND_STRING;
      cache[mi][ni] = v2;
    }

    return cache[mi][ni];
  }
}

int main()
{

  char x[] = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
  char y[] = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
  int m = strlen(x);
  int n = strlen(y);
  int cache[m][n];
  int match[m][n];
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cache[i][j] = -1;
      match[i][j] = -1;
    }
  }
  printf("Max Length of x & y: %d \n", LCS(x, y, m, n, n, cache, match));
  // printArray(m, n, match);
  printPath(m - 1, n - 1, x, n, match);
}
