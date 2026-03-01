#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string trimTrailingVowels(string s) {
        string newS = "";
        int n = s.length();
        int j = n -1;
        while(j >= 0 && (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o'|| s[j] == 'u' )) j--;
        if(j < 0) return "";
        newS = s.substr(0,j+1);
        return newS;
    }
};
int main (){

}