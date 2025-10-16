#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool isAnagram(string s1, string s2)
{
    unordered_map<char, int> freqS1;
    unordered_map<char, int> freqS2;
    for (char ch : s1)
    {
        freqS1[ch]++;
    }

    for (char ch : s2)
    {
        freqS2[ch]++;
    }

    return (freqS1 == freqS2);
}
vector<string> removeAnagrams(vector<string> &words)
{
    vector<string> ans;
    int j = 0, i = 1;
    while (i < words.size())
    {
        if (isAnagram(words[j], words[i]))
        {
            i++;
        }
        else
        {
            ans.push_back(words[j]);
            j = i;
        }
    }
    ans.push_back(words[j]);
    return ans;
}

int main()
{

}