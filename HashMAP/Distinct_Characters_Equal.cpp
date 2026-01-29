#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
class Solution {
public:
    bool isItPossible(string word1, string word2) {
        unordered_map<char, int> word1Freq, word2Freq;

        for (int i = 0; i < word1.size(); i++) {
            word1Freq[word1[i]]++;
        }
        for (int i = 0; i < word2.size(); i++) {
            word2Freq[word2[i]]++;
        }

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                char c1 = 'a' + i;
                char c2 = 'a' + j;
                if (!word1Freq.count(c1) || !word2Freq.count(c2))
                    continue;

                word2Freq[c2]--;
                word1Freq[c1]--;

                if (word1Freq[c1] == 0)
                    word1Freq.erase(c1);
                if (word2Freq[c2] == 0)
                    word2Freq.erase(c2);

                word1Freq[c2]++;
                word2Freq[c1]++;

                if (word1Freq.size() == word2Freq.size())
                    return true;

                word1Freq[c2]--;
                word2Freq[c1]--;

                if (word1Freq[c2] == 0)
                    word1Freq.erase(c2);
                if (word2Freq[c1] == 0)
                    word2Freq.erase(c1);

                word2Freq[c2]++;
                word1Freq[c1]++;
            }
        }
        return false;
    }
};
int main (){

}