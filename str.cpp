#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    string str = "aaccbb";
    sort(str.begin(),str.end());
    cout<<str;
    return 0;
}