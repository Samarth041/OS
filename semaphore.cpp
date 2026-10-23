#include<iostream>
#include<thread>
#include<semaphore>
#include<vector>
using namespace std;

counting_semaphore<3> printers(3);

void usePrinter(int id){
    printers.acquire(); //take one permit

    cout<<"thread "<<id<<"is using a printer\n";

    //simulate printer work
    printers.release(); //return the permit

}

int main(){
    vector<thread> threads;

    for(int i=1;i<=5;i++){
        threads.emplace_back(usePrinter,1);

    }

    for(auto& t:threads){
        t.join();
    }
}