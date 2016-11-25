# Basic Knowledges

## 1. C and C++

### 1.1 Pointer of Pointer
![Pointer1][1]
![Pointer2][2]
![Pointer3][3]
![Pointer4][4]


### 1.2 Pointer and arrays

```c++
int A[5];
```

**Element at index i, e.g**

```c++
Address: &A[i] or (A+i)
Value: A[i] or *(A+i)
```
**Size of Array**

```c++
int A[] = {1,2,3,4,5};
int size = sizeof(A) / sizeof(A[0]); // 20/4 = 5
```

### 1.3 Application's memory

- Heap (new, allocate)
- Stack (each function)
- Static/Global (Static and global variables)
- Code (Text)

### 1.4 Arrays as function arguments

```c++
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

```c++
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

```c++
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

```c++
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

```c++
malloc  //int *p = (int *)malloc(sizeof(int));
calloc
realloc
free  //free(p)
```

**C++**

```c++
new //int *p = new int;  int *p = new int[20];
delete //delete p; delete []p;
```

### 1.9 Function Pointers
```c++
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

```c++
const int *ptr;
or
int const *ptr;
```

**Constant pointer to variable**
we can change value of object pointed by pointer, but cannot change the pointer to point another variable.

```c++
int *const ptr;
```

**constant pointer to constant**

```c++
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

### 1.17 When do we use Initializer List in C++?++
<http://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/>

there are situations where initialization of data members inside constructor doesn’t work and Initializer List must be used. Following are such cases:

1. For initialization of non-static const data members
2. For initialization of reference members
3. For initialization of member objects which do not have default constructor
4. For initialization of base class members
5. When constructor’s parameter name is same as data member (this pointer is also ok)
6. For Performance reasons

### 1.18 Is it possible to call constructor and destructor explicitly?
<http://www.geeksforgeeks.org/possible-call-constructor-destructor-explicitly/>

>Yes. When the constructor is called explicitly the compiler creates a nameless temporary object and it is immediately destroyed

### 1.19 Private destructor
<http://www.geeksforgeeks.org/private-destructor/>

### 1.20 When does compiler create default and copy constructors in C++?
<http://www.geeksforgeeks.org/does-compiler-always-create-a-copy-constructor/>

>In C++, compiler creates a default constructor if we don’t define our own constructor (See this). Compiler created default constructor has empty body, i.e., it doesn’t assign default values to data members (In java, default constructors assign default values).

>Compiler also creates a copy constructor if we don’t write our own copy constructor. Unlike default constructor, body of compiler created copy constructor is not empty, it copies all data members of passed object to the object which is being created.

>Compiler doesn’t create a default constructor if we write any constructor even if it is copy constructor. Compiler creates a copy constructor if we don’t write our own. Compiler creates it even if we have written other constructors in class.

>**So we need to write copy constructor only when we have pointers or run time allocation of resource like file handle, a network connection, etc**

### 1.21 Why copy constructor argument should be const in C++?
<http://www.geeksforgeeks.org/copy-constructor-argument-const/>

1. One reason for passing const reference is, we should use const in C++ wherever possible so that objects are not accidentally modified
2. compiler created temporary objects cannot be bound to non-const references and the original program tries to do that. It doesn’t make sense to modify compiler created temporary objects as they can die any moment.

### 1.22 Multiple Inheritance in C++
<http://www.geeksforgeeks.org/multiple-inheritance-in-c/>

### 1.23 Virtual Destructor
<http://www.geeksforgeeks.org/g-fact-37/>

>Deleting a derived class object using a pointer to a base class that has a non-virtual destructor results in undefined behavior. To correct this situation, the base class should be defined with a virtual destructor

>As a guideline, any time you have a virtual function in a class, you should immediately add a virtual destructor (even if it does nothing)

### 1.24 Advanced C++ | Virtual Copy Constructor
<http://www.geeksforgeeks.org/advanced-c-virtual-copy-constructor/>

### 1.25 Operator Overloading in C++
<http://quiz.geeksforgeeks.org/operator-overloading-c/>

```c++
// The global operator function is made friend of this class so
// that it can access private members (in class)
friend Complex operator + (Complex const &, Complex const &);

// return type: Complex, operand: c1, c2
Complex operator + (Complex const &c1, Complex const &c2)
{
     return Complex(c1.real + c2.real, c1.imag + c2.imag);
}
Complex c3 = c1 + c2;
```

### 1.26 Use of explicit keyword in C++
<http://www.geeksforgeeks.org/g-fact-93/>
>In C++, if a class has a constructor which can be called with a single argument, then this constructor becomes conversion constructor because such a constructor allows conversion of the single argument to the class being constructed

### 1.27 Default Assignment Operator and References
<http://www.geeksforgeeks.org/default-assignment-operator-and-references/>

Compiler doesn’t creates default assignment operator in following cases

1. Class has a nonstatic data member of a const type or a reference type
2. Class has a nonstatic data member of a type which has an inaccessible copy assignment operator
3. Class is derived from a base class with an inaccessible copy assignment operator

### 1.28 Smart Pointers in C++
<http://www.geeksforgeeks.org/smart-pointers-cpp/>

### 1.29 Overloading stream insertion (<<) and extraction (>>) operators in C++
<http://quiz.geeksforgeeks.org/overloading-stream-insertion-operators-c/>

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