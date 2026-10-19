#include<iostream>
#include<thread>
using namespace std;

void task1(){
    for(int i=1;i<=5;i++){
        cout<<"task 1 "<<i<<"\n";
    }
}

void task2(){
    for(int i=1;i<=5;i++){
        cout<<"task 2"<<i<<"\n";
    }
}

int main(){
    thread t1(task1);
    thread t2(task2);

    t1.join();
    t2.join();

    return 0;
}