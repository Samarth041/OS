#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        std::cerr << "fork failed\n";
        return 1;
    }

    if (pid == 0) {
        std::cout << "Child PID: " << getpid() << '\n';
    } else {
        std::cout << "Parent PID: " << getpid()
                  << ", child PID: " << pid << '\n';
        wait(nullptr);
        std::cout << "Child has finished\n";
    }

    return 0;
}