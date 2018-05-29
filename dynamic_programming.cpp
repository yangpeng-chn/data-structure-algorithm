#include<iostream>
using namespace std;

const int MAX = 100;
int lookup[MAX];

void initLookup(){
	for (int i = 0; i < MAX; ++i)
	{
		lookup[i] = -1;
	}
}

//https://www.geeksforgeeks.org/dynamic-programming-set-1/
//Memoization (Top Down)
//This approach is top-down since the original problem, 
//say, fib(3), is at the top in the computation.
int fib(int n){
	if (lookup[n] == -1)
	{
		if (n <=1)
			lookup[n] = n;
		else{
			lookup[n] = fib(n-1) + fib(n-2);
		}
	}
	return lookup[n];
}


//Tabulation (Bottom Up)
//this computation is bottom-up since original problem, 
//say, fib(3), is at the bottom of the computation.
int fibTab(int n)
{
  int f[n+1];
  f[0] = 0;
  f[1] = 1;
  for (int i = 2; i <= n; i++)
      f[i] = f[i-1] + f[i-2];
  return f[n];
}

int main(){
	initLookup();
	for(int i = 1; i < 10; i++){
		cout << fibTab(i) << " ";
	}
	cout << endl;
	return 0;
}