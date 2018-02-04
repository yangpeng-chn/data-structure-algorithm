/* Program to insert in a sorted list */
#include<iostream>
using namespace std;
 
/* Link list node */
struct Node
{
    int data;
    struct Node* next;
};

struct Node* newNode(int value){
	struct Node *node = new Node;
	node->data = value;
	node->next = NULL;
	return node;
}

void printList(struct Node *node){
	while(node != NULL){
		cout << node->data << " ";
		node = node->next;
	}
	cout << endl;
}

//P1
//https://www.geeksforgeeks.org/given-a-linked-list-which-is-sorted-how-will-you-insert-in-sorted-way/
void sortedInsert(struct Node** head, struct Node *node){
	if (*head == NULL){
		*head = node;
	}
	else if( (*head)->data > node->data){
		node->next = *head; // here is head, not (*head)->next
		*head = node;
	}
	else{
		struct Node *current = *head;
		while(current->next != NULL &&
			node->data > current->next->data ){
			current = current->next;
		}
		node->next = current->next;
		current->next = node;
	}
}

//P2
//https://www.geeksforgeeks.org/delete-a-given-node-in-linked-list-under-given-constraints/
//Note: to delete a node, need to track the previous node of the node to be deleted
void deleteNode(struct Node *head, struct Node *n){
	if (head == n)
	{
		if (head -> next == NULL)
		{
			cout << "cannot delete node, as there is only one node" << endl;
			return;
		}
		head->data = head->next->data;
		n = n->next;
		head->next = head->next->next;
		delete n;
		return;
	}else{
		Node *prev = head;
		while(prev->next != NULL && prev->next != n){
			prev = prev->next;
		}
		if (prev->next != NULL) // means prev->next == n, otherwise no node found, do nothing
		{
			prev->next = prev->next->next;
			delete n; // we have n pointer to refer the node, so no temp node is needed
		}
	}
}

//P3
//https://www.geeksforgeeks.org/compare-two-strings-represented-as-linked-lists/
int compare(Node *list1, Node *list2) {
	if (list1 == NULL && list2 == NULL)
		return 0;

	while(list1 != NULL && list2 != NULL){
		if(list1->data > list2->data)
			return 1;
		else if(list1->data < list2->data)
			return -1;
		else{
			list1 = list1->next;
			list2 = list2->next;
		}
	}
	if (list1 == NULL && list2 == NULL)
		return 0;
	return list1==NULL?-1:1;
}

//P4
//https://www.geeksforgeeks.org/merge-a-linked-list-into-another-linked-list-at-alternate-positions/
void merge(struct Node *p, struct Node **q){
	Node *currentP = p, *currentQ = *q;
	Node *nextP, *nextQ;
	while(currentP != NULL && currentQ != NULL){
		nextP = currentP->next;
		nextQ = currentQ->next;
		currentP->next = currentQ;
		currentP->next->next = nextP;
		currentP = nextP;
		currentQ = nextQ;
	}
	*q=currentQ;
}

int main(){
	//P1
	// struct Node* head = NULL;
	// struct Node *new_node = newNode(5);
	// sortedInsert(&head, new_node);
	// new_node = newNode(10);
	// sortedInsert(&head, new_node);
	// new_node = newNode(7);
	// sortedInsert(&head, new_node);
	// new_node = newNode(3);
	// sortedInsert(&head, new_node);
	// new_node = newNode(1);
	// sortedInsert(&head, new_node);
	// new_node = newNode(9);
	// sortedInsert(&head, new_node);
	// printf("\n Created Linked List\n");
	// printList(head);

	//P2
	// printf("\nDeleting node %d: ", head->next->next->data);
	//deleteNode(head, head->next->next);
	//printf("\nModified Linked List: ");
	//printList(head);
	//printf("\nDeleting node %d: ", head->data);
	//deleteNode(head, head);
	//printf("\nModified Linked List: ");
	//printList(head);

    //P3
	// Node *list1 = newNode(3);
	// list1->next = newNode(4);
	// list1->next->next = newNode(4);
	// list1->next->next->next = newNode(5);
	// list1->next->next->next->next = newNode(6);
	// list1->next->next->next->next->next = newNode(2);
	// Node *list2 = newNode(3);
	// list2->next = newNode(4);
	// list2->next->next = newNode(4);
	// list2->next->next->next = newNode(5);
	// list2->next->next->next->next = newNode(5);
	// list2->next->next->next->next->next = newNode(2);
	// cout << compare(list1, list2) << endl;

	//P5
	// Node *list1 = newNode(1);
	// list1->next = newNode(2);
	// list1->next->next = newNode(3);
	// Node *list2 = newNode(4);
	// list2->next = newNode(5);
	// list2->next->next = newNode(6);
	// list2->next->next->next = newNode(7);
	// list2->next->next->next->next = newNode(8);
	// merge(list1, &list2);
	// printList(list1);
	// printList(list2);
	
	return 0;
}