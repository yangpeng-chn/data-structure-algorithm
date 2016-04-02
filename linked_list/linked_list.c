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

void printListAddress(struct node* list){
	while(list != NULL){
		printf("%p ", list);
		list = list->next;
	}
	printf("\n");
}

void addNodeAtFront(struct node** list, int new){ //if use node*, the address of list cannot be changed. the insertion will fail.
	struct node* front = NULL;
	front = (struct node*)malloc(sizeof(struct node));
	front->data = new;
	front->next = *list;
	
	*list = front;

	// list = &front; //cannot use this one
}

void addNodeAtEnd(struct node* list, int new){ 
	struct node* new_node = NULL;
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = new;
	new_node->next = NULL;
	while(list->next != NULL){
		list = list->next;
	}

	list->next = new_node;
}

void addNodeAtnPosition(struct node* list, int new, int pos){
	if (pos < 1){
		printf("%s\n", "pos must be greater than 0");
		return;
	}
	struct node* new_node = NULL;
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = new;
	int idx = 0;
	while(list != NULL){
		if(++idx == pos){ //from 1
			new_node->next = list->next;
			list->next = new_node;
			return;
		}
		list = list->next;
	}
	printf("%s\n", "pos must be smaller or equal to length of list"); //len3 -> 3ok, 4bad
}

void deleteNode(struct node** list, int key){
	struct node* tmp = *list, *prev;
	//struct node *temp=*head_ref;
	//struct node *prev;

	if ( tmp != NULL && tmp->data == key) //head is the key
	{
		*list = tmp->next; //change head
		free(tmp);
		return;
	}

	while( tmp != NULL && tmp->data != key){ //after the loop, either found the node to be deleted or reached the end of the list and not found.
		prev = tmp;
		tmp = tmp->next;
	}

	if (tmp == NULL)
		return;

	prev->next = tmp->next;
	free(tmp);
}

void deleteNPosNode(struct node** list, int pos){
	struct node* tmp = *list, *prev;
	if(tmp != NULL && pos == 0){
		*list = tmp->next;
		free(tmp);
		return;
	}

	int idx = 0;
	while (++idx != pos && tmp != NULL){ //1 to n 123 ->(0,1,2)
		prev = tmp;
		tmp = tmp->next;
	}

	if (tmp == NULL){
		printf("%s\n", "pos out of range");
		return;
	}

	prev->next = tmp->next;
}

void reversePrintList(struct node* list){
	
}

int main()
{
	struct node* head = NULL;
	struct node* second = NULL;
	struct node* third = NULL;

	head = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third = (struct node*)malloc(sizeof(struct node));
 	
 	int a = 5;
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

	addNodeAtEnd(head, 4);
	printList(head);
	printListAddress(head);

	addNodeAtnPosition(head, 10, 2);
	printList(head);
	printListAddress(head);

	deleteNode(&head, 10);
	printList(head);
	printListAddress(head);

	deleteNPosNode(&head, 5);
	printList(head);
	printListAddress(head);
	return 0;
}