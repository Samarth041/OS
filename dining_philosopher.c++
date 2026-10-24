
#include <iostream>
#include <thread>
#include <semaphore.h>
#include <array>
#include <mutex>
#include <vector>

using namespace std;

const int N = 5;

sem_t room; //creates a semaphore that controls how many philosophers can compete for forks at once.
array<sem_t, N> forks;//creates a semaphore that controls how many philosophers can compete for forks at once.
mutex printMutex;

void philosopher(int id) {
    int left = id;
    int right = (id + 1) % N;

    for (int meal = 1; meal <= 3; meal++) {
        {
            lock_guard<mutex> lock(printMutex);
            cout << "Philosopher " << id
                 << " is thinking\n";
        }

        // Allow at most 4 philosophers to compete
        sem_wait(&room);

        // Pick up both forks
        sem_wait(&forks[left]);
        sem_wait(&forks[right]);

        {
            lock_guard<mutex> lock(printMutex);
            cout << "Philosopher " << id
                 << " is eating meal " << meal << '\n';
        }

        // Put down both forks
        sem_post(&forks[left]);
        sem_post(&forks[right]);

        // Leave the room
        sem_post(&room);
    }

    lock_guard<mutex> lock(printMutex);
    cout << "Philosopher " << id
         << " has finished eating\n";
}

int main() {
    sem_init(&room, 0, 4);

    for (int i = 0; i < N; i++) {
        sem_init(&forks[i], 0, 1);
    }

    vector<thread> philosophers;

    for (int i = 0; i < N; i++) {
        philosophers.emplace_back(philosopher, i);
    }

    for (auto& p : philosophers) {
        p.join();
    }

    for (int i = 0; i < N; i++) {
        sem_destroy(&forks[i]);
    }

    sem_destroy(&room);

    cout << "All philosophers have finished.\n";
    return 0;
    
}


/*At most four philosophers can compete for forks at once.
sem_init(&forks[i], 0, 1)	Each fork is available to one philosopher at a time.
sem_wait(&room)	Enter only if a room permit is available.
sem_wait(&forks[left])	Acquire the left fork.
sem_wait(&forks[right])	Acquire the right fork.
sem_post(&forks[left])	Release the left fork.
sem_post(&forks[right])	Release the right fork.
sem_post(&room)	Return the room permit so another philosopher can compete.*/
