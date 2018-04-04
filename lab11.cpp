#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct edge_struct
{
  int u;
  int v;
  int cost;
} edge;

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

int compare(const void *a, const void *b)
{
  return (((edge *)a)->cost - ((edge *)b)->cost);
}

// MAKE_SET
// 	For all n
// 		parent[n] = n
void makeSet(int parent[], int len)
{
  for (int i = 0; i < len; i++)
  {
    parent[i] = i;
  }
}

// FIND_SET(n)
// 	While parent[n] is not equal to n
// 		n = parent[n]
int findSet(int parent[], int n)
{
  while (n != parent[n])
  {
    n = parent[n];
  }
  // union by rank: we need extra another array to save rank.
  // path compression
  return n;
}

// UNION(u, v)
// 	parent[FIND_SET(v)] = u
void unionSet(int parent[], int u, int v)
{
  int t = findSet(parent, v);
  parent[t] = u;
}

// KRUSKAL(G)
// 	For each vertex v
// 		MakeSet(v)
// 	Sort the graph edges into non-decreasing order by their weight
// 	cost = 0
// 	For each edge (u,v,weight) taken after the sorting
// 		IF FindSet(u) is not equal to FindSet(v)
// 			Mark/Print u, v as a minimum spanning tree edge
// 			UnionSet(u,v)
// 			cost += weight

int karskal(edge edgeList[], int parent[], int numEdge, int numNode)
{

  int u, v, weight;
  makeSet(parent, numNode);
  qsort(edgeList, numEdge, sizeof(edge), compare);
  int cost = 0;

  for (int i = 0; i < numEdge; ++i)
  {
    u = edgeList[i].u;
    v = edgeList[i].v;
    weight = edgeList[i].cost;
    if (findSet(parent, u) != findSet(parent, v))
    {
      unionSet(parent, u, v);
      cost += weight;
    }
  }
  return cost;
}

int main()
{
  int numEdge = 14;
  int numNode = 9;
  int parent[numNode];

  edge edgeList[14] = {
      {0, 1, 4},
      {0, 5, 8},
      {1, 2, 8},
      {1, 5, 11},
      {2, 6, 2},
      {2, 3, 7},
      {2, 8, 4},
      {3, 4, 9},
      {3, 8, 14},
      {4, 8, 10},
      {5, 6, 7},
      {5, 7, 1},
      {6, 7, 6},
      {7, 8, 2}};

  int minCost = karskal(edgeList, parent, numEdge, numNode);
  printf("The cost for MST is %d", minCost);
  return 0;
}
