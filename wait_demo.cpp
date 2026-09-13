#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;
int main(){
    pid_t pid=fork();

    if (pid==0){
        cout<<"Child : doinge work....."<<endl;
        sleep(3);
        cout<<"Child : finished"<<endl;
        return 42;
    }
    else{
        cout<<"Parent waiting .....\n";
        int status;
        wait(&status);

        cout<<"Parent : child finished\n";
    }

    return 0;
}