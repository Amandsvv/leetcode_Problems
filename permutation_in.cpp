// 567. Permutation in String

// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

#include <iostream>

using namespace std;
bool checkInclusion(string s1, string s2)
{
    int freq[26] = {0};

    for (int i = 0; i < s1.size(); i++)
    {
        freq[s1[i] - 'a']++;
    }

    int strt = 0, end = s1.size();

    while (end <= s2.size())
    {
        int widoFreq[26] = {0};
        for (int i = strt; i < end; i++)
        {
            widoFreq[s2[i] - 'a']++;
        }
        bool isFound = true;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] != widoFreq[i])
            {
                isFound = false;
                break;
            }
        }
        if (isFound)
            return true;
        strt++;
        end++;
    }
    return false;
}
int main()
{
    string s1 = "ab";
    string s2 = "biobyubaret";

    cout<<"Is a permutation : "<<checkInclusion(s1,s2)<<endl;
    return 0;
}