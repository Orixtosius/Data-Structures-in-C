#include "tete.h"

//Question 1

void init_tas(tas* t)
{
    t = (tas*)malloc(sizeof(tas));
    t->p = malloc(64*sizeof(int));
    t->capasity = 64;
    t->size = 0;
}

//Question 2

void detruire_tas(tas* t)
{
    free(t->p);
    free(t);
}

//Question 3

void inserer_tas(tas* t, int valeur)
{
    if(t->capasity<=t->size)
    {
        printf("La capacité est pleine \n");
    }
    else
    {
        t->size ++;
        int i = t->size;
        t->p[i] = valeur;
        int temp;
        while(t->p[i]>t->p[i/2])
        {
            temp = t->p[i/2];
            t->p[i/2] = t->p[i];
            t->p[i] = temp;
            i/=2;
        }
    }
}
//Question 4
int consulter_tas(const tas* t)
{
    printf("Les elements sont :\n");
    for(int i=0;i<t->size;i++)
    {
        printf("%d\t",t->p[i]);
    }
}

//Question 5

void supprimer_tas(tas* t)
{
    if(t->size<= 0)
    {
        printf("Il n'y a pas d'element dans le tas \n");        
    }
    else
    {
        int x = t->p[t->size];
        printf("Element suprime est %d\n",x);
        t->size--;
    }
        
}