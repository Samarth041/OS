#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;
int main(){
    pid_t pid=fork();

    if (pid<0){
        cerr<<"fork() failed";
        return 1;
    }

    if (pid==0){
        cout<<"Child process\n";
        cout<<"PID : "<<getpid()<<"\n";
        cout<<"PPID: "<<getppid()<<"\n";
    }
    else{
        wait(nullptr);
        cout<<"Parent Process\n";
        cout<<"PID : "<<getpid()<<"\n";
        cout<<"PPID: "<<getppid()<<"\n";
    }
    return 0;
}