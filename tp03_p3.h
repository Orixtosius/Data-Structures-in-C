#ifndef LIB_H_ 
#define LIB_H_
#define size 3
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack
{
    int value[size];
    int front;
    int rear;
};
typedef struct stack ST;
ST s;

void enqueue(int data);
int dequeue();
void show();

#endif