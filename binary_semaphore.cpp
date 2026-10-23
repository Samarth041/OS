#include <semaphore>
#include <iostream>
using namespace std;

binary_semaphore sem(1);

void task() {
    sem.acquire();

    cout << "Inside protected section\n";

    sem.release();
}

/*
This illustrates acquiring and releasing a single permit. In production code, ensure that the permit is released even if an exception occurs. For ordinary mutual exclusion, a C++ std::mutex with std::lock_guard is usually the clearer choice.
*/