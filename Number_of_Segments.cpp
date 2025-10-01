#include<iostream>

using namespace std;
int countSegments(string s) {
    int i = 0,count = 0, n = s.size();

    while(i < n){
        while(s[i] == ' ' && i < n){
            i++;
        }
        if(i<n){
            count++;
        }
        while(s[i] != ' ' && i < n){
            i++;
        }
    }
    return count;
}
int main(){
    string s = "Hello my name is Aman";
    cout<<"No. of words in string is : "<<countSegments(s)<<endl;
    return 0;
}