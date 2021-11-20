#include "tete.h"

int main()
{
    tas *t;
    init_tas(t);
    inserer_tas(t, 7);
    inserer_tas(t, 1);
    inserer_tas(t, 9);
    inserer_tas(t, 35);
    inserer_tas(t, 4);
    inserer_tas(t, 10); 
    inserer_tas(t, 13);
    inserer_tas(t, 2);
    inserer_tas(t, 20);
    inserer_tas(t, 40);
    while(t->size>0)
    {
        supprimer_tas(t);
    }
    return 0;
}
