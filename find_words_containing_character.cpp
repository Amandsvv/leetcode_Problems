#include <iostream>
#include <vector>
using namespace std;

vector<int> findWordsContaining(vector<string> &words, char x)
{
    vector<int> ans;
    for (int i = 0; i < words.size(); i++)
    {
        string word = words[i];
        if (word.find(x) < word.size())
        {
            ans.push_back(i);
        }
    }
    return ans;
}

int main()
{
    
}