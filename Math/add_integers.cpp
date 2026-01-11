// 258. Add Digits

// Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
#include <iostream>

using namespace std;

int addDigits(int num)
{
    int sum = 0;
    while (num)
    {
        sum += num % 10;
        num /= 10;
    }

    if (sum % 10 == sum)
    {
        return sum;
    }
    else
    {
        return addDigits(sum);
    }

    return -1;
}

int main()
{
    int n = 38;
    cout << addDigits(n);
    return 0;
}