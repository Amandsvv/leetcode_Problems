// Given an integer n, return true if it is a power of two. Otherwise, return false.

// An integer n is a power of two, if there exists an integer x such that n == 2x.

#include<iostream>

using namespace std;
bool isPowerOfTwo(int n) {
    long int pow = 1;

    while(pow <= n){
        if(pow == n) return true;
        pow*=2;
    }

    return false;
}

bool isvalid(int m){
    return m > 0 && (m &(m-1) == 0);
}
int main(){
    int n = 16;
    cout<<(14==4);
} 