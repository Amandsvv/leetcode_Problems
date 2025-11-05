#include<iostream>
#include<vector>
using namespace std;
bool isPowerFour(int n){
    if(n < 1) return false;
    if(n &(n-1)) return false;

    return (n & 0x55555555);
}
int main (){
    int n = 16;
    if(isPowerFour(n)){
        cout<<"yes";
    }elae{
        cout<<"No";
    }
}