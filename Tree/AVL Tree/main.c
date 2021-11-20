#include "head.h"

int main()
{
    n *node;
    node = (n*)malloc(sizeof(n));
    
    
    *insertNode(node,49, "Almanya");
    *insertNode(node,32, "Belçika");
    *insertNode(node,33, "Fransa");
    *insertNode(node,90, "Türkiye");
    *insertNode(node,54, "Arjantin");
    *insertNode(node,20, "Mısır");
    *insertNode(node,31, "Hollanda");
    *insertNode(node,41, "İsviçre");
    *insertNode(node,61, "Avustralya");
    *insertNode(node,377, "Monaco");
    *insertNode(node,44, "İngiltere");
    *insertNode(node,30, "Yunanistan");
    *insertNode(node,43, "Avusturya");
    *insertNode(node,55, "Brezilya");
    *insertNode(node,34, "İspanya");
    *insertNode(node,52, "Meksika");
    *insertNode(node,351, "Portekiz");
    *insertNode(node,46, "İsveç");
    *deleteNode(node, 52);
    *deleteNode(node, 351);    
    *deleteNode(node, 46);
    
}

