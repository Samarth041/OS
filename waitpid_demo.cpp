#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;
int main(){
    pid_t child1=fork();

    if(child1==0){
        cout<<"Child 1 started \n";
        sleep(2);
        cout<<"Child 1 finished\n";
        return 10;
    }

    pid_t child2=fork();
    if(child2==0){
        cout<<"Child 2 started\n";
        sleep(5);
        cout<<"Child 2 finished\n";
        return 20;
    }

    //Parent

    cout<<"Parent is waiting for child1\n";

    int status;
    waitpid(child1,&status,0);
    cout<<"Parent : Child 1 finished \n";

    return 0;

}