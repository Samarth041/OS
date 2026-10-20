#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

int counter=0;
mutex m;
void increment(){
    for(int i=0;i<1000;i++){
        lock_guard<mutex> lock(m);
        counter++;
    }
}

int main(){
    thread t1(increment);
    thread t2(increment);

    t1.join();
    t2.join();

    cout<<"Counter = " <<counter<<endl;
    return 0;
}

/*
mutex m protects the shared counter.

lock_guard<mutex> lock(m) locks the mutex when the guard is created and unlocks it when the guard goes out of scope.

Only one thread at a time can hold this mutex, so the increment operations are protected from interfering with each other.

Shared memory makes communication easier, but shared data must be synchronized when concurrent access can cause conflicts.
*/