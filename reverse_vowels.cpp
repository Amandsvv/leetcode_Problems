#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    string reverseVowels(string s) {
        string str = "";
        string vowel = "aeiouAEIOU";
        for(char ch : s){
            if(vowel.find(ch) != string::npos){
                str+=ch;
            }
        }
        reverse(str.begin(),str.end());
        int idx = 0;
        for(int i = 0; i< s.size(); i++){
            if(vowel.find(s[i]) != string::npos){
                s[i] = str[idx++];
            }
        }
        return s;
    }
};
int main (){

}