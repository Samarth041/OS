
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex m1, m2;

void thread1() {
    lock_guard<mutex> a(m1);
    this_thread::sleep_for(chrono::milliseconds(100));

    lock_guard<mutex> b(m2);
    cout << "Thread 1 finished\n";
}

void thread2() {
    lock_guard<mutex> a(m2);
    this_thread::sleep_for(chrono::milliseconds(100));

    lock_guard<mutex> b(m1);
    cout << "Thread 2 finished\n";
}

int main() {
    thread t1(thread1);
    thread t2(thread2);

    t1.join();
    t2.join();
}

/*Expected behavior: The program may hang without printing either completion message. The exact outcome depends on thread scheduling, so a hang is possible but not guaranteed on every run.

Why?
- Thread 1 locks m1 and waits for m2.
- Thread 2 locks m2 and waits for m1.
- Each holds a resource the other needs.
The program demonstrates hold and wait, mutual exclusion, no preemption, and circular wait.*/