# Basic Knowledges

## 1. C and C++

### 1.1 Pointer of Pointer
![Pointer1][1]
![Pointer2][2]

### 1.2 Pointer and arrays

```
int A[5];
```

1. **Element at index i, e.g**

	```
	Address: &A[i] or (A+i)
	Value: A[i] or *(A+i)
	```
2. **Size of Array**

	```
	int A[] = {1,2,3,4,5};
	int size = sizeof(A) / sizeof(A[0]); // 20/4 = 5
	```

### 1.3 Application's memory

- Heap (new, allocate)
- Stack (each function)
- Static/Global (Static and global variables)
- Code (Text)

### 1.4 Arrays as function arguments

```
int SumofEle(int A[]){ //same as int* A, call by ref, so can change the value of A in the calling func.
	int size = sizeof(A) / sizeof(A[0]); // 4/4 = 0, thus need to pass the size of array as argument
}

int main(){
	int A[] = {1,2,3,4,5};
	int size = sizeof(A) / sizeof(A[0]); // 20/4 = 5
	SumofEle(A);  // A can be used for &A[0]
	//this is only to create a pointer to interger which stores the address of the 1st element of A and it doesn't copy the whole array.
}
```

### 1.5 Character arrays and strings

- Size of array >= No. of characters in string + 1. e.g. "John" size >= 5
- String in C has be to `null` terminated
- Arrays and pointers are different types that are used in similar manner
- Arrays are always passed to function by reference

**String initialization**

[char * a = "" and char b[] = ""](http://ja.stackoverflow.com/questions/14553/char-a-%E3%81%A8-char-b-%E3%81%AB%E3%81%AF%E3%81%A9%E3%81%AE%E3%82%88%E3%81%86%E3%81%AA%E9%81%95%E3%81%84%E3%81%8C%E3%81%82%E3%82%8A%E3%81%BE%E3%81%99%E3%81%8B)

```
//case 1
char C[5];
C[0] = 'J';
C[1] = 'o';
C[2] = 'h';
C[3] = 'n';
C[4] = '\0'; //need to add this explicitly
int len = strlen(C); //4, size is 5

//case 2
char C[5] = {'J', 'o', 'h', 'n', '\0'}; //need to add \0 explicitly
int len = strlen(C); //4, size is 5

//case 3
char C[20] = "John"; // a null will be added after 'n' implicitly
int len = strlen(C); //4, size is 20

//case 4
char C[] = "John"; // a null will be added after 'n' implicitly
int len = strlen(C); //4, size is 5

//case 5
char *C = "John"; // a null will be added after 'n' implicitly
```

**Aarry and pointer**

```
char C1[5] = "John";
char * C2 = C1; //OK, C2 stores the address of 1st element in C1.
C1 = C2; //NG
C1 = C1 + 1; //NG
C2++; //OK
C2[i] is *(C2 + i)
C1[i] is *(C1 + i)
```

[1]: /Users/yangpeng/gitRepositories/data-structure-algorithm/C_C++/images/pointer1.png
[2]: /Users/yangpeng/gitRepositories/data-structure-algorithm/C_C++/images/pointer2.png