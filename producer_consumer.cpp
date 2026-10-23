/*
semaphore mutex = 1;
semaphore empty = N;
semaphore full = 0;

// Producer
while (true) {
    item = produce_item();

    wait(empty);   // Wait for an empty slot
    wait(mutex);   // Lock the buffer

    insert_item(item);

    signal(mutex); // Unlock the buffer
    signal(full);  // One more filled slot
}

// Consumer
while (true) {
    wait(full);    // Wait for an available item
    wait(mutex);   // Lock the buffer

    item = remove_item();

    signal(mutex); // Unlock the buffer
    signal(empty); // One more empty slot

    consume_item(item);
}
*/


#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <semaphore>
#include <chrono>

using namespace std;

const int N = 5;

counting_semaphore<N> emptySlots(N);
counting_semaphore<N> full(0);

mutex m;
queue<int> buffer;

void producer() {
    for (int i = 1; i <= 10; i++) {
        int item = i;

        emptySlots.acquire();
        m.lock();

        buffer.push(item);
        cout << "Produced: " << item << endl;

        m.unlock();
        full.release();

        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void consumer() {
    for (int i = 1; i <= 10; i++) {
        full.acquire();
        m.lock();

        int item = buffer.front();
        buffer.pop();

        cout << "Consumed: " << item << endl;

        m.unlock();
        emptySlots.release();

        this_thread::sleep_for(chrono::milliseconds(150));
    }
}

int main() {
    thread p(producer);
    thread c(consumer);

    p.join();
    c.join();

    return 0;
}
