#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void printList(struct node* list){
	while(list != NULL){
		printf("%d ", list->data);
		list = list->next;
	}
	printf("\n");
}

void reversePrintList(struct node* list){
	if (list == NULL){
		return;
	}
	reversePrintList(list->next);
	printf("%d ", list->data);
}

//can also use stack to do reverse print, below is Pseudocode
void reversePrintListByStack(struct node* list){
	// while(list != null){
	// 	stack.push(list->data);
	// 	list = list->next;
	// }
	// while(stack.isEmpty() != true){
	// 	stack.pop();
	// }
}

void printListAddress(struct node* list){
	while(list != NULL){
		printf("%p ", list);
		list = list->next;
	}
	printf("\n\n");
}

//4 steps O(1)
void addNodeAtFront(struct node** head_ref, int new_data){ //if use node*, the address of list cannot be changed. the insertion will fail.
	printf("%s%d\n", "Entered addNodeAtFront, data: ", new_data);
	struct node* front = (struct node*)malloc(sizeof(struct node));
	front->data = new_data;
	front->next = *head_ref;
	*head_ref = front;
	// head_ref = &front; //cannot use this one
}

//5 steps O(n)
void addNodeAtEnd(struct node** head_ref, int new_data)
{
	printf("%s%d\n", "Entered addNodeAtEnd, data: ", new_data);
	/* 1. allocate node */
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	
	/* 2. put in the data  */
	new_node->data  = new_data;
	
	/* 3. This new node is going to be the last node, so make next 
	      of it as NULL*/
	new_node->next = NULL;
	
	/* 4. If the Linked List is empty, then make the new node as head */
	if (*head_ref == NULL){
		*head_ref = new_node;
		return;
	}  
	  
	struct node *last = *head_ref;
	/* 5. Else traverse till the last node */
	while (last->next != NULL)
		last = last->next;
	
	/* 6. Change the next of last node */
	last->next = new_node;
}

//pos starts from 0, if pos == 0, use addNodeAtFront func, O(n)
void addNodeAtnPosition(struct node** head_ref, int new_data, int pos){ //e.g: 123, data: 5, pos: 2, result:1253
	printf("Entered addNodeAtnPosition, pos:%d, data:%d\n", pos, new_data);
	if (pos < 0){
		printf("%s\n", "pos can not be negative");
		return;
	}

	if (pos == 0){
		addNodeAtFront(head_ref, new_data);
		return;
	}

	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = new_data;

	struct node *prev = *head_ref;
	int idx = 0;
	while(prev != NULL && ++idx != pos){
		prev = prev->next;
	}

	if (prev == NULL){
		printf("%s\n", "pos must be smaller or equal to length of list"); //len3 -> 3ok, 4bad
		return;
	}

	new_node->next = prev->next;
	prev->next = new_node;
}

// O(n)
void deleteNodeByKey(struct node** head_ref, int key){
	printf("%s%d\n", "Entered deleteNodeByKey, key:", key);

	struct node* tmp = *head_ref, *prev;

	if ( tmp != NULL && tmp->data == key) {//head is the key
		*head_ref = tmp->next; //change head
		free(tmp);
		return;
	}

	while( tmp != NULL && tmp->data != key){ //after the loop, either found the node to be deleted or reached the end of the list and not found.
		prev = tmp;
		tmp = tmp->next;
	}

	if (tmp == NULL){
		printf("%s\n", "key not found");
		return;
	}

	prev->next = tmp->next;
	free(tmp);
}

//pos starts from 0, O(n)
void deleteNodeByPos(struct node** head_ref, int pos){ //e.g: 123, pos: 1, result:13
	printf("%s%d\n", "Entered deleteNodeByPos, pos:", pos);

	struct node* tmp = *head_ref;
	struct node* prev = *head_ref;
	if(tmp != NULL && pos == 0){
		*head_ref = tmp->next;
		free(tmp);
		return;
	}

	int idx = 0;
	while (idx++ != pos && tmp != NULL){ //set the node that will be deleted as tmp, idx starts from 0
		prev = tmp;
		tmp = tmp->next;
	}

	if (tmp == NULL){
		printf("%s\n", "pos out of range");
		return;
	}

	prev->next = tmp->next;
	free(tmp);
}

