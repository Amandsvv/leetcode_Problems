#include<iostream>
#include<vector>
using namespace std;
bool canWinNim(int n){
    return n%4 != 0;
}
int main (){
    if(canWinNim(4))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}