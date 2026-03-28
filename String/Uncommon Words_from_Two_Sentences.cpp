#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freq;
        stringstream ss(s1 + " " + s2);
        string word;

        while (ss >> word) {
            freq[word]++;
        }

        vector<string> ans;
        for (auto& [word, count] : freq) {
            if (count == 1) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};
int main (){

}