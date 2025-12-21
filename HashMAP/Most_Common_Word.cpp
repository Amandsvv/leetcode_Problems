#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> freq;

        for (char &c : paragraph) {
            if (!isalpha(c)) c = ' ';
            else c = tolower(c);
        }

        string word, ans;
        stringstream ss(paragraph);
        int maxFreq = 0;

        while (ss >> word) {
            if (!ban.count(word)) {
                freq[word]++;
                if (freq[word] > maxFreq) {
                    maxFreq = freq[word];
                    ans = word;
                }
            }
        }
        return ans;
    }
};

int main (){

}