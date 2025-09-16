// 125. Valid Palindrome

// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric
//  characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(string s)
{

    string alphaNumeric = "";

    for (int i = 0; i < s.size(); i++)
    {
        if ('A' <= s[i] && s[i] <= 'Z')
        {
            char l = char(s[i] + 32);
            alphaNumeric.push_back(l);
        }
        else if ('a' <= s[i] && s[i] <= 'z' || '0' <= s[i] && s[i] <= '9')
        {
            alphaNumeric.push_back(s[i]);
        }
        else
        {
            continue;
        }
    }

    int i = 0, j = alphaNumeric.size() - 1;

    while (i < j)
    {
        if (alphaNumeric[i] != alphaNumeric[j])
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

int main()
{
    // string s = "race a car";
    // cout<<isPalindrome(s);

    vector<int> A = {1,2,3,4,1};
    int sum =0;
    for(int el : A){
        sum ^= el;
    }

    cout<<sum;

    return 0;
}