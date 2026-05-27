class Solution {
public:
    int numberOfSpecialChars(string word) {
        int firstLower[26];
        int firstUpper[26];

        for (int i = 0; i < 26; ++i) {
            firstLower[i] = -1;
            firstUpper[i] = -1;
        }

        for (int i = 0; i < word.size(); ++i) {
            char ch = word[i];
            if (ch >= 'a' && ch <= 'z') {
                firstLower[ch - 'a'] = i;
            } else if (ch >= 'A' && ch <= 'Z') {
                if (firstUpper[ch - 'A'] == -1) {
                    firstUpper[ch - 'A'] = i;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < 26; ++i) {
            if (firstLower[i] != -1 && firstUpper[i] != -1) {
                if (firstLower[i] < firstUpper[i]) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};