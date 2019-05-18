//! Run with g++ thread_practice.cpp -pthread  && ./a.out

#include <iostream>
#include <thread>

using namespace std;


void f1()
{
    cout << "This is thread 1!\n";
}



int main()

{
    thread t1(f1); //* start running thread t1;
    //t1.join(); //* main thread waiting for t1 to finish

    t1.detach(); //*t1 will run freely on its own -- daemon process

    if (t1.joinable())
        t1.join();
    
    return 0;
}
