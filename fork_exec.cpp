#include<iostream>
#include<unistd.h>
using namespace std;
int main(){
    pid_t pid=fork();

    if (pid==0){
        cout<<"Child before execution";
        execlp("ls","ls",nullptr);
        cout<<"child after  execution";

    }

    else{
        cout<<"Parent";
    }
    return 0;
}