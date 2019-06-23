/* Linked list problems
createNode
printList (4 variations)
insert element in a sorted linked list
deleteNode (2 variations)
compare if two linked list are equal
merge two linked list, iterative and resursive
get middle element
reverse linked list (3 variations) (Iterative and recursion methods)
detect loop
remove the loop
rotate a linked list
delete list
insert node at beginning (two variations)
insert a node at Nth position, n counts from 1
delete a node at Nth position, n counts from 1
mergeK sorted lists
Kth Smallest Element in m Sorted lists
*/

/* notes
in c++, keyworkd "struct" can be omitted when define a node, but not in c
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
 
/* Link list Node */
struct Node
{
    int data; // 4 bytes
    struct Node* next; // 4 bytes
    // Node(int val){data = val};
};

struct Node* newNode(int value){
    struct Node *node = new Node;
    // or in C: struct Node* node = (Node*)malloc(sizeof(Node)); 
    node->data = value;
    node->next = NULL;
    return node;
}

Node* head;
void Print() //Insert using global variable. Node* head;
{
    struct Node* temp = head; // we don’t want to change the address of head, so need to use temp
    while(temp != NULL)
    {
        printf(" %d", temp->data); // scanf("%d", &n)
        temp = temp->next;
    }
    printf("\n");
}

