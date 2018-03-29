#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

typedef struct edge_struct
{
  int u;
  int v;
} edge;

void DFS(int u, int visited[], vector<int> graph[])
{
  // printf("DFS: %d\n", u);
  visited[u] = 1;
  for (vector<int>::iterator vi = graph[u].begin(); vi != graph[u].end(); ++vi)
  {
    if (visited[*vi] == 0)
    {
      DFS(*vi, visited, graph);
    }
  }
}

void checkConnected(int u, int v, vector<int> graph[])
{
  int verticesNo = 10;
  int visited[verticesNo];

  //Fill up array visited[100] with zeros
  for (int i = 0; i < verticesNo; i++)
  {
    visited[i] = 0;
  }

  DFS(u, visited, graph);

  if (visited[v] == 1)
  {
    printf("Vertices %d and %d are connected.\n", u, v);
  }
  else
  {
    printf("Vertices %d and %d are not connected.\n", u, v);
  }
}

int main()
{
  int u, v;

  vector<int> graph[50];

  edge listOfEdges[10] = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {7, 6}, {6, 8}, {8, 9}, {9, 6}, {5, 4}, {4, 3}};
  // edge listOfEdges[6] = {{0, 5}, {1, 6}, {2, 7}, {3, 8}, {4, 9}, {1, 5}};

  // Build Graph
  for (int i = 0; i < 10; ++i)
  {
    u = listOfEdges[i].u;
    v = listOfEdges[i].v;
    graph[u].push_back(v); // For a birectional edge, we should insert both (u,v) and (v,u) as an edge
    graph[v].push_back(u);
  }

  checkConnected(0, 1, graph);
  checkConnected(0, 3, graph);
  checkConnected(1, 4, graph);
  checkConnected(6, 8, graph);
  checkConnected(2, 5, graph);
  checkConnected(8, 9, graph);
  checkConnected(5, 7, graph);
  checkConnected(0, 8, graph);

  return 0;
}
