// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

#include <iostream>
#include <vector>
using namespace std;

int reverse(int x)
{
    if (x == -2147483648)
        return 0;
    if (x < 0)
    {
        x = -(x);

        long int rev = 0;

        while (x)
        {
            int dit = x % 10;
            if (rev * 10 > INT32_MAX)
            {
                return 0;
            }
            rev = rev * 10 + dit;
            x /= 10;
        }
        return -(rev);
    }
    else
    {
        long int rev = 0;

        while (x)
        {
            int dit = x % 10;
            if (rev * 10 > INT32_MAX)
            {
                return 0;
            }
            rev = rev * 10 + dit;
            x /= 10;
        }
        return rev;
    }
}

int main()
{
    int x = -123;
    cout<<reverse(x);
}