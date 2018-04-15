#include<iostream>
using namespace std;

/*
Selection Sort, 
Bubble Sort, 
Insertion Sort, 
Merge Sort, 
Heap Sort, 
QuickSort, 
Radix Sort, 
Counting Sort, 
Bucket Sort, 
ShellSort, 
Comb Sort, 
Pigeonhole Sort, 
Cycle Sort
*/

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void selectionSort(int arr[], int n){
    
}


void bubbleSort(int arr[], int n){
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n-1; ++j)
        {
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}

int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int i = low;
	for (int j = low; j < high; j++)
	{
		if (arr[j] <= pivot)
		{
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[high]);
	return i;
}
void quickSort(int arr[], int low, int high){
	if(low < high){
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi-1);
		quickSort(arr, pi+1, high);
	}
}

//https://www.programiz.com/dsa/heap-sort
void heapify(int arr[], int n, int i){
    int largest = i;
    int l = i*2 + 1;
    int r = i*2 + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(&arr[largest], &arr[i]);
        heapify(arr, n, largest);
    }
}

// heap sort
void heapSort(int arr[], int n){
    for (int i = n/2-1; i >= 0 ; i--)
        heapify(arr, n, i);

    for (int i = n-1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

/* Driver program to test above functions */
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
 
    printf("\nArray is \n");
    printArray(arr, size);
    // quickSort(arr, 0, size-1);
    // mergeSort(arr, 0, size - 1);
    // bubbleSort(arr, size);
    heapSort(arr, size);
    printf("\nSorted array is \n");
    printArray(arr, size);
    return 0;
}