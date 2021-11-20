#ifndef LIB_H_ 
#define LIB_H_
#include <stdio.h>
#include <stdlib.h>
struct file;
typedef struct file file;
void insert(file** head, int d, int p);
void remove_item(file** head, int it);
void changePriority(file** head,int it, int p);
void deleteHighestPriority(file** head);
file* new(int d, int p);
int isEmpty(file** head);
int getHighestPriority(file** head);
#endif