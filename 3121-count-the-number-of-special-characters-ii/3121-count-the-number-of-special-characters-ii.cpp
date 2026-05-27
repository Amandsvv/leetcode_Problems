class Solution {
public:
    int numberOfSpecialChars(string word) {
        // Use arrays to store the first index of each character.
        // Initialize with -1 to indicate the character hasn't been seen yet.
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
                // Store only the FIRST occurrence of uppercase
                if (firstUpper[ch - 'A'] == -1) {
                    firstUpper[ch - 'A'] = i;
                }
            }
        }

        int cnt = 0;
        // Check every letter from 'a' to 'z'
        for (int i = 0; i < 26; ++i) {
            // If both lowercase and uppercase exist
            if (firstLower[i] != -1 && firstUpper[i] != -1) {
                // Check if lowercase appears BEFORE uppercase
                if (firstLower[i] < firstUpper[i]) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};