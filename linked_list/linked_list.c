#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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
    //  stack.push(list->data);
    //  list = list->next;
    // }
    // while(stack.isEmpty() != true){
    //  stack.pop();
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

    struct node* tmp = *head_ref, *prev; //prev is NULL

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

    // If linked list is empty
    if (*head_ref == NULL)
        return;

    // Store head node
    struct node* temp = *head_ref;

    // If head needs to be removed
    if (pos == 0){
        *head_ref = temp->next;   // Change head
        free(temp);               // free old head
        return;
    }

    // Find previous node of the node to be deleted
    for (int i=0; temp!=NULL && i<pos-1; i++)
         temp = temp->next;

    // If position is more than number of nodes, Node temp->next is the node to be deleted
    if (temp == NULL || temp->next == NULL){
        printf("%s\n", "Out of range");
        return;
    }

    // Store pointer to the next of node to be deleted
    struct node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

//O(n)
int getCount(struct node* list){
    int count = 0;
    while (list != NULL){
        count ++;
        list = list->next;
    }
    return count;
}

//O(n) slower than getCount
int getCountUsingRecursion(struct node* list){
    if (list == NULL)
        return 0;
    return 1 + getCountUsingRecursion(list->next);
}

//O(n) The idea it to first search x and y in given linked list. 
//If any of them is not present, then return. While searching for x and y, keep track of current and previous pointers. 
//First change next of previous pointers, then change next of current pointers
void swapNodes(struct node **head_ref, int x, int y){
    printf("%s%d,%d\n", "Entered swapNodes, values:", x, y);
    // Nothing to do if x and y are same
    if (x == y) return;
 
    // Search for x (keep track of prevX and CurrX
    struct node *prevX = NULL, *currX = *head_ref;
    while (currX && currX->data != x)
    {
        prevX = currX;
        currX = currX->next;
    }
 
    // Search for y (keep track of prevY and CurrY
    struct node *prevY = NULL, *currY = *head_ref;
    while (currY && currY->data != y)
    {
        prevY = currY;
        currY = currY->next;
    }
 
    // If either x or y is not present, nothing to do
    if (currX == NULL || currY == NULL)
        return;
 
    // If x is not head of linked list
    if (prevX != NULL)
        prevX->next = currY;
    else // Else make y as new head
        *head_ref = currY;  
 
    // If y is not head of linked list
    if (prevY != NULL)
        prevY->next = currX;
    else  // Else make x as new head
        *head_ref = currX;
 
    // Swap next pointers
    struct node *temp = currY->next;
    currY->next = currX->next;
    currX->next  = temp;
}

int getNth(struct node* head, int index){
    printf("%s%d\n", "Entered getNth, index:", index);
    struct node* current = head;
    for (int i = 0; i < index && current != NULL; ++i){
        current = current->next;
    }
    if (current != NULL){
        return current->data;
    }
    assert(0);
}

void printMiddle(struct node *head){
    printf("%s\n","Entered printMiddle");
    struct node *slow_ptr = head;
    struct node *fast_ptr = head;
    if (head!=NULL){
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf("The middle element is %d\n\n", slow_ptr->data);
    }
}

//Find n’th node from the end of a Linked List
/*
Method 1 (Use length of linked list)
1) Calculate the length of Linked List. Let the length be len.
2) Print the (len – n + 1)th node from the begining of the Linked List.
*/
void printNthFromLast1(struct node* head, int n){
    printf("%s%d\n","Entered printNthFromLast1, n: ", n);

    struct node* current = head;
    int len = 0;
    while(current != NULL){
        len++;
        current = current->next;
    }
    if (n > len || n < 1){
        printf("invalid input or %d is greater than the no. of nodes in list\n\n", n);
        return;
    }

    struct node* temp = head;
    for( int i = 1; i < len - n + 1; i++)
        temp = temp->next;

    printf("The %dth node from last is %d\n\n", n, temp->data);
}

/*
Method 2 (Use two pointers) 
Maintain two pointers – reference pointer and main pointer. 
Initialize both reference and main pointers to head. 
First move reference pointer to n nodes from head. 
Now move both pointers one by one until reference pointer reaches end. 
Now main pointer will point to nth node from the end. Return main pointer.
*/

void printNthFromLast2(struct node* head, int n){
    printf("%s%d\n","Entered printNthFromLast2, n: ", n);
    if ( n < 1 ){
        printf("n must be greater than 0\n\n");
        return;
    }
    struct node* ref_ptr = head;
    struct node* main_ptr = head;

    for(int i = 0; i < n; i++){
        if(ref_ptr != NULL)
            ref_ptr = ref_ptr->next;
        else{
            printf("%d is greater than the no. of nodes in list\n\n", n); //can handle empty list as well
            return;
        }
    }

    while(ref_ptr != NULL){
        main_ptr = main_ptr->next;
        ref_ptr = ref_ptr->next;
    }
    printf("The %dth node from last is %d\n\n", n, main_ptr->data);
}

void deleteList(struct node** head_ref){
    printf("%s\n","Entered deleteList");
    struct node* current = *head_ref;
    struct node* tmp = *head_ref;
    while(current != NULL){
        tmp = current;
        current = current->next;
        free(tmp);
    }
    *head_ref = NULL; //this line is needed
}

int main()
{
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;
    struct node* empty = NULL;

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

    swapNodes(&head, 1, 3);
    printList(head);

    printMiddle(head);

    printNthFromLast1(head, 0);
    printNthFromLast2(head, 4);
    printNthFromLast2(head, 5);
    printNthFromLast2(empty, 0);

    printf("The length of Linked list is: %d\n", getCount(head));
    printf("The length of Linked list is: %d\n", getCountUsingRecursion(head));
    printf("The 3th of Linked list is: %d\n", getNth(head, 3));
    reversePrintList(head);

    deleteList(&head);
    printList(head);
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