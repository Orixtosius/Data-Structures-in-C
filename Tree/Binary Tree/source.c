#include "head.h"

q *rear = NULL;
q *front = NULL;

a *insertNode(a *node, int value) 
{
    if (node == NULL)
    {
        a *new = (a*)malloc(sizeof(a));
        new->key = value;
        printf("%d\n",new->key);
        new->left = NULL;
        new->right = NULL;
        return new;
    }
    node->parent = node;
    if (value < node->key)
    {
        node->left = insertNode(node->left, value);

    }
    else
    {
        node->right = insertNode(node->right, value);
    }
    return node;
}

a *findMin(a *node)
{
    a *temp = (a*)malloc(sizeof(a));
    temp = node;
    while(temp->left != NULL)
    {
        temp = temp->left;        
    }
    printf("%d\n",temp->key);
    return temp;

}

a *findMax(a *node)
{
    a *temp = (a*)malloc(sizeof(a));
    temp = node;
    while(temp->right != NULL)
    {
        temp = temp->right;        
    }
    printf("%d\n",temp->key);
    return temp;
    
}

a *deleteNode(a *root, int value) {
  if (root == NULL) 
  return root;
  if (value < root->key)
    root->left = deleteNode(root->left, value);
  else if (value > root->key)
    root->right = deleteNode(root->right, value);

  else {

    if (root->left == NULL) {
      a *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      a *temp = root->left;
      free(root);
      return temp;
    }
    a *temp = findMin(root->right);
    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

void inord(a* node)
{
    if(node== NULL)
    {
       printf("Aucun element pour vous montrer"); 
    }
    else
    {
        if(node->left != NULL)
        {
            preord(node->left);   
        }
        printf("%d , ",node->key);
    
        if(node->right != NULL)
        {
            preord(node->right);   
        }    
    }
}

void preord(a* node)
{
    if(node== NULL)
    {
       printf("Aucun element pour vous montrer."); 
    }
    else
    {
        printf("%d , ",node->key);
        if(node->left != NULL)
        {
            preord(node->left);   
        }
        if(node->right != NULL)
        {
            preord(node->right);   
        }    
    }
}

void postord(a* node)
{
    if(node== NULL)
    {
       printf("Aucun element pour vous montrer."); 
    }
    else
    {
        if(node->left != NULL)
        {
            preord(node->left);   
        }
        
        if(node->right != NULL)
        {
            preord(node->right);   
        }
        printf("%d , ",node->key);
    }
}
void leveord(a* node)
{
    if (node == NULL)
    {
       printf("Aucun element pour vous montrer."); 
    }
    else
    {
        enqueue(node);
        while(rear !=NULL)
        {
            a* res = dequeue();
            printf("%d",res->key);
            if (res->left != NULL)
            {
                enqueue(res->left);
            }
            if (res->right != NULL)
            {
                enqueue(res->right);               
            }
        }
        
    }
}

void enqueue(a* node)
{
    q *temp;
    temp = (q*)malloc(sizeof(q));
    temp->niq = node;
    temp->next = NULL;
   
    if(front == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

a* dequeue()
{
    if(front == NULL)
    {
        printf("Cette operation est termine car la pile est vite!\n");
        exit(1); 
    }
    else
    {
        q *temp = front;
        front = front->next;
        a *res = front->niq;
        free(res);
        return res;
    }
}

a* searchNode(a *node, int value)
{
    if (node->key == value)
    {
        return node;
    }
    else if (node->key > value)
    {
        return searchNode(node->right, value);
    }
    if (node->key < value)
    {
        return searchNode(node->left, value);        
    }
}