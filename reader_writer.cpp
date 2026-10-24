/*
semaphore mutex = 1;
semaphore wrt = 1;
int readCount = 0;

// Reader
wait(mutex);
readCount++;

if (readCount == 1) {
    wait(wrt);       // First reader blocks writers
}

signal(mutex);

// Read the shared resource

wait(mutex);
readCount--;

if (readCount == 0) {
    signal(wrt);     // Last reader allows writers
}

signal(mutex);


// Writer
wait(wrt);

// Write to the shared resource

signal(wrt);
*/

/*Understand the reader code step by step
When the first reader arrives:
1. It locks mutex to safely update readCount.
2. readCount changes from 0 to 1.
3. Because it is the first reader, it locks wrt.
4. It releases mutex and starts reading.
When another reader arrives:
- readCount increases from 1 to 2.
- It does not need to acquire wrt again.
- Both readers can read simultaneously.
When a reader finishes:
- It decreases readCount.
- If readers remain, wrt stays locked.
- If readCount becomes 0, the last reader releases wrt, allowing a writer to proceed.*/

#include<iostream>
#include<thread>
#include<shared_mutex>
#include<mutex>
#include<vector>

using namespace std;

shared_mutex rwMutex;
int marks=70;

void reader(int id){
    shared_lock<shared_mutex> lock(rwMutex);
    
    cout<<"reader "<<id<<" read marks: "<<marks<<endl;
}

void writer(){
    unique_lock<shared_mutex> lock(rwMutex);
    marks=90;

    cout<<"Writer updated marks to : "<<marks<<endl;
}

int main(){
    vector<thread> readers;

    //two readers read the original value
    readers.emplace_back(reader,1);
    readers.emplace_back(reader,2);

    for (auto& t:readers){
        t.join();
    }

    //writers updates teh marks
    thread w(writer);
    w.join();

    //a new thread sees the updated value

    thread r(reader,3);
    r.join();
    return 0;
}