void Print(struct Node* head) //print using parameter
{
    while(head != NULL)
    {
        printf(" %d", head->data);
        head = head->next;
    }
    printf("\n");
}
void PrintUsingRecursion(struct Node* p)
{
    if (p == NULL) return;
    printf("%d ", head->data);
    PrintUsingRecursion(p->next);
}
//1,2,3,4 => 4,3,2,1
void ReversePrintUsingRecursion(struct Node* p)
{
    if (p == NULL) return;
    ReversePrintUsingRecursion(p->next);
    printf("%d ", head->data);
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

bool deleteElement(Node **head, Node *deleteMe )
{
    Node *elem;

    if (!head || !*head || !deleteMe ) /* Check for null pointers */
        return false;

    elem = *head;
    if( deleteMe == *head ){ /* special case for head */
        *head = elem->next;
        free(deleteMe);
        return true;
    }

    while( elem ){
        if( elem->next == deleteMe ){
            /* elem is element preceding deleteMe */
            elem->next = deleteMe->next;
            free(deleteMe);
            return true;
        }
        elem = elem->next;
    }
    /* deleteMe not found */
    return false;
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
void merge(Node *p, Node **q){
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

Node* mergeWithRec(Node* p, Node* q){
    if(p == NULL) return q;
    if(q == NULL) return p;
    if(p->data < q->data){
        p->next = mergeWithRec(p->next, q);
        return p;
    }else{
        q->next = mergeWithRec(p, q->next);
        return q;
    }
}

//P5
//https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1
//https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/
int getMiddle(Node *head)
{
    if (head == NULL) return -1;
    Node *slowP = head;
    Node *fastP = head;
    while (fastP != NULL && fastP->next != NULL){
        slowP = slowP->next;
        fastP = fastP->next->next;
    }
    return slowP->data;
}

//P6
//https://www.geeksforgeeks.org/reverse-a-linked-list/
//https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1/?ref=self
Node* reverse(Node *head)
{
    Node *prev = NULL;
    Node *current=head;
    Node *next;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
  // Your code here
}

void reverse() // or void Reverse(struct Node** pointerToHead)
{
    struct Node *current, *prev, *next;
    current = head; // or current = *pointerToHead
    prev = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    //current, next are NULL now
    head = prev; // or *pointerToHead = prev
}
void reserveUsingRecursion(struct Node* p) // important
{
    if (p->next == NULL) //last element
    {
        head = p;
        return;
    }
    reserveUsingRecursion(p->next);
    struct Node* q = p->next;
    q->next = p; 
    // above two lines equal to: p->next->next = p
    p->next = NULL;
}


//P7
//https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1/?ref=self
//https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/
int detectloop(Node *list)
{
    Node *slow = list, *fast = list;
    while (slow != NULL && fast != NULL && fast->next !=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return 1;
        }
    }
    return 0;
   // your code here
}

//P8
//https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1/?ref=self
void removeTheLoop(Node *node)
{
    Node *slow = node, *fast = node, *prev;
    while (slow != NULL && fast != NULL && fast->next !=NULL){
        slow = slow->next;
        fast = fast->next->next;
        prev = slow;
        if(slow == fast){
            prev->next = NULL;
            return;
        }
    }
}

//P9
//https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1/?ref=self
//https://www.geeksforgeeks.org/rotate-a-linked-list/
void rotate(Node **head_ref, int k)
{
    if (k == 0 || *head_ref == NULL) return;
    int i = 1;
    Node *current = *head_ref;
    Node *kthNode;
    
    while(current != NULL && i < k){
        i++;
        current = current->next;
    }
    if (current == NULL) return;
    kthNode = current;
    while (current->next != NULL)
        current = current->next;
    
    current->next = *head_ref;
    *head_ref = kthNode->next;
    kthNode->next = NULL;
}

//P10
void deleteList( struct Node **head )
{
    Node *deleteMe = *head;

    while( deleteMe ){
        Node *next = deleteMe->next;
        free(deleteMe);
        deleteMe = next;
    }

    *head = NULL;
}

void Insert(int x) //Insert using global variable. Node* head;
{
    struct Node* temp = (Node*)malloc(sizeof(Node)); // or new Node(); in C++
    temp->data = x;
    temp->next = NULL;
    if(head != NULL) temp->next = head;
    head = temp;
}
void Insert(struct Node** pointerToHead, int x) // insert using parameter
{
    struct Node* temp = (Node*)malloc(sizeof(Node)); // or new Node(); in C++
    temp->data = x;
    temp->next = NULL;
    if(*pointerToHead != NULL) temp->next = *pointerToHead;
    *pointerToHead = temp;
}
//struct Node* head = NULL;
//Insert(&head, 2);

//1,2,3,4 Insert(5, 3) = > 1,2,5,3,4
void Insert(int data, int n) //or void Insert(struct Node** pointerToHead, int data, int n)
{
    struct Node* temp1 = (Node*)malloc(sizeof(struct Node)); // or new Node(); in C++
    temp1->data = data;
    temp1->next = NULL;
    if (n == 1){ // works even if head is empty
        temp1->next = head; // or temp1->next = *pointerToHead;
        head = temp1; // or *pointerToHead = temp1;
        return;
    }
    struct Node* temp2 = head; // or struct Node*temp2 = *pointerToHead;
    for (int i = 0; i < n - 2; i++){ // find the previous position of n, set temp2 to element 2
        temp2 = temp2->next; 
    }
    temp1->next = temp2->next; // temp2->next is element 4
    temp2->next = temp1; // set new node as next element of element 2
}

// 1,2,3,4 Delete(3) => 1,2,4
void Delete(int n) // or void Delete(struct Node** *pointerToHead, int n)
{
    struct Node* temp1 = head; // or struct Node* temp1 = *pointerToHead
    if (n == 1){
        head = temp1->next; // head now points to the second node, or *pointerToHead = temp1->next;
        free(temp1); // or delete temp1; in C++
        return;
    }
    int i = 0;
    for (int i = 0; i < n - 2; i++){ // temp1 points to n-1 th node, element 2
        temp1 = temp1->next; 
    }
    struct Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2); // or delete temp2; in C++
}

//https://leetcode.com/problems/merge-k-sorted-lists/description/
Node* mergeKLists(vector<Node*>& lists) {
    auto comp = [](Node* a, Node* b) { return a->data > b->data; };
    priority_queue<Node*, vector<Node*>, decltype(comp)> pq(comp);
    Node dummy;
    Node *cur = &dummy;
    for(Node *list : lists){
        if(list) pq.push(list);
    }
    while(!pq.empty()){
        cur->next = pq.top();
        pq.pop();
        cur = cur->next;
        if(cur->next) //cur won't be nulltpr as cur is the element poped from the queue which is always non-nullptr, so we only need to check if its next is nullptr
            pq.push(cur->next);
    }
    return dummy.next;
}

int kthSmallest(vector<Node*>& lists, int k){
    auto comp = [](Node* a, Node* b) { return a->data > b->data; };
    priority_queue<Node*, vector<Node*>, decltype(comp)> pq(comp);
    Node dummy;
    Node *cur = &dummy;
    for(Node *list : lists){
        if(list) pq.push(list);
    }
    int count = 0;
    while(!pq.empty() && count < k){
        cur->next = pq.top();
        count++;
        if(count == k)
            return cur->next->data;
        pq.pop();
        cur = cur->next;
        
        if(cur->next) //cur won't be nulltpr as cur is the element poped from the queue which is always non-nullptr, so we only need to check if its next is nullptr
            pq.push(cur->next);
    }
    return 0;
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

    
    // Node *list1, *list2, *list3;
    // list1 = newNode(1);
    // list1->next = newNode(3);
    // list2 = newNode(2);
    // list2->next = newNode(4);
    // list2->next->next = newNode(6);
    // list3 = newNode(0);
    // list3->next = newNode(9);
    // list3->next->next = newNode(10);
    // list3->next->next->next = newNode(11);
    // vector<Node*>lists{list1, list2, list3};
    // Node* list = mergeKLists(lists);
    // printList(list);

    cout << kthSmallest(lists, 5) << endl;
    return 0;
}