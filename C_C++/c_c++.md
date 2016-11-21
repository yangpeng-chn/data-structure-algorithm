# Basic Knowledges

## 1. C and C++

### 1.1 Pointer of Pointer
![Pointer1][1]
![Pointer2][2]
![Pointer3][3]
![Pointer4][4]


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

### 1.6 Aarry and pointer

```
char C1[5] = "John";
char * C2 = C1; //OK, C2 stores the address of 1st element in C1.
C1 = C2; //NG
C1 = C1 + 1; //NG
C2++; //OK
C2[i] is *(C2 + i)
C1[i] is *(C1 + i)

char C[20] = "hello"; //string gets stored in the space for array
C[0] = 'A'; //OK
C++; //NG

char *C = "hello"; //string gets stored as compile time constant
C[0] = 'A'; //NG
C++; //OK
```

### 1.7 Pointers and 2-D arrays

```
int B[2][3];
B[0] and B[1] are 1-D arrays of 3 integers.

int A[5];
int *p = A;

//Output of below are the same
Print B; //a pointer to 1-D array of 3
Print *B; //a pointer to an integer, p
Print B[0]; //Address of first integer, A
Print &B[0][0] //Address of first integer, &A[0]

int *p = B; //NG, as B will return a pointer to 1-D array of 3 integers.
int (*p)[3] = B; //OK

for 2-D array,
B[i][j] = *(B[i]+j)
		 = *(*(B + i)+j)

```

### 1.8 Pointers and dynamic memory

**C**

```
malloc  //int *p = (int *)malloc(sizeof(int));
calloc
realloc
free  //free(p)
```

**C++**

```
new //int *p = new int;  int *p = new int[20];
delete //delete p; delete []p;
```

### 1.9 Function Pointers
```
int Add(int a, int b){
	return a+b
}

int (*p)(int,int); //cannot be *p
p = &Add;
printf("%d", (*p)(3, 2));
```

### 1.10 Const Qualifier in C
**Pointer to constant**
We can change pointer to point to any other integer variable, but cannot change value of object (entity) pointed using pointer ptr.

```
const int *ptr;
or
int const *ptr;
```

**Constant pointer to variable**
we can change value of object pointed by pointer, but cannot change the pointer to point another variable.

```
int *const ptr;
```

**constant pointer to constant**

```
const int *const ptr;
```

### 1.11 Storage Classes and Type Qualifiers

<http://quiz.geeksforgeeks.org/c-language-2/storage-classes/>

**Static storage** can be used as 	`Global variable`, `Function name` and `Local variable`, cannot be used as `Function parameter`.

>Declaring a global variable as static limits its scope to the same file in which it is defined. A static function is only accessible to the same file in which it is defined. A local variable declared as static preserves the value of the variable between the function calls

### 1.12 When do we pass arguments by reference or pointer?
<http://www.geeksforgeeks.org/when-do-we-pass-arguments-by-reference-or-pointer/>

In C++, variables are passed by reference due to following reasons:

- To modify local variables of the caller function
- For passing large sized arguments
- **To avoid Object Slicing**
- To achieve Run Time Polymorphism in a function

### 1.13 Function overloading and const keyword
<http://www.geeksforgeeks.org/function-overloading-and-const-functions/>

>C++ allows functions to be overloaded on the basis of const-ness of parameters only if the const parameter is a reference or a pointer.

### 1.14 Inline Functions in C++
<http://quiz.geeksforgeeks.org/inline-functions-cpp/>
>Remember, inlining is only a request to the compiler, not a command. Compiler can ignore the request for inlining. Compiler may not perform inlining in such circumstances like ...

- Inline functions provide following advantages:
- Inline function disadvantages:

### 1.15 Basic Concepts of Object Oriented Programming using C++
<http://quiz.geeksforgeeks.org/basic-concepts-of-object-oriented-programming-using-c/>

- Encapsulation and Data abstraction
- Inheritance
- Polymorphism
- Dynamic Binding
- Message Passing

>Overloading doesn’t work for derived class in C++ programming language. There is no overload resolution between Base and Derived

### 1.16 Copy Constructor in C++
<http://quiz.geeksforgeeks.org/copy-constructor-in-cpp/>

**When is copy constructor called?**
> In C++, a Copy Constructor may be called in following cases:
>
1. When an object of the class is returned by value.
2. When an object of the class is passed (to a function) by value as an argument.
3. When an object is constructed based on another object of the same class.
4. When compiler generates a temporary object.
It is however, not guaranteed that a copy constructor will be called in all these cases, because the C++ Standard allows the compiler to optimize the copy away in certain cases

## 2. Mathematics

### 2.1 Prime number

```
1 -> {1} -> no
2 -> {1,2} -> yes
```

[1]: /Users/yangpeng/gitRepositories/data-structure-algorithm/C_C++/images/pointer1.png
[2]: /Users/yangpeng/gitRepositories/data-structure-algorithm/C_C++/images/pointer2.png
[3]: /Users/yangpeng/gitRepositories/data-structure-algorithm/C_C++/images/pointer3.png
[4]: /Users/yangpeng/gitRepositories/data-structure-algorithm/C_C++/images/pointer4.png