#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<unordered_map>
#include<bitset> //for bitset as big flag
#include<typeinfo> // for typeid
#include<cctype> //for tolower and isalnum
#include<sstream>
#include<iomanip>

using namespace std;

/*
g++ main.cpp -std=c++11 -o main; ./main
*/
int compare(const vector<int>&a, const vector<int>&b){
        return a[1] < b[1];
    }
struct DateStruct
{
    int year;
    int month;
    int day;
};

class DateClass
{
public:
    int year;
    int month;
    int day;
    const int m_array[5];
public:
    DateClass(): m_array {1,2}{
        cout << "DateClass()" << endl;
    }
    DateClass(int year, int month, int day): m_array {1,2} // zero the member array
    {
        cout << "DateClass(int year, int month, int day)" << endl;
    }
};

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

int square1(int n) 
{ 
    //Address of n in square1() is not the same as n1 in main() 
    cout << "address of n1 in square1(): " << &n << "\n";   
      
    // clone modified inside the function 
    n *= n; 
    return n; 
} 
//Pass-by-Reference with Pointer Arguments 
void square2(int *n) 
{ 
    //Address of n in square2() is the same as n2 in main() 
    cout << "address of n2 in square2(): " << n << "\n"; 
      
    // Explicit de-referencing to get the value pointed-to 
    *n *= *n; 
} 
//Pass-by-Reference with Reference Arguments 
void square3(int &n) 
{ 
    //Address of n in square3() is the same as n3 in main() 
    cout << "address of n3 in square3(): " << &n << "\n"; 
      
    // Implicit de-referencing (without '*') 
    n *= n; 
} 

void my_int_func(int x)
{
    printf( "%d\n", x );
}

void func(int a[], int n){
    cout << "value of a in func: " << a << endl;
}

void func1(int *b, int n){
    cout << "value of b in func: " << b << endl;
}

int comp(const int * p, const int * q){
    return *p - *q;
}


int compareSec(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}

int compareFirst1(const pair<string, int>& a, const pair<string, int>& b) {
    return a.first < b.first;
}

int compareFirst(pair<string, int> *a, pair<string, int> *b) {
    return (*a).first < (*b).first;
}

void printSizeOfType(){
    std::cout << "bool:\t\t" << sizeof(bool) << " bytes" << std::endl;
    std::cout << "char:\t\t" << sizeof(char) << " bytes" << std::endl;
    std::cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes" << std::endl;
    std::cout << "char16_t:\t" << sizeof(char16_t) << " bytes" << std::endl; // C++11, may not be supported by your compiler
    std::cout << "char32_t:\t" << sizeof(char32_t) << " bytes" << std::endl; // C++11, may not be supported by your compiler
    std::cout << "short:\t\t" << sizeof(short) << " bytes" << std::endl;
    std::cout << "int:\t\t" << sizeof(int) << " bytes" << std::endl;
    std::cout << "long:\t\t" << sizeof(long) << " bytes" << std::endl;
    std::cout << "long long:\t" << sizeof(long long) << " bytes" << std::endl; // C++11, may not be supported by your compiler
    std::cout << "float:\t\t" << sizeof(float) << " bytes" << std::endl;
    std::cout << "double:\t\t" << sizeof(double) << " bytes" << std::endl;
    std::cout << "long double:\t" << sizeof(long double) << " bytes" << std::endl;
    std::cout << "size_t:\t\t" << sizeof(size_t) << " bytes" << std::endl;
}

void charPactice(){
    char a = 'a';
    char A = 'A';
    cout << static_cast<int>(a)<< endl;
    cout << A << endl;
    cout << a-A << endl;
    cout << 'a' - 'A' << endl;
    char upper = 'B';
    cout << upper << endl;
    cout << (char)(upper + 'a' - 'A') << endl; // upper to lower
}

void referencePractice(){
    int a = 1;
    int &b = a;
    cout << &a << endl;
    cout << &b << endl;
    cout << sizeof (b) << endl;
}

void arrayFunc1(int a[3])
{
    cout << a[2] << endl;
    cout << a[3];
}

void arrayFunc2(int *a){
    int b[2] {1,2};
    // a = b;
    a[1] = 0;
}

void cpp11and14(){
    int x { 4 };
    cout << x << endl;

    const unsigned char option1 = 0b0000'0010; // represents bit 1
    cout << option1 << endl;
}

