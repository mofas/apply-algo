#include <stdio.h>
#include <string.h>

typedef struct edge_struct
{
  int u1;
  int u2;
  int cost;
} Edge;

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
