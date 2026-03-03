#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    string invert(string s){
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0') s[i] = '1';
            else s[i] = '0';
        }
        return s;
    }
    char findKthBit(int n, int k) {
        string s = "0";

        for(int i = 1; i < n; i++){
            string invertedString = invert(s);
            reverse(invertedString.begin(), invertedString.end());
            string newS = s + "1" + invertedString;
            s = newS;
        }
        return s[k-1];
    }
};
int main (){

}