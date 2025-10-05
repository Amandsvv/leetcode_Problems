#include<iostream>

using namespace std;

int fib(int n){
    if(n == 0 || n == 1){
        return n;
    }

    return fib(n-1) + fib(n-2);
}

int main(){
    cout<< "fibonacci till 5th term : "<<fib(5);
    return 0; 
}