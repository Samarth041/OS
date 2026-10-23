
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

mutex m;
condition_variable cv;
bool done = false;

void taskA() {
    unique_lock<mutex> lock(m);

    cv.wait(lock, [] {
        return done;
    });

    cout << "Task A proceeds\n";
}

void taskB() {
    {
        lock_guard<mutex> lock(m);
        cout << "Task B completes its work\n";
        done = true;
    }

    cv.notify_one();
}

int main() {
    thread t1(taskA);
    thread t2(taskB);

    t1.join();
    t2.join();
}
