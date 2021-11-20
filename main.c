#include "tp03_p3.h"

int main()
{
    s.rear=-1;
    s.front=-1;
    int programme = 1;
    int button;
    int element;
    while(programme)
    {
        printf("Choisissez ce que vous aimeriez faire ? \n1 pour Emfiler\n2 pour Defiler\n3 pour Afficher\n4 pour Quitter\n");
        scanf("%d", &button);        
        switch(button)
        {
            case 1:
                printf("Choisissez ce que vous aimeriez ajouter a le tableau\n");
                scanf("%d",&element);
                enqueue(element);
                break;
            case 2:
                element = dequeue();
                printf("Element defile est %d\n", element);
                break;
            case 3:
                show();
                break;
            case 4:
                exit(0);
        }
        printf("Voulez-vous quitter? \n0 pour Oui, 1 pour Non\n");
        scanf("%d",&programme);
    }


    return 0;
}
