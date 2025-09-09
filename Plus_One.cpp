// You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

// Increment the large integer by one and return the resulting array of digits.

#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits)
{
    int n = digits.size(); // Taking size of array of digits
    int carry = 0; //counting carry which should be added forward 
    for (int i = n-1; i >= 0; i--) //starting from the last as we have to add from the last postion
    {
        int sum = digits[i] + 1;

        if (sum == 10) //checking if there is any carry
        {
            carry = 1;
            digits[i] = 0;
        }
        else // if there is no carry assigning value at the ith index with the sum and making carry as 0
        {
            digits[i] = sum;
            carry = 0;
        }

        if (carry == 0) // if there is no carry so it will be pour final form of resulting array so returns it
        {
            return digits;
        }
    }

    if (carry == 1) // at last also checking if any carry remaining only possib;e if a;rgest integer would be 9, 99, 999 .....
    {
        digits[0] = 1; // so at 1st index 1
        digits.push_back(0); //and at last 0 is being pushed out 
    }
    return digits;
}
int main()
{
    vector<int> digits = {1,2,3};

    plusOne(digits);

    for (int el : digits){
        cout<<el<<" ";
    }
}