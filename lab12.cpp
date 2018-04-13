#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct node_struct
{
  int vertex;
  int dist;
} Node;

typedef struct edge_struct
{
  int u1;
  int u2;
  int cost;
} Edge;

struct NodeCompare
{
  bool operator()(Node *n1, Node *n2) const
  {
    return n1->dist > n2->dist;
  }
};

void printResult(int distance[], int length)
{
  printf("Vertex    Distance from Source\n");
  for (int i = 0; i < length; i++)
  {
    printf("%d         %d\n", i, distance[i]);
  }
}

// DIJKSTRA(G, s)
// 	DISTANCE[0...n-1] = INFINITY
// 	DISTANCE[s] = 0
// 	sourceNode.vertex = s
// 	sourceNode.dist = 0
// 	PQ.INSERT(sourceNode)  // PQ is a priority queue
// 	WHILE PQ is not empty
// 		u = PQ.EXTRACT_MIN_DIST()
// 		for each vertex v adjacent to u
// 			IF DISTANCE[v] > DISTANCE[u] + edgeCost(u,v)
// 				DISTANCE[v] = DISTANCE[u] + edgeCost(u,v)
// 				// create a new node to put into PQ
// 				node.vertex = v
// 				node.dist = DISTANCE[v]
//        have to make sure if the vertex already exist, just update its dist value.
// 				PQ.INSERT(node)

void dijkstra(vector<Node> graph[], int n, int source)
{
  // initial distance
  const int INF = 9999999;
  int distance[n];
  Node *nodeRef[n];

  for (int i = 0; i < n; ++i)
  {
    distance[i] = INF;
  }
  distance[source] = 0;

  // Initial Queue
  priority_queue<Node *, vector<Node *>, NodeCompare> PQ;
  Node *s = new Node;
  (*s).vertex = source;
  (*s).dist = 0;
  nodeRef[source] = s;
  PQ.push(s);

  while (!PQ.empty())
  {
    int u, v, distU, distV, costUV;
    Node *x = PQ.top();
    PQ.pop();
    u = x->vertex;
    distU = x->dist;
    // printf("Extract vertex(u): %d, dist: %d\n", u, distU);

    for (vector<Node>::iterator vi = graph[u].begin(); vi != graph[u].end(); ++vi)
    {
      v = vi->vertex;
      costUV = vi->dist;
      distV = distance[v];
      if (distV > distU + costUV)
      {
        // printf("update edge (%d , %d) with cost %d\n", u, v, distU + costUV);
        distance[v] = distU + costUV;
        // if the vertex already exist, just update its dist value.
        // if (nodeRef[v])
        // {
        //   printf("Updte priority: v = %d with cost %d\n", v, distance[v]);
        //   (*nodeRef[v]).dist = distance[v];
        // }
        // else
        // {
        Node *t = new Node;
        (*t).vertex = v;
        (*t).dist = distance[v];
        nodeRef[v] = t;
        printf("Insert PQ:      v = %d into queue with cost %d\n", v, distance[v]);
        PQ.push(t);
        // }
      }
    }
  }

  printResult(distance, n);
}

int main()
{
  vector<Node> graph[50];
  int n = 5;
  int u1, u2, dist, cost;

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
    t.dist = cost;
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

  dijkstra(graph, n, 0);

  return 0;
}
