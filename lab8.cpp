#include <stdio.h>
#include <math.h>
#include <iostream>
#include <queue>
#include <string>

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
  bool operator()(Node *n1, Node *n2) const
  {
    return n1->freq > n2->freq;
  }
};

void printTree(Node *root, string code)
{
  if (!root)
    return;

  if (root->symbol != '_')
    printf("%c : %s\n", root->symbol, code.c_str());

  printTree(root->left, code + "0");
  printTree(root->right, code + "1");
}

Node *huffman(Node c[], int n)
{
  priority_queue<Node *, vector<Node *>, NodeCompare> PQ;

  for (int i = 0; i < n; ++i)
  {
    PQ.push(&c[i]);
  }

  for (int i = 0; i < n - 1; ++i)
  {
    Node *z = new Node;

    Node *x, *y;
    x = PQ.top();
    PQ.pop();
    y = PQ.top();
    PQ.pop();
    (*z).symbol = '_';
    z->freq = x->freq + y->freq;
    z->left = x;
    z->right = y;

    printf("Insert %c %c : %d \n", z->symbol, x->symbol, y->symbol, z->freq);
    PQ.push(z);
  }

  Node *ret = PQ.top();
  PQ.pop();

  return ret;
}

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

  Node *root = huffman(nodeList, 6);
  printTree(root, "");

  return 0;
}
