#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

typedef struct node_struct
{
  int vertex;
  int cost;
} Node;

typedef struct edge_struct
{
  int u1;
  int u2;
  int cost;
} Edge;

const int INF = 9999999;

void PrintPath(int n, int *intermediate, int u, int v)
{
  int intUV = *((intermediate + u * n) + v);
  if (intUV == -1)
  {
    return;
  }

  if (intUV == v)
  {
    printf("%d ", v);
    return;
  }

  PrintPath(n, intermediate, u, intUV);
  PrintPath(n, intermediate, intUV, v);
};

// n is the number of nodes,  m is the number of edges.
void FloydWarshall(vector<Node> graph[], int V, int E)
{
  int D[V][V];
  int intermediate[V][V];

  //initialize all D[V][V] = INF
  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      D[i][j] = INF;
      intermediate[i][j] = -1;
    }
  }

  // For each i = 1 to V
  // 	D[i][i] = 0
  for (int i = 0; i < V; i++)
  {
    D[i][i] = 0;
  }

  // For each edge (u,v,weight)
  // 	D[u][v] = weight
  for (int u = 0; u < V; u++)
  {
    for (vector<Node>::iterator vi = graph[u].begin(); vi != graph[u].end(); ++vi)
    {
      D[u][vi->vertex] = vi->cost;
      intermediate[u][vi->vertex] = vi->vertex;
    }
  }

  // For k from 1 to V
  // 	For i from 1 to V
  // 		For j from 1 to V
  // 			IF D[i][j] > D[i][k] + D[k][j]
  // 				D[i][j] = D[i][k] + D[k][j]
  for (int k = 0; k < V; k++)
  {
    for (int i = 0; i < V; i++)
    {
      for (int j = 0; j < V; j++)
      {
        if (D[i][j] > D[i][k] + D[k][j])
        {
          D[i][j] = D[i][k] + D[k][j];
          intermediate[i][j] = k;
        }
      }
    }
  }

  // print cost from i to j
  // for (int i = 0; i < V; i++)
  // {
  //   for (int j = 0; j < V; j++)
  //   {
  //     printf("[%d,%d] = %d\n", i, j, D[i][j]);
  //   }
  // }

  // print all path from i to j
  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      if (i != j)
      {
        printf("Path from %d to %d : [ %d ", i, j, i);
        PrintPath(V, (int *)intermediate, i, j);
        printf("] with cost %d \n", D[i][j]);
      }
    }
  }
}

int main()
{
  vector<Node> graph[50];
  int n = 5;
  int u1, u2, cost;

  Edge edgeList[10] = {
      {0, 1, 10},
      {0, 3, 5},
      {1, 2, 1},
      {1, 3, 2},
      {2, 4, 4},
      {3, 1, 3},
      {3, 2, 9},
      {3, 4, 2},
      {4, 0, 7},
      {4, 2, 6}};

  for (int i = 0; i < 10; ++i)
  {
    u1 = edgeList[i].u1;
    u2 = edgeList[i].u2;
    cost = edgeList[i].cost;

    Node t;
    t.vertex = u2;
    t.cost = cost;
    graph[u1].push_back(t);
  }

  // // Test 2
  // Edge edgeList[5] = {
  //     {0, 1, 1},
  //     {1, 2, 1},
  //     {2, 3, 1},
  //     {3, 4, 1},
  //     {0, 4, 2},
  // };

  // for (int i = 0; i < 5; ++i)
  // {
  //   u1 = edgeList[i].u1;
  //   u2 = edgeList[i].u2;
  //   cost = edgeList[i].cost;

  //   Node t;
  //   t.vertex = u2;
  //   t.dist = cost;
  //   graph[u1].push_back(t);
  // }

  // // Test 3
  // n = 9;
  // Edge edgeList[14] = {
  //     {0, 1, 4},
  //     {0, 7, 8},
  //     {1, 2, 8},
  //     {1, 7, 11},
  //     {2, 3, 7},
  //     {2, 8, 2},
  //     {2, 5, 4},
  //     {3, 4, 9},
  //     {3, 5, 14},
  //     {4, 5, 10},
  //     {5, 6, 2},
  //     {6, 7, 1},
  //     {6, 8, 6},
  //     {7, 8, 7},
  // };
  // for (int i = 0; i < 14; ++i)
  // {
  //   u1 = edgeList[i].u1;
  //   u2 = edgeList[i].u2;
  //   cost = edgeList[i].cost;

  //   Node t;
  //   t.vertex = u2;
  //   t.dist = cost;
  //   graph[u1].push_back(t);
  // }

  FloydWarshall(graph, n, 10);

  return 0;
}
