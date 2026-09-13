#include <iostream>
#include <unistd.h>

int main() {

    std::cout << "Before fork\n";

    fork();

    std::cout << "After fork\n";

    return 0;
}

