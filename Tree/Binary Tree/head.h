#ifndef LIB_H_ 
#define LIB_H_
#include <stdio.h>
#include <stdlib.h>

struct arbre
{
    int key;
    struct arbre* parent;
    struct arbre* left;
    struct arbre* right;
};
typedef struct arbre a;

struct queue
{
    a *niq;
    struct queue *next;
};
typedef struct queue q;

a *insertNode(a *node, int value);
a *deleteNode(a *node, int value);
a *findMax(a *node);
a *findMin(a *node);

void preord(a* node);
void inord(a* node);
void postord(a* node);
void leveord(a* node);

void enqueue(a* node);
a* dequeue();

a* searchNode(a *node, int value);

#endif