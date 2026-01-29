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

class Solution {
public:
    bool isItPossible(string word1, string word2) {

        vector<int> f1(26, 0), f2(26, 0);

        for (char c : word1) f1[c - 'a']++;
        for (char c : word2) f2[c - 'a']++;

        int d1 = 0, d2 = 0;

        for (int i = 0; i < 26; i++) {
            if (f1[i] > 0) d1++;
            if (f2[i] > 0) d2++;
        }

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {

                // dono me hona chahiye
                if (f1[i] == 0 || f2[j] == 0) continue;

                int nd1 = d1;
                int nd2 = d2;

                if (i == j) {
                    // same char swap → no change
                    if (d1 == d2)
                        return true;
                    continue;
                }

                // word1 loses i
                if (f1[i] == 1) nd1--;

                // word1 gains j
                if (f1[j] == 0) nd1++;

                // word2 loses j
                if (f2[j] == 1) nd2--;

                // word2 gains i
                if (f2[i] == 0) nd2++;

                if (nd1 == nd2)
                    return true;
            }
        }

        return false;
    }
};

int main (){

}