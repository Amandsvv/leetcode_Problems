#include <iostream>
#include <vector>
using namespace std;

long long removeZeros(long long n)
{
    long long ans = 0;
    long long int mult = 1;
    while (n)
    {
        int dig = n % 10;
        if (dig != 0)
        {
            ans = ans + dig * mult;
            mult *= 10;
        }
        n /= 10;
    }
    return ans;
}

int main()
{
    long long n = 6703045605;
    cout<<removeZeros(n)<<endl;
    return 0;
}