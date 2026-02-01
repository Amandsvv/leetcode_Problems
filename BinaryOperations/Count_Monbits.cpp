// 3827. Count Monobit Integers
// Solved
// Easy
// premium lock icon
// Companies
// Hint
// You are given an integer n.

// An integer is called Monobit if all bits in its binary representation are the same.

// Return the count of Monobit integers in the range [0, n] (inclusive).
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Solution {
public:
    int countMonobit(int n) {
       return static_cast<int>(log2(n+1)) + 1;
    }
};

int main (){

}