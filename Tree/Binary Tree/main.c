
#include "head.h"

int main(void)
{
    a *root = NULL;
    a *searched = NULL;
    int programme = 1;
    int button;
    int element;
    while(programme)
    {
        printf("Choisissez ce que vous aimeriez faire ? \n1 pour Ajouter\n2 pour Fasser\n3 pour Inordre\n4 pour Pre-ordre\n5 pour Post-ordre\n6 pour LevelOrdre\n7 pour Max\n8 pour Min\n9 pour Checher L'existence\n0 pour Quitter\n");
        scanf("%d", &button);        
        switch(button)
        {
            case 1:
                printf("Choisissez ce que vous aimeriez ajouter a l'arbre\n");
                scanf("%d",&element);
                root = insertNode(root,element);
                break;
            case 2:
                printf("Choisissez ce que vous aimeriez supprimer a l'arbre\n");
                scanf("%d",&element);
                printf("Element fasse est %d\n", element);
                root = deleteNode(root,element);
                break;
            case 3:
                inord(root);
                break;
            case 4:
                preord(root);
                break;
            case 5:
                postord(root);
                break;
            case 6:
                leveord(root);
                break;
            case 7:
                findMax(root);
                break;
            case 8:
                findMin(root);
            case 9:
                searched = searchNode(root,element);
                break;
            case 0:
                exit(0);
        }
        printf("Voulez-vous quitter? \n0 pour Oui, 1 pour Non\n");
        scanf("%d",&programme);
    }

    return 0;


}
