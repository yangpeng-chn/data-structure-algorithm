#include<iostream>
using namespace std;

/* 
Linear search
Binary search
Jump search
Interpolation Search
Exponential Search
Ternary Search
*/
int linearSearch(int arr[], int n, int v){
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == v)
			return i;
	}
	return -1;
}

// why use l + (r-l)/2 instead of (l+r)/2. 
// https://stackoverflow.com/questions/27167943/why-leftright-left-2-will-not-overflow
// https://www.geeksforgeeks.org/binary-search/
int binarySearchRec(int arr[], int l, int r, int v){
	if (l <= r)
	{
		int mid = l + (r - l)/2;
		if (arr[mid] == v) return mid;
		else if (arr[mid] > v) return binarySearchRec(arr, l, mid-1, v);
		else return binarySearchRec(arr, mid+1, r, v);
	}
	return -1;
}

// https://www.geeksforgeeks.org/binary-search/
int binarySearch(int arr[], int n, int v){
	int left = 0;
	int right = n-1;
	while(left <= right){
		int mid = left + (right - left)/2;
		if (arr[mid] == v) return mid;
		else if (arr[mid] > v) right = mid-1;
		else left = mid+1;
	}
	return -1;
}

int main()
{
    int arr[] = {5, 6, 7, 11, 12, 13};
    int size = sizeof(arr)/sizeof(arr[0]);
    // cout << linearSearch(arr, size, 6) << endl;
    // cout << binarySearch(arr, size, 6) << endl;
    cout << binarySearchRec(arr, 0, size-1, 6) << endl;
    return 0;
}