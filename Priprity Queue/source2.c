#include "tete.h"


struct file
{
  int data;
  int priority;
  struct file *next;
};

file* new(int d, int p)
{
	file* temp = (file*)malloc(sizeof(file));
	temp->data = d;
	temp->priority = p;
	temp->next = NULL;
	return temp;
}
void insert(file** head, int d,int p)
{
	file* start = (*head);

	// Create new Node
	file* temp = new(d, p);

	// Special Case: The head of list has lesser
	// priority than new node. So insert new
	// node before head node and change head node.
	if ((*head)->priority > p) {

		// Insert New Node before head
		temp->next = *head;
		(*head) = temp;
	}
	else {

		// Traverse the list and find a
		// position to insert new node
		while (start->next != NULL &&
			start->next->priority < p) {
			start = start->next;
		}

		// Either at the ends of the list
		// or at required position
		temp->next = start->next;
		start->next = temp;
	}
}

int isEmpty(file** head)
{
    return (*head) == NULL;
}

int getHighestPriority(file** head)
{
	return (*head)->data;
}

void deleteHighestPriority(file** head)
{
    file* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

void remove_item(file** head, int it)
{
    file* temp = (*head);
    for(int i=2;i<=it;i++)
    {
        temp = temp->next;
    }
    if(temp->next->next != NULL)
    {
        temp->next = temp->next->next;
    }
    else
    {
        temp->next = NULL;
    }
    
}
void changePriority(file** head,int it, int p)
{
    file* temp = (*head);
    for(int i=2;i<=it;i++)
    {
        temp = temp->next;
    }
    temp->priority = p;
    
    
}