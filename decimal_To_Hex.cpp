#include<iostream>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";

        string hex = "0123456789abcdef";
        string ans = "";

        unsigned int n = num;  // handles negative numbers in 2's complement

        while(n > 0) {
            ans = hex[n & 15] + ans;  // last 4 bits
            n >>= 4;
        }

        return ans;
    }
};
int main(){
}
