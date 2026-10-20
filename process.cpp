
#include <iostream>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int main() {
    int i = 1;

    do {
        cout << "Process running... Count = " << i << endl;
        sleep(2);  // Pause for 2 seconds
        i++;
    } while (true);

    return 0;
}


/*

first run it and then open new terminal and run

 ps -a :- to see which program is running 

then yu can  see ppid with ps -al 

and if yu want to kill the process yu can use kill -9 pid to kill that process ; here -9 denote yu are killing it forcefully
*/
