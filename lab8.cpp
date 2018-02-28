#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>

using namespace std;

typedef struct node_struct
{
  char symbol;
  int freq;
  struct node_struct *left;
  struct node_struct *right;
} Node;

struct NodeCompare
{
  bool operator()(const Node &n1, const Node &n2) const
  {
    return n1.freq > n2.freq;
  }
};

int main()
{
  int n = 6;
  Node nodeList[6] = {
      {'a', 45, NULL, NULL},
      {'b', 13, NULL, NULL},
      {'c', 12, NULL, NULL},
      {'d', 16, NULL, NULL},
      {'e', 9, NULL, NULL},
      {'f', 5, NULL, NULL}};

  priority_queue<Node, vector<Node>, NodeCompare> PQ;

  for (int i = 0; i < n; ++i)
    PQ.push(nodeList[i]);

  for (int i = 0; i < n; ++i)
  {
    Node t;
    t = PQ.top(); // Getting the min item, the item still stays in the Queue
    PQ.pop();     // Popping out this item

    printf("%c %d\n", t.symbol, t.freq);
  }
  return 0;
}
