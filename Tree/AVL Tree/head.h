#ifndef LIB_H_ 
#define LIB_H_
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int key;
  char cntry[15];
  struct Node *left;
  struct Node *right;
  int height;
};
typedef struct Node n;
int height(n *N);
n *rightRotate(n *y);
n *leftRotate(n *x);
n *newNode(char cntry[15], int key) ;
int getBalance(n *N) ;
n *insertNode(n *node, int key, char cntry[15]) ;
n *deleteNode(n *root, int key) ;
int max(int a, int b);
#endif