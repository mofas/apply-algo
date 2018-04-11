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

vector<Node> graph[50];

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
//                                 // have to make sure if the vertex already exist, just update its dist value.
// 				PQ.INSERT(node)

void dijkstra(int distance[], priority_queue<Node *, vector<Node *>, NodeCompare> PQ)
{
  Node *x = PQ.top();
  printf("Vertex: %d, dist: %d\n", x->vertex, x->dist);
}

int main()
{
  const int INF = 9999999;
  int n = 5;
  int u, v, d;
  int u1, u2, dist, cost;
  int distance[n];

  for (int i = 0; i < n; ++i)
  {
    distance[i] = INF;
  }

  distance[0] = 0;

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

  // for (int i = 0; i < n; ++i)
  // {
  //   u = i;
  //   cout << u << ": ";
  //   for (vector<Node>::iterator vi = graph[u].begin(); vi != graph[u].end(); ++vi)
  //   {
  //     v = vi->vertex;
  //     cost = vi->dist;
  //     cout << "[" << v << "," << cost << "] ";
  //   }
  //   cout << endl;
  // }

  // Initial Queue
  priority_queue<Node *, vector<Node *>, NodeCompare> PQ;
  Node node;
  node.vertex = 0; // Assuming 0 is the source node
  node.dist = 0;
  PQ.push(&node);

  dijkstra(distance, PQ);

  return 0;
}
