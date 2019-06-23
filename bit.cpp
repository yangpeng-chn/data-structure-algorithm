#include "iostream"
using namespace std;

bool isPowerOfTwo(int x){
    if (x == 0) return false;
    while( x % 2 == 0) x /= 2;
        return x==1;
}

int main(){
    unsigned int a=1;
    unsigned int b=2;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "~a: " << ~a << endl;//2^32 - 1 - 1 = 4294967294
    cout << "~b: " << ~b << endl;//2^32 - 1 - 2 = 4294967293
    cout << "a^b: " << (a^b) << endl; // 3
    cout << "a&b: " << (a&b) << endl; // 0
    cout << "a|b: " << (a|b) << endl; // 3
    cout << "a>>1 (right shift, devide by 2): " << (a>>1) << endl; // 0
    cout << "a<<1 (left shift, multiply by 2): " << (a<<1) << endl; // 2

    cout << isPowerOfTwo(3) << endl; 
    cout << isPowerOfTwo(4) << endl; 
    return 0;
}
