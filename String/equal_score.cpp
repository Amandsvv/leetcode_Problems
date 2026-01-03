#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool scoreBalance(string s) {
        int rightSum = 0, leftSum = 0;
        for(char ch : s){
            rightSum+=(ch-'a'+1);
        }
        for(int i = 0; i < s.size(); i++){
            leftSum+=(s[i]-'a'+1);
            rightSum-=(s[i]-'a'+1);
            if(leftSum == rightSum) return true;
        }
        return false;
    }
};

int main (){


}