//https://www.geeksforgeeks.org/must-do-coding-questions-for-companies-like-amazon-microsoft-adobe/
/*
maxSubArraySum (kadane's algorithm)
reverse an array without affecting special characters
countTriplets
zigZag
find pythagorean triplet (2 variations)
is Palindrome (2 variations, int and string)
find subarry with given sum (No nagative numbers, 2 variations, good and bad)
Merge two arrays
*/

#include "iostream"

using namespace std;

void printStr(char str[]){
    cout << str << endl;
}

void printInt(int arr[], int n){
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//1. Kadane’s Algorithm
//https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}


//P1
//https://www.geeksforgeeks.org/reverse-an-array-without-affecting-special-characters/
bool isAlphabet(char c){ //
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

void reverse(char str[]){
    int l = 0, r = strlen(str) - 1;
    while(l < r){
        if (!isAlphabet(str[l]))
            l++;
        else if (!isAlphabet(str[r]))
            r--;
        else
        {
            char tmp = str[r];
            str[r] = str[l];
            str[l] = tmp;
            r--;
            l++;
        }
    }
}

//P2
//https://www.geeksforgeeks.org/count-triplets-with-sum-smaller-that-a-given-value/
//Given an array of distinct integers and a sum value. Find count of triplets with sum smaller than given sum value. Expected Time Complexity is O(n^2).
int countTriplets(int arr[], int n, int num){
    sort(arr, arr+n);
    int result = 0;
    for (int i = 0; i < n-2; ++i)
    {
        int j = i+1, k = n-1;
        while(j < k){
            if(arr[i] + arr[j] + arr[k] >= num)
                k--;
            else{
                result += (k-j);
                for( int m = 1; m <= k-j; m++)
                    cout << arr[i] << " " << arr[j] << " " << arr[j+m] << endl;
                j++;
            }
        }
    }
    return result;
}

//P3
//https://www.geeksforgeeks.org/convert-array-into-zig-zag-fashion/
void zigZag(int arr[], int n){
    bool flag = true; //"<"
    for (int i = 0; i < n-1; ++i)
    {
        if (flag){ //"<"
            if(arr[i+1] < arr[i]){
                swap(&arr[i], &arr[i+1]);
            }
        }else{ //">"
            if(arr[i+1] > arr[i]){
                swap(&arr[i], &arr[i+1]);
            }
        }
        flag = !flag;
    }
}


//P4
//https://www.geeksforgeeks.org/find-pythagorean-triplet-in-an-unsorted-array/
bool isTriplet(int arr[], int n)
{
    // Square array elements
    for (int i=0; i<n; i++)
        arr[i] = arr[i]*arr[i];
 
    // Sort array elements
    sort(arr, arr + n);
 
    // Now fix one element one by one and find the other two
    // elements
    for (int i = n-1; i >= 2; i--)
    {
        // To find the other two elements, start two index
        // variables from two corners of the array and move
        // them toward each other
        int l = 0; // index of the first element in arr[0..i-1]
        int r = i-1; // index of the last element in arr[0..i-1]
        while (l < r)
        {
            // A triplet found
            if (arr[l] + arr[r] == arr[i])
                return true;
 
            // Else either move 'l' or 'r'
            (arr[l] + arr[r] < arr[i])?  l++: r--;
        }
    }
 
    // If we reach here, then no triplet found
    return false;
}

bool isTriplet1(int arr[], int n){
    sort(arr, arr+n);
    for (int i = 0; i < n-2; ++i)
    {
        int j = i+1, k=n-1;
        while(j<k){
            int a = arr[i]*arr[i], b = arr[j]*arr[j], c = arr[k]*arr[k];
            if ( (a + b) != c){
                k--;
            }else{
                return true;
            }
        }
    }
    return false;
}

//
bool isPalindromeNum(int n){//1001
    int reversedInt = 0;
    int originalInt = n;
    while(n != 0){
        int reminder = n % 10;
        reversedInt = reversedInt * 10 + reminder;
        n = n/10;
    }
    return reversedInt==originalInt? true: false;
}

bool isPalindromeStr(string s){
    int low = 0, high = s.size()-1;
    while(low < high){
        if(s[low] != s[high])
            return false;
        low++;
        high--;
    }
    return true;
}


//https://www.geeksforgeeks.org/find-subarray-with-given-sum/
//http://www.techiedelight.com/find-subarray-having-given-sum-given-array/
//http://blog.gainlo.co/index.php/2016/06/01/subarray-with-given-sum/
void subArraySumGood(int a[], int n, int sum){ // O(n)
    int currentSum = 0, start = 1;
    for (int i = 0; i < n; ++i)
    {
        currentSum += a[i];
        while(currentSum > sum && start < n+1){
            currentSum = currentSum - a[start - 1];
            start++;
        }
        if (currentSum == sum)
        {
            cout << start << " " << i+1 << endl;
            return;
        }
    }
    cout << -1 << endl;
    return;
}

void subArraySumBad(int a[], int n, int sum){ // O(n^2)
    int currentSum = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            currentSum += a[j];
            if (currentSum == sum)
            {
                cout << i+1 << " " << j+1 << endl;
                return;
            }
            if (currentSum > sum){
                currentSum = 0;
                break;
            }
        }
    }

    cout << -1 << endl;
    return;
}

//https://practice.geeksforgeeks.org/problems/missing-number-in-array
int missingNum(int a[], int n){
    int expectedSum = 0;
    for (int i = 1; i < n+2; i++){
        expectedSum += i;
    }
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += a[i];
    }
    return expectedSum - sum;
}

//merge two arrays
int *mergeArrays(int a[], int b[], int m, int n){
    if ( m == 0 && n == 0 ) return NULL;
    int *result = new int[m+n];
    if (result == NULL) {return NULL;}
    
    int i = 0, j = 0, k = 0;
    while(i < m && j < n){
        if (a[i] > b[j]){
            result[k] = a[i];
            i++;
        }else{
            result[k] = b[j];
            j++;
        }
        k++;
    }
    while(i < m){
        result[k] = a[i];
        i++;
        k++;
    }
    while(j < n){
        result[k] = b[j];
        j++;
        k++;
    } 
    return result;
}

void changeme(int arr[], int n){
    arr[0] = 10;
}



int main(){
    //P1
    // char str[] = "a!!!b.c.d,e'f,ghi";
    // printStr(str);
    // reverse(str);
    // printStr(str);

    //P2
    // int arr[] = {3,4,1,7,5};
    // cout << countTriplets(arr, sizeof(arr)/sizeof(arr[0]), 12) << endl;

    //P3
    // int  arr[] = {4, 3, 7, 8, 6, 2, 1};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // zigZag(arr, n);
    // printInt(arr, n);

    //P4
    //int arr[] = {3, 1, 4, 6, 5};
    //int arr_size = sizeof(arr)/sizeof(arr[0]);
    //isTriplet(arr, arr_size)? cout << "Yes\n": cout << "No\n";
    //isTriplet1(arr, arr_size)? cout << "Yes\n": cout << "No\n";

    // cout << isPalindromeStr("isia") << endl;
    // cout << isPalindromeNum(1001) << endl;

    // int a[] = {1,2,3};
    // changeme(a, 3);
    // cout <<a[0];
    return 0;
}