int main()
{
	struct node* head = NULL;
	struct node* second = NULL;
	struct node* third = NULL;

	head = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third = (struct node*)malloc(sizeof(struct node));
 	
	head->data = 1;
	head->next = second;
	second->data = 2;
	second->next = third;
	third->data = 3;
	third->next = NULL;

	printList(head);
	printListAddress(head);

	addNodeAtFront(&head, 0);
	printList(head);
	printListAddress(head);

	addNodeAtEnd(&head, 4);
	printList(head);
	printListAddress(head);

	addNodeAtnPosition(&head, 10, 0); //front
	printList(head);
	printListAddress(head);

	addNodeAtnPosition(&head, 5, 2); //middle
	printList(head);
	printListAddress(head);

	addNodeAtnPosition(&head, 6, 7); //end
	printList(head);
	printListAddress(head);

	addNodeAtnPosition(&head, 6, 9); //out of range
	printList(head);
	printListAddress(head);

	deleteNodeByKey(&head, 10);
	printList(head);
	printListAddress(head);

	deleteNodeByPos(&head, 0); //front
	printList(head);
	printListAddress(head);

	deleteNodeByPos(&head, 2); //middle
	printList(head);
	printListAddress(head);

	deleteNodeByPos(&head, 4); //end
	printList(head);
	printListAddress(head);

	deleteNodeByPos(&head, 4); //out of range
	printList(head);
	printListAddress(head);

	reversePrintList(head);
	return 0;
}

//output
/*
1 2 3
0x7f9998c032d0 0x7f9998c032e0 0x7f9998c032f0

Entered addNodeAtFront, data: 0
0 1 2 3
0x7f9998c03300 0x7f9998c032d0 0x7f9998c032e0 0x7f9998c032f0

Entered addNodeAtEnd, data: 4
0 1 2 3 4
0x7f9998c03300 0x7f9998c032d0 0x7f9998c032e0 0x7f9998c032f0 0x7f9998c03310

Entered addNodeAtnPosition, pos:0, data:10
Entered addNodeAtFront, data: 10
10 0 1 2 3 4
0x7f9998c03320 0x7f9998c03300 0x7f9998c032d0 0x7f9998c032e0 0x7f9998c032f0 0x7f9998c03310

Entered addNodeAtnPosition, pos:2, data:5
10 0 5 1 2 3 4
0x7f9998c03320 0x7f9998c03300 0x7f9998c03330 0x7f9998c032d0 0x7f9998c032e0 0x7f9998c032f0 0x7f9998c03310

Entered addNodeAtnPosition, pos:7, data:6
10 0 5 1 2 3 4 6
0x7f9998c03320 0x7f9998c03300 0x7f9998c03330 0x7f9998c032d0 0x7f9998c032e0 0x7f9998c032f0 0x7f9998c03310 0x7f9998c03340

Entered addNodeAtnPosition, pos:9, data:6
pos must be smaller or equal to length of list
10 0 5 1 2 3 4 6
0x7f9998c03320 0x7f9998c03300 0x7f9998c03330 0x7f9998c032d0 0x7f9998c032e0 0x7f90 5 1 2 3 4 6
0x7f9998c03300 0x7f9998c03330 0x7f9998c032d0 0x7f9998c032e0 0x7f9998c032f0 0x7f9998c03310 0x7f9998c03340

Entered deleteNodeByPos, pos:0
5 1 2 3 4 6
0x7f9998c03330 0x7f9998c032d0 0x7f9998c032e0 0x7f9998c032f0 0x7f9998c03310 0x7f9998c03340

Entered deleteNodeByPos, pos:2
5 1 3 4 6
0x7f9998c03330 0x7f9998c032d0 0x7f9998c032f0 0x7f9998c03310 0x7f9998c03340

Entered deleteNodeByPos, pos:4
5 1 3 4
0x7f9998c03330 0x7f9998c032d0 0x7f9998c032f0 0x7f9998c03310

Entered deleteNodeByPos, pos:4
pos out of range
5 1 3 4
0x7f9998c03330 0x7f9998c032d0 0x7f9998c032f0 0x7f9998c03310

4 3 1 5
*/