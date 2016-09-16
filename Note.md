##Linked list

+ Linked list provides following two advantages over arrays

	1. Dynamic size
	2. Ease of insertion/deletion

+ Linked lists have following drawbacks:

	1. Random access is not allowed. We have to access elements sequentially starting from the first node. So we cannot do binary search with linked lists.
	2. Extra memory space for a pointer is required with each element of the list.
	3. Arrays have better cache locality that can make a pretty big difference in performance.

+ Definition in `C`

	```
	struct node 
	{
	  int data;
	  struct node *next;
	};
	```
	```
	
+ Conclusion

	1. Once it is needed to change the head, it is necesssary to pass reference of head as parameter in the function.
	2. In general, array is considered a data structure for which size is fixed at the compile time and array memory is allocated either from Data section (e.g. global array) or Stack section (e.g. local array). Similarly, linked list is considered a data structure for which size is not fixed and memory is allocated from Heap section (e.g. using malloc() etc.) as and when needed.
	3. Array means contiguous memory. It can exist in any memory section be it Data or Stack or Heap. Linked List means non-contiguous linked memory. It can exist in any memory section be it Heap or Data or Stack.