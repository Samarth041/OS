#include<iostream>
#include<unistd.h>
using namespace std;
int main(){
    pid_t pid=fork();

    if (pid==0){
        cout<<"Child PID= "<<getpid()<<" , PPID= "<<getppid()<<"\n";
        sleep(5);
        cout<<"Child after parent exits: PID = "<<getpid()<<" , PPID= "<<getppid()<<"\n";
    }

    else{
        cout<<"Parent : PID = "<<getpid()<<"\n";

        cout<<"Parent exiting...\n";
    }
    return 0;
}