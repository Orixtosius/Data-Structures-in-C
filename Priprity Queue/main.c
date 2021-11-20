#include "tete.h"

int main()
{
	// Create a Priority Queue
	// 7->4->5->6
	file* queue = new(4, 1);
	insert(&queue, 5, 2);
	insert(&queue, 6, 3);
	insert(&queue, 7, 0);
    remove_item(&queue,3);
    changePriority(&queue, 2, 1);

	while (!isEmpty(&queue)) {
		printf("%d ", getHighestPriority(&queue));
		deleteHighestPriority(&queue);
	}
	
 
	return 0;
}
