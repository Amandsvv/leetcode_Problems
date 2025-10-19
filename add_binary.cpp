// Given two binary strings a and b, return their sum as a binary string.
// Example 1:

// Input: a = "11", b = "1"
// Output: "100"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string addBinary(string a, string b)
{
    int carry = 0;

    int aLen = a.length();
    int bLen = b.length();

    // cout<<aLen;
    // cout<<endl;
    // cout<<bLen;

    if (aLen >= bLen)
    {
        int j = aLen - 1;
        for (int i = bLen - 1; i >= 0; i--)
        {
            if (b[i] == '0' && a[j] == '1' || b[i] == '1' && a[j] == '0')
            {
                if (carry == 0)
                {
                    a[j--] = '1';
                }
                else
                {
                    a[j--] = '0';
                }
            }
            else if (b[i] == '0' && a[j] == '0')
            {
                if (carry == 0)
                {
                    a[j--] = '0';
                }
                else
                {
                    a[j--] = '1';
                    carry = 0;
                }
            }
            else
            {
                if (carry == 0)
                {
                    carry = 1;
                    a[j--] = '0';
                }
                else
                {
                    a[j--] = '1';
                }
            }
        }
        if (j >= 0 && carry == 1)
        {
            while (carry == 1 && j >= 0)
            {
                if (a[j] == '0')
                {
                    a[j--] = '1';
                    carry = 0;
                }
                else
                {
                    a[j--] = '0';
                }
            }
        }

        if (carry == 1)
        {
            carry = 0;
            a.insert(a.begin(), '1');
        }

        return a;
    }
    else
    {
        int j = bLen - 1;
        for (int i = aLen - 1; i >= 0; i--)
        {
            if (a[i] == '0' && b[j] == '1' || a[i] == '1' && b[j] == '0')
            {
                if (carry == 0)
                {
                    b[j--] = '1';
                }
                else
                {
                    b[j--] = '0';
                }
            }
            else if (a[i] == '0' && b[j] == '0')
            {
                if (carry == 0)
                {
                    b[j--] = '0';
                }
                else
                {
                    b[j--] = '1';
                    carry = 0;
                }
            }
            else
            {
                if (carry == 0)
                {
                    carry = 1;
                    b[j--] = '0';
                }
                else
                {
                    b[j--] = '1';
                }
            }
        }

        if (j >= 0)
        {
            while (carry == 1 && j >= 0)
            {
                if (b[j] == '0')
                {
                    b[j--] = '1';
                    carry = 0;
                }
                else
                {
                    b[j--] = '0';
                }
            }
        }

        if (carry == 1)
        {
            carry = 0;
            b.insert(b.begin(), '1');
        }
        return b;
    }
    return "";
}

int convertN(string s){
    int num = 0;
    for(char ch : s){
        if(ch == '1'){
            num = num*10 + 1;
        }else{
            num = num*10;
        }
    }
    return num;
}

string addBnaryOptimised(string s1, string s2){
    int num1 = convertN(s1);
    int num2 = convertN(s2);
    
}

int main()
{
    string s = "11";
    string s2 = "1";
    cout<<addBinary(s,s2);
}
