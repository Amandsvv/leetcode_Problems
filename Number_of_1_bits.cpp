// Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

#include <iostream>
#include <vector>
using namespace std;

int hammingWeight(int n)
{
    int res = 0;
    for (int i = 31; i >= 0; i--)
    {
        if ((n >> i) & 1)
        {
            res += 1;
        }
    }
    return res;
}

int main (){
    int n = 11;
    cout<<hammingWeight(n);
}