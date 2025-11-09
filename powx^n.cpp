#include<iostream>
#include<vector>
using namespace std;

int power(int x, int n){
    if(n == 0){
        return 1;
    }
    return  x * power(x, n-1);
}

int powerOptimised(int x, int n){
    if(n == 0){
        return 1;
    }

    if(n%2 == 0){
        int result = powerOptimised(x,n/2);
        return result * result;
    }else{
        int result = powerOptimised(x,(n-1)/2);
        return result * result * x;
    }
}
int main (){
    int x = 2;
    int n = -6;
    cout<<powerOptimised(x,n)<<endl;
}