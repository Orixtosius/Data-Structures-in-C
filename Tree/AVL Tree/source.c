#include "head.h"

int height(n *node) 
{
  if (node == NULL)
    return 0;
  return node->height;
}

n *rightRotate(n *y) 
{
  n *x = y->left;
  n *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

n *leftRotate(n *x) 
{
  n *y = x->right;
  n *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

n *newNode(char country[15], int key) 
{
    n *node = (struct Node *)
    malloc(sizeof(struct Node));
    node->key = key;
    int i;
    while(i != '\0')
    {
        node->cntry[i] = country[i];
    }
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

int getBalance(n *N) 
{
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}


n *insertNode(n *node, int key, char cntry[15]) 
{

  if (node == NULL)
    return newNode(cntry,key);

  if (key < node->key)
    node->left = insertNode(node->left, key, cntry);
  else if (key > node->key)
    node->right = insertNode(node->right, key, cntry);
  else
    return node;


  node->height = 1 + max(height(node->left),
               height(node->right));

  int balance = getBalance(node);
  if (balance > 1 && key < node->left->key)
    return rightRotate(node);

  if (balance < -1 && key > node->right->key)
    return leftRotate(node);

  if (balance > 1 && key > node->left->key) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  if (balance < -1 && key < node->right->key) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

n *minValueNode(n *node) {
  struct Node *current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}


n *deleteNode(n *root, int key) 
{

  if (root == NULL)
    return root;

  if (key < root->key)
    root->left = deleteNode(root->left, key);

  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    if ((root->left == NULL) || (root->right == NULL)) {
      struct Node *temp = root->left ? root->left : root->right;

      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      struct Node *temp = minValueNode(root->right);

      root->key = temp->key;

      root->right = deleteNode(root->right, temp->key);
    }
  }

  if (root == NULL)
    return root;


  root->height = 1 + max(height(root->left),
               height(root->right));

  int balance = getBalance(root);
  if (balance > 1 && getBalance(root->left) >= 0)
    return rightRotate(root);

  if (balance > 1 && getBalance(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  if (balance < -1 && getBalance(root->right) <= 0)
    return leftRotate(root);

  if (balance < -1 && getBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

int max(int a, int b) 
{
  return (a > b) ? a : b;
}