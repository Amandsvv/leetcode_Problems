#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int numSteps(string s) {
        int count = 0, carry = 0;

        for(int i = s.length() - 1; i > 0; i--){
            if((s[i] - '0' + carry) == 1){
                count+=2; // +2 because of /2 & +1
                carry = 1; // carry is going to be 1
            }else{
                count++; //If it was even dividing it by 2 just decrease 1 last bit (char) in binary string
            }
        }
        return carry + count;
    }
};
int main (){
    string s = "100010101001";
    Solution obj;
    cout<<obj.numSteps(s);
    return 0;
}