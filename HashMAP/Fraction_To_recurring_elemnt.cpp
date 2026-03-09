#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // Handle edge cases
        if (numerator == 0) return "0";
        
        // Handle sign
        bool negative = (numerator < 0) ^ (denominator < 0);
        long long num = labs(numerator);
        long long den = labs(denominator);
        
        // Handle integer part
        string result = "";
        if (negative) result += "-";
        result += to_string(num / den);
        
        // Handle decimal part
        long long remainder = num % den;
        if (remainder == 0) return result;
        
        result += ".";
        
        // Track remainders and their positions
        unordered_map<long long, int> remainderPositions;
        string decimalPart = "";
        
        while (remainder != 0) {
            // If we've seen this remainder before, we have a cycle
            if (remainderPositions.find(remainder) != remainderPositions.end()) {
                int pos = remainderPositions[remainder];
                decimalPart.insert(pos, "(");
                decimalPart += ")";
                break;
            }
            
            // Store current remainder position
            remainderPositions[remainder] = decimalPart.size();
            
            // Perform long division
            remainder *= 10;
            decimalPart += to_string(remainder / den);
            remainder %= den;
        }
        
        result += decimalPart;
        return result;
    }
};
int main (){

}