char toLower(char c){
   if (c > 'A' && c < 'Z')
        return c+'a'-'A';
    return c;
}

void bits(){
    const int option0 = 0;
    const int option1 = 1;
    const int option2 = 2;
    const int option3 = 3;
    const int option4 = 4;
    const int option5 = 5;
    const int option6 = 6;
    const int option7 = 7;

    std::bitset<8> bits(0x2); // we need 8 bits, start with bit pattern 0000 0010
    bits.set(option4); // set bit 4 to 1 (now we have 0001 0010)
    bits.flip(option5); // flip bit 5 (now we have 0011 0010)
    bits.reset(option5); // set bit 5 back to 0 (now we have 0001 0010)
 
    std::cout << "Bit 4 has value: " << bits.test(option4) << '\n';
    std::cout << "Bit 5 has value: " << bits.test(option5) << '\n';
    std::cout << "All the bits: " << bits << '\n';
}

void arrayFunc(){
    char name[6] = "Study"; // '\0' added automatically
    char name1[10] = {'L','e','s','s','o','n','s','\0'}; // '\0' added explicitly
    cout << sizeof(name) << endl;
    cout << sizeof(name1) << endl;
    cout << name << endl;
    cout << name1 << endl;

    // int temp = 5;
    // const int length = temp; // the value of length isn't known until runtime, so this is a runtime constant, not a compile-time constant!
    // int array[temp]; // Not ok
    // cout << sizeof(array) << endl;

    int array[5];
    for (int i = 0; i < 5; ++i)
    {
        cout << array[i] << endl;
    }

    cout << typeid(array).name() << endl; //A5_i (array with 5 int elements)
    cout << typeid(&array).name() << endl; //P5_i (pointer of array with 5 int elements)
    cout << typeid(array[0]).name() << endl; //i (int)
    cout << typeid(&array[0]).name() << endl; //Pi (Pointer of int)

    std::array<int, 3> arr;
    arr = {1,2,3};
    cout << arr[1];
}

void vectorFunc(){
    vector<int>array;
    array = { 0, 1, 2, 3, 4 }; // okay, array length is now 5
    cout << array.size();
    array = { 9, 8, 7 }; // okay, array length is now 3
    cout << array.size();
}

void pointerFunc(){
    // int x(4);
    // cout << typeid(&x).name(); //(With gcc, this prints “pi” (pointer to int)).
    // int *p;
    // cout << *p;

    int *ptr1 = new int (5); // use direct initialization
    int *ptr2 = new int { 6 }; // use uniform initialization
    cout << *ptr1 << endl;
    cout << *ptr2 << endl;
    delete ptr1;
    delete ptr2;
}

void printString(const char *cstring)
{
    // Only print if cstring is non-null
    if (cstring)
        std::cout << cstring;
    else
        std::cerr << "function printString() received a null parameter";
}

void passByAddress(int *a){
    // cout << a << endl;
    // int b[] = {2,3,4};
    // a = b;
    cout << typeid(a).name() << endl;
}

void passByRef(int &a){
    cout << a << endl;
}

void unorderedMap(){
    unordered_map<int, int> um;
    // um[1]++;
    cout << um[1] << endl;
}

int partition(int a[], int start, int end){
    int pivot = a[end];
    int pidx = start;
    for(int i = start; i < end; i++){
        if(a[i] < pivot){
            swap(a[i], a[pidx++]);
        }
    }
    swap(a[pidx], a[end]);
    return pidx;
}
void quicksort(int a[], int start, int end){
    if(start < end){
        int pidx = partition(a, start, end);
        quicksort(a, start, pidx-1);
        quicksort(a, pidx+1, end);
    }
}

void merge(int a[], int l, int m, int h){
    int n1 = m-l+1;
    int n2 = h-m;
    int left[n1];
    int right[n2];
    for(int i = 0; i < n1; i++){
        left[i] = a[l+i];
    }
    for(int i = 0; i < n2; i++){
        right[i] = a[m+1+i];
    }
    int i = 0, j = 0, k = l; //note, k starts from l, not 0!
    while(i < n1 && j < n2){
        if(left[i] < right[j]){
            a[k++] = left[i++];
        }else{
            a[k++] = right[j++];
        }
    }
    while(i < n1){
        a[k++] = left[i++];
    }
    while(j < n2){
        a[k++] = right[j++];
    }
}

