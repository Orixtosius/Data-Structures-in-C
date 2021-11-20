#include "tp03_p3.h"

void enqueue(int data)
{
    if(s.rear>=size-1)
    {
        printf("Cette operation est termine a cause de depassement de la capasite!\n");
    }
    else
    {
        if(s.front<0)
        {
            s.front++;
        }
        s.rear++;
        s.value[s.rear] = data;
    }
}
int dequeue()
{
    if(s.front==-1)
    {
        printf("Cette operation est termine car la pile est vite!\n");
        exit(1); 
    }

    int res = s.value[s.front];
    for(int i=0;i<s.rear+1;i++)
    {
        s.value[i] = s.value[i+1];
    }
    s.rear--;
    if(s.rear==0)
    {
        s.front--;
    }
    return res;
}

void show()
{
    if(s.front==-1)
    {
        printf("Il n'y a pas d'element dans la file!\n");     
    }
    for(int i=0;i<s.rear+1;i++)
    {
        printf("Element %d. est : %d\n", i+1, s.value[i]);
    }
}