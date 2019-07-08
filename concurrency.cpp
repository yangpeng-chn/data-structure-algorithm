#include <thread>
#include <iostream>
#include <chrono>
using namespace std;

int a = 1;
void thread1()
{
    // cout << "t1\n";
    a++;
}

void thread2()
{
    // cout << "t2\n";
    a++;
}

int main(int argc, char* argv[])
{
    thread t1(thread1);
    thread t2(thread2);

    t1.join();
    t2.join();
    cout << a << endl;
    return 0;
}