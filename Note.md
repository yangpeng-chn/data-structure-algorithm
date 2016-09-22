#Linked list
*****

#### Linked list provides following two advantages over arrays

1. Dynamic size
2. Ease of insertion/deletion

#### Linked lists have following drawbacks:

1. Random access is not allowed. We have to access elements sequentially starting from the first node. So we cannot do binary search with linked lists.
2. Extra memory space for a pointer is required with each element of the list.
3. Arrays have better cache locality that can make a pretty big difference in performance.

#### Definition in `C`

```
struct node 
{
  int data;
  struct node *next;
};
```

#### `void swapNodes(struct node **head_ref, int x, int y)`

```
  x   y
1 2 3 4 5
    ↓
1 4 3 2 5

Step 1 (Ignore the case that x or y is head)
prevX->next = currentY (1's next = 4)
1 4 ...
prevY->next = currentX (3's next = 2)
... 3 2 ...

Step 2
tmp = currentY->next
currentY->next = currentX->next (4's next = 3)
1 4 3 2 ...
currentX->next = tmp (2's next = 5)
1 4 3 2 5

```
	
#### Conclusion

1. Once it is needed to change the head, there are 3 ways to implement. [Ref][1]
	- Make head pointer global
	- Return head pointer
	- Use Double Pointer This approach follows the simple C rule: if you want to modify local variable of one function inside another function, pass pointer to that variable. So we can pass pointer to the head pointer to modify the head pointer in our deleteFirst() function. (**Recommended**)
2. In general, array is considered a data structure for which size is fixed at the compile time and array memory is allocated either from Data section (e.g. global array) or Stack section (e.g. local array). Similarly, linked list is considered a data structure for which size is not fixed and memory is allocated from Heap section (e.g. using malloc() etc.) as and when needed.
3. Array means contiguous memory. It can exist in any memory section be it Data or Stack or Heap. Linked List means non-contiguous linked memory. It can exist in any memory section be it Heap or Data or Stack.

[1]: http://www.geeksforgeeks.org/how-to-write-functions-that-modify-the-head-pointer-of-a-linked-list/