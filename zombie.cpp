#include<iostream>
#include<unistd.h>
#include<cstdlib>
using namespace std;

int main(){
    pid_t pid=fork();

    if (pid==0){
        cout<<"Child : I am exiting ...\n";
        exit(42);
    }

    else{
        cout<<"Parent sleeping.... \n";
        sleep(30);
    }

    return 0;
}