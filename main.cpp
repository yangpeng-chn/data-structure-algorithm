#include<iostream>
using namespace std;

void print(int arr[], int n){
	cout << "&arr[0] in func: " << &arr[0] << endl;
	cout << "arr in func: " << arr << endl;
	cout << "&arr in func : " << &arr << endl;
	for (int i = 0; i < n; ++i)
	{
		/* code */
	}
	// int b = 3;
	// arr = &b;
	// cout << "arr: " << arr << endl;
	// cout << "&arr: " << &arr << endl;
}

void print2(int arr[4], int n){
	cout << "arr: " << arr << endl;
	cout << "&arr: " << &arr << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test( int arr[], int n){
	arr = arr+1;
}

void byref1(int (&a)[4]){
	cout << "&a[0] in byref1: " << &a[0] << endl;
	cout << "a in byref1: " << a << endl;
	cout << "&a in byref1: " << &a << endl;
}

void show_mem_rep(char *start, int n) 
{
    int i;
    for (i = 0; i < n; i++)
         printf(" %.2x", start[i]);
    printf("\n");
}

int main(){
	// int a[] = {1,-2,3,-4};
	// cout << maxSubArraySum(a, sizeof(a)/sizeof(a[0]));
	// cout << "&a[0] in main: " << &a[0] << endl;
	// cout << "a in main: " << a << endl;
	// cout << "&a in main: " << &a << endl;
	// print(a, 4);
	// cout << "a[0]: " << a[0] << endl;
	// cout << "a: " << a << endl;
	// cout << "&a: " << &a << endl;

	// int b = 1;
	// int &c = b;
	// cout << "&b: " << &b << endl;
	// cout << "&c: " << &c << endl;

	// int d = 4;
	// int arr[d];
	// arr[0] = 4;
	// arr[1] = 3;
	// arr[2] = 2;
	// arr[3] = 1;
	// test(a, 4);

	// int x[4] = {1,2,3,4};
 //  	byref1(a);

	// const int MAX = 4;
	// const char *names[MAX] = { "Zara Ali", "Hina Ali", "Nuha Ali", "Sara Ali" };

 //   for (int i = 0; i < MAX; i++) {
 //      cout << "Value of names[" << i << "] = ";
 //      cout << *(names + i) << endl;
 //   }

	// int a = -2147483647;
	// cout << -2147483647 - 1U << endl;
	// cout << (-2147483647 - 1U < 2147483647) << endl;

	// unsigned a = 1;
	// cout << 0-a << endl;

	// int i = 0x01234567;
 //    show_mem_rep((char *)&i, sizeof(i));
 //    getchar();

    int a = 2147483648;
    unsigned int b = a;
    cout << a << endl; //-2147483648
    cout << b << endl; //2147483648

    int x = -2147483648;
    cout << x - 1 << endl; //2147483647

	return 0;
}