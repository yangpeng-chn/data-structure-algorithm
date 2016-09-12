##Linked list

+ Linked list provides following two advantages over arrays

	1.	Dynamic size
	2.	Ease of insertion/deletion

+ Linked lists have following drawbacks:

	1.	Random access is not allowed. We have to access elements sequentially starting from the first node. So we cannot do binary search with linked lists.
	2.	Extra memory space for a pointer is required with each element of the list.
	3. Arrays have better cache locality that can make a pretty big difference in performance.

+ Definition in `C`

	```
	struct node 
	{
	  int data;
	  struct node *next;
	};
	```

+ Add a node at the front: (4 steps process)

	```
	/* Given a reference (pointer to pointer) to the head of a list
	   and an int,  inserts a new node on the front of the list. */
	void push(struct node** head_ref, int new_data)
	{
	    /* 1. allocate node */
	    struct node* new_node = (struct node*) malloc(sizeof(struct node));
	  
	    /* 2. put in the data  */
	    new_node->data  = new_data;
	  
	    /* 3. Make next of new node as head */
	    new_node->next = (*head_ref);
	  
	    /* 4. move the head to point to the new node */
	    (*head_ref)    = new_node;
	}
	```

+ Add a node after a given node: (5 steps process)
	
	```
	/* Given a node prev_node, insert a new node after the given
	   prev_node */
	void insertAfter(struct node* prev_node, int new_data)
	{
	    /*1. check if the given prev_node is NULL */
	    if (prev_node == NULL) 
	    { 
	       printf("the given previous node cannot be NULL");       
	       return;  
	    }  
	          
	    /* 2. allocate new node */
	    struct node* new_node =(struct node*) malloc(sizeof(struct node));
	  
	    /* 3. put in the data  */
	    new_node->data  = new_data;
	  
	    /* 4. Make next of new node as next of prev_node */
	    new_node->next = prev_node->next; 
	  
	    /* 5. move the next of prev_node as new_node */
	    prev_node->next = new_node;
	}
	```

+ Add a node at the end: (6 steps process)

	```
	/* Given a reference (pointer to pointer) to the head
	   of a list and an int, appends a new node at the end  */
	void append(struct node** head_ref, int new_data)
	{
	    /* 1. allocate node */
	    struct node* new_node = (struct node*) malloc(sizeof(struct node));
	 
	    struct node *last = *head_ref;  /* used in step 5*/
	  
	    /* 2. put in the data  */
	    new_node->data  = new_data;
	 
	    /* 3. This new node is going to be the last node, so make next 
	          of it as NULL*/
	    new_node->next = NULL;
	 
	    /* 4. If the Linked List is empty, then make the new node as head */
	    if (*head_ref == NULL)
	    {
	       *head_ref = new_node;
	       return;
	    }  
	      
	    /* 5. Else traverse till the last node */
	    while (last->next != NULL)
	        last = last->next;
	  
	    /* 6. Change the next of last node */
	    last->next = new_node;
	    return;    
	}
	```
	
+ Conclusion

	1. Once it is needed to change the head, it is necesssary to pass reference of head as parameter in the function.