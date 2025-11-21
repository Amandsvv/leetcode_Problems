#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for(char ch : t){
            if(ch == s[i]){
                i++;
            }
        }
        if(i >= s.size()) return true;
        return false;
    }
};
int main (){

}