#include<iostream>
using namespace std;

/*
permutation
*/

/* Function to swap two characters */
void swap(char& a, char& b)
{
	char temp;
	temp = a;
	a = b;
	b = temp;
}

//https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
/* Function to obtain permutations of string characters */
void permutation(string s,int i,int n)
{
	int j;
	if (i == n)
		cout << s << "\t";
	else{
		for (j = i; j < s.length(); j++){
	        swap(s[i],s[j]);
	        permutation(s, i + 1, n);
	        swap(s[i],s[j]);
	    } 
	}
}

int main()
{
	string s;
	cout << "Enter the string : ";
	cin >> s;
	cout << endl << "The permutations of the given string : " << endl;
	permutation(s, 0, s.length() - 1);
	cout << endl;
}