void mergesort(int a[], int l, int h){
    if(l < h){
        int m = l + (h-l)/2;
        mergesort(a, l, m);
        mergesort(a, m+1, h);
        merge(a, l, m, h);
    }
}

int fib(int n){
    int a = 1;
    int b = 1;
    for(int i = 2; i < n; i++){
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int longestSubstringKDistinct(string str, int k){
    int start = 0, res = 0;
    unordered_map<char, int> um;
    for (int i = 0; i < str.size(); ++i)
    {
        um[str[i]]++;
        while(um.size() > k){
            char left = str[start];
            if(--um[left] == 0)
                um.erase(left);
            start++;
        }
        res = max(res, i - start + 1); //no need to put in while block as if the size is k, the res will be updated
    }
    return res;
}

static int a; //Zero Initialized
int b; //Zero Initialized

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
    // byref1(a);

    // const int MAX = 4;
    // const char *names[MAX] = { "Zara Ali", "Hina Ali", "Nuha Ali", "Sara Ali" };

    // for (int i = 0; i < MAX; i++) {
       // cout << "Value of names[" << i << "] = ";
       // cout << *(names + i) << endl;
    // }

    // int a = -2147483647;
    // cout << -2147483647 - 1U << endl;
    // cout << (-2147483647 - 1U < 2147483647) << endl;

    // unsigned a = 1;
    // cout << 0-a << endl;

    // int i = 0x01234567;
    // show_mem_rep((char *)&i, sizeof(i));
    // getchar();

    // int a = 2147483648;
    // unsigned int b = a;
    // cout << a << endl; //-2147483648
    // cout << b << endl; //2147483648

    // int x = -2147483648;
    // cout << x - 1 << endl; //2147483647

    // int a[] = {2,3,4};
    // cout << "address of n1 in main(): " << &a[0] << "\n"; 
    // cout << "Square of n1: " << square1(a[0]) << "\n"; 
    // cout << "No change in n1: " << a[0] << "\n"; 
      
    //Call-by-Reference with Pointer Arguments 
    // cout << "address of n2 in main(): " << &a[0] << "\n"; 
    // //square2(&a[0]);
    // square2(a[0]);
    // cout << "Square of n2: " << a[0] << "\n"; 
    // cout << "Change reflected in n2: " << a[0] << "\n"; 
      
    // //Call-by-Reference with Reference Arguments 
    // int n3=8; 
    // cout << "address of n3 in main(): " << &a[0] << "\n"; 
    // square3(a[0]); 
    // cout << "Square of n3: " << a[0] << "\n"; 
    // cout << "Change reflected in n3: " << a[0] << "\n"; 

    // int nums[2][3]  =  { { 16, 18, 20 }, { 25, 26, 27 } };
    // cout << "value of nums: " << nums << endl;
    // cout << "value of *nums: " << *nums << endl;
    // cout << "value of nums[0]: " << nums[0] << endl;
    // cout << "value of nums + 1: " << nums + 1 << endl;
    // cout << "value of *nums + 1: " << *nums + 1 << endl;
    // cout << "value of nums[0] + 1: " << nums[0] + 1 << endl;
    // cout << "size of nums: " << sizeof(nums) << endl;
    // cout << "size of nums[0]: " << sizeof(nums[0]) << endl;

    // const char * ptr = "geek";
    // cout << sizeof("geek") << endl;
    // char *ptr1 = "geek";
    // ptr1[0] = 'a';

    // int a = 0;
    // void *p = &a;
    // int *p1 = (int*)p;
    // cout << *p << endl;
    // cout << *p1 << endl;


    // void (*foo)(int);
    // foo = &my_int_func;

    // foo(2);
    // (*foo)(2);

    // int a[] = {1,2,3};
    // cout << "value of a: " << a << endl;
    // func(a, 3);
    // func1(a, 3);

    // int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // sort(arr, arr+n, greater<int>());
    // for (int i = 0; i < n; ++i)
    // {
            // cout << arr[i] << " ";
    // }
    // cout << endl;

    // vector<int> data(arr, arr + n);
    // sort(data.begin(), data.end(), greater<int>());
    // for (int i = 0; i < n; ++i)
    // {
            // cout << data[i] << " ";
    // }

    // unordered_map<string, int> mp({{"practice", 3}, {"makes", 2}, {"perfect", 1}, {"just", 4}});
    // unordered_map<string, int> mp({{"d", 3}, {"a", 2}, {"c", 1}, {"b", 4}});
    // for(auto it = mp.begin(); it != mp.end();it++){
    //   cout << it->first << " " << it->second << endl;
    // }
    // vector<pair<string, int>> vec(mp.begin(), mp.end());
    // sort(vec.begin(), vec.end(), compareFirst);
    // for (int i = 0; i < vec.size(); ++i)
    // {
    //  cout << vec[i].first << " " << vec[i].second << endl;
    // }

    // for(auto it = mp.begin(); it != mp.end();it++){
    //  cout << it->first << " " << it->second << endl;
    // }

    // printSizeOfType();
    // charPactice();
    // cpp11and14();

    // int x = 1;
    // x = x++;
    // std::cout << x;

    // bits();
    // arrayFunc();
    // pointerFunc();
    // referencePractice();

    // int a[]{1,2,3,4};
    // arrayFunc1(a);
    // cout << a << endl;
    // cout << &a << endl;

    // int a[] {2,3};
    // cout << a << endl;
    // arrayFunc2(a);
    // cout << a << endl;
    // cout << a[0] << endl;
    // cout << a[1] << endl;
    // vectorFunc();
    // DateStruct today { 2020, 10, 14 };
    // cout << typeid(today).name() << endl;

    // DateClass yesterday(1,1,2);
    // DateClass *p = new DateClass();
    // DateClass *q = new DateClass;
    // DateClass today;

    // int a[]{1,2,3};
    // cout << typeid(a).name() << endl;
    // passByAddress(a);
    // int a = 1;
    // passByRef(a+1);

    // unordered_map<char, int> um;
    // um.insert(std::make_pair('a',1));
    // // Common usage
    // cout << um['a'] << endl; // 1
    // cout << um.empty() << endl; // false
    // // cout << um.find('a') << endl; // 
    // cout << (um.find('a') != um.end()) << endl; //
    // unordered_map<char, int>::const_iterator it = um.find('a');
    // cout << it->first << " " << it->second << endl;

    // string s = "123";
    // // string p = "new" + to_string(s[0]);
    // string p = "new" + to_string(s[0]);
    // cout << p << endl;

    // stack<int,std::vector<int> > third; 
    // third.push(1);
    // cout << third.top();
    // cout << st.top();

    // string s;
    // cout << s.empty()<< endl;

    // cout << isalnum('a') << endl;
    // cout << static_cast<char>(tolower('A')) << endl;

    // unorderedMap();

    // array<int,6> ar = {1, 2, 3, 4, 5, 6};
    // array<int,6> a{1, 2, 3, 4, 5, 6};
    // cout << a[0];
    // a.fill(0);
    // cout << a[4];

    // vector<int> v = { 10, 20, 30 };
    // vector<int> v1{ 20, 30, 40 };

    // for(auto val: v){
    //     cout << val << endl;
    // }

    // const char *szSource("my string");
    // cout << strlen(szSource) << endl;

    // char a = 'a';
    // ostringstream o;
    // o << a;
    // // string s (o.str());
    // // string s(static_cast<string>(a));
    // char ch = 'a'; 
    // string p(to_string(ch)); //97
    // string p1 = "test" + o.str();//testa
    // string str{ch}; //a

    // cout << p1 << endl;
    // cout << str << endl;

    // std::istringstream iStream("123");
    // int i;
    // iStream >> i;
    // cout << i << endl;

    // string s = "hello";
    // const char *ch = s.c_str();
    // cout << ch << endl;

    // string str = "3.14";
    // int i = std::stoi(str); // 3, need to pass str.c_str() in c
    // double d = std::stod(str); // 3.14, need to pass str.c_str() in c
    // cout << i << endl;
    // cout << d << endl;

    // string str = "cat";
    // char ca[4];
    // strcpy(ca, str.c_str());
    // cout << ca << endl;

    // int a[]{3,1,2,5,4};
    // // quicksort(a, 0, sizeof(a)/sizeof(a[0])-1);
    // mergesort(a, 0, sizeof(a)/sizeof(a[0])-1);

    // for(int i = 0; i < 5; i++)
    //     cout << a[i] << endl;

    // char c = 'b';
    // string s("abc");
    // // s += c + 1;
    // s += 97;
    // string s1{'c'};
    // cout << s << endl;
    // cout << typeid('a' + 1).name() << endl;
    // cout << typeid("abc").name() << endl;
    // cout << static_cast<char>('a' + 1) << endl;

    // string s = "abc";
    // const char * ch= s.data();
    // cout << ch << endl;

    // char buf[3];
    // char buf1[3];
    // cin >> setw(3) >> buf >> buf1;
    // cout << buf << " " << buf1;

    // char strBuf[4];
    // cin.getline(strBuf, 4);
    // cout << strBuf << endl;
    // cout << cin.gcount() << " characters were read" << endl;

    // cout << isdigit('a');
    // cout << isdigit('1');

    // cout << fib(6) << endl;

    // map<int, int> gquiz1; 
    // gquiz1.insert(pair<int, int>(4, 20)); 
    // gquiz1.insert(pair<int, int>(3, 60)); 
    // for (auto itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) { 
    //     cout << '\t' << itr->first 
    //          << '\t' << itr->second << '\n'; 
    // } 
    
    // int a[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    // int asize = sizeof(a) / sizeof(a[0]);
    // sort(a, a + asize); 
    // if (binary_search(a, a + 10, 2))
    //     cout << "\nElement found in the array";

    // int n = -12;
    // cout << n / 10 << " " << n % 10;

    // string s = "Abc";
    // string s1 = "test";
    // string s2 = s1 + s[0];
    // string s3 = static_cast<string>(s[0]);
    // string s4 = (string)s[0];
    // string s4(s[0]);
    // cout << s2 << endl;
    // cout << s3 << endl;
    // cout << s4 << endl;

    // s[0]= s[0] - ('a' - 'A');
    // s[0] ^= (1<<5);
    // cout << s[0];
    // s[0] ^= (1<<5);
    // cout << s[0];

    // char a = 'a', b = 'B';
    // a ^= (1<<5);
    // b ^= (1<<5);
    // cout << a << " " << b; // A b

    // char c = a - ('a' - 'A');
    // char c = a - 32;
    // cout << c;

    // cout << s2;
    // assert(longestSubstringKDistinct("araaci", 2) == 4);
    // assert(longestSubstringKDistinct("araaci", 1) == 2);
    // assert(longestSubstringKDistinct("cbbebi", 3) == 5);

    // queue<int>q{{1}};
    // stack<int>s{{1}};
    // vector<int>v{1};

    // int i;  //Undefined Behavior, Might be Initialized to anything
    // static int j; //Zero Initialized
    // cout<<"\nLocal Uninitialized int variable [i]"<<i<<"\n";
    // cout<<"\nLocal Uninitialized Static int variable [j]"<<j<<"\n";
    // cout<<"\nGlobal Uninitialized Static int variable [a]"<<a<<"\n";
    // cout<<"\nGlobal Uninitialized int variable [b]"<<b<<"\n";

    // vector<int> v(5);
    // cout << v[4];
    // unordered_map<char, int>um;
    // um['a']++;
    // cout << um['a'];
    // int a[3] = {4};
    // string s[3]{"a"};
    // cout << a[0] << " " << a[1] << " " << a[2] << endl;
    // cout << s[0] << " " << s[1] << " " << s[2] << endl;
    // char c;
    // cout << c << endl;

    // priority_queue<int, vector<int>, greater<int>> pq;
    // priority_queue<int> pq;
    // pq.push(3);
    // pq.push(2);
    // pq.push(4);
    // cout << pq.top() << endl;
    // pq.pop();
    // cout << pq.top() << endl;
    // pq.pop();
    // cout << pq.top() << endl;
    // pq.pop();

    // int arr[]{3,1,2,4};
    // sort(arr, arr+sizeof(arr)/sizeof(arr[0]));
    // vector<int>vec(arr, arr+sizeof(arr)/sizeof(arr[0]));
    // sort(vec.begin(), vec.end());
    // sort(arr, arr+sizeof(arr)/sizeof(arr[0]), greater<int>());
    // sort(vec.begin(), vec.end(), greater<int>());
    // for (int i = 0; i < 4; ++i)
    // {
    //     cout << vec[i] << endl;
    // }
    
    // vector<vector<int>> intervals{{2,12},{8,10},{1,3},{15,18}};
    // sort(intervals.begin(), intervals.end(), compare);
    // for(auto intv : intervals){
    //     cout << intv[0] << " " << intv[1] << endl;
    // }
    return 0;
}