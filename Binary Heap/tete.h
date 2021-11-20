#include <stdlib.h>
#include <stdio.h>
#ifndef LIB_H_ 
#define LIB_H_

typedef struct
{
    int capasity;
    int size;
    int *p;
}tas;


void init_tas(tas* t);
void detruire_tas(tas* t);
void inserer_tas(tas* t, int valeur);
int consulter_tas(const tas* t);
void supprimer_tas(tas* t);

#endif