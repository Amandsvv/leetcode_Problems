#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int alternateDigitSum(int n) {
       string s = to_string(n);
        int sum = 0;
        int sign = 1;

        for (int i = 0; i < s.length(); i++) {
            // Convert char to int and apply sign
            sum += (s[i] - '0') * sign;
            // Flip the sign for the next digit
            sign *= -1;
        }

        return sum;
    }
};
int main (){

}