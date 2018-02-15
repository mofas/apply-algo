#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node_struct
{
  int value;
  struct node_struct *left;
  struct node_struct *right;
} node;

node *treeSearch(node *p, int value) //return the node found or NULL if not found
{
  if (p == NULL)
    return NULL;
  if (value == p->value)
    return p;
  if (value < p->value)
    return treeSearch(p->left, value);
  else
    return treeSearch(p->right, value);
}

node *insert(node *root, int value)
{
  if (root == NULL)
  {
    node *temp = (node *)malloc(sizeof(node));
    temp->left = temp->right = NULL;
    temp->value = value;
    return temp;
  }

  if (value < root->value)
    root->left = insert(root->left, value);
  else
    root->right = insert(root->right, value);

  return root;
}

// pointer version
void insertByPointer(node **root, int value)
{
  if (*root == NULL)
  {
    *root = (node *)malloc(sizeof(node));
    (*root)->left = NULL;
    (*root)->right = NULL;
    (*root)->value = value;
    return;
  }

  if (value < (*root)->value)
    insertByPointer(&(*root)->left, value);
  else
    insertByPointer(&(*root)->right, value);
  return;
}

int randRange(int from, int to)
{
  int r = rand();
  r = r % (to - from + 1);
  r = r + from;
  return r;
}

void printTree(node *root)
{
  if (root != NULL)
  {
    printTree(root->left);
    printf("%d, ", root->value);
    printTree(root->right);
  }
}

int main()
{
  srand(time(NULL));
  node *root;
  root = NULL;
  int n = 10;

  // insert 20 value from 1 ~  100 into tree,
  // and print the result for each step.

  // we first insert by assign
  for (int i = 0; i < n; i++)
  {
    int value = randRange(1, 100);
    printf("insert the %d as the %d element.\n", value, i);
    root = insert(root, value);
    printTree(root);
    printf("\n");
  }

  printf("\nNow insert by reference.\n\n");
  // we now insert by reference.
  for (int i = 0; i < n; i++)
  {
    int value = randRange(1, 100);
    printf("insert the %d as the %d element.\n", value, (i + n));
    insertByPointer(&root, value);
    printTree(root);
    printf("\n");
  }

  printf("\n\n");

  // random search a number.
  int randTarget = randRange(1, 100);
  node *result = treeSearch(root, randTarget);
  printf("Try to search: %d \n", randTarget);
  if (result == NULL)
  {
    printf("Cannot find %d \n", randTarget);
  }
  else
  {
    printf("Find the result %d in the tree.", result->value);
  }
}
