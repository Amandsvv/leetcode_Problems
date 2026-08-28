#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        char midChar = 0;
        int oddCount = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                oddCount++;
                midChar = i + 'a';
            }
        }

        if (oddCount > 1) return "";

        int m = n / 2;
        vector<int> half_freq(26, 0);
        for (int i = 0; i < 26; i++) {
            half_freq[i] = freq[i] / 2;
        }

        auto makePalindrome = [&](const string& half) {
            string rev = half;
            reverse(rev.begin(), rev.end());
            if (midChar) return half + midChar + rev;
            return half + rev;
        };

        // Helper to fill remaining characters lexicographically
        auto fillSmallest = [](vector<int> counts) {
            string res = "";
            for (int i = 0; i < 26; i++) {
                if (counts[i] > 0) {
                    res += string(counts[i], i + 'a');
                }
            }
            return res;
        };

        // Case 1: First half matches target[0...m-1] exactly
        vector<int> temp_counts = half_freq;
        bool can_match_exact = true;
        for (int i = 0; i < m; i++) {
            int char_idx = target[i] - 'a';
            if (--temp_counts[char_idx] < 0) {
                can_match_exact = false;
                break;
            }
        }

        if (can_match_exact) {
            string exact_half = target.substr(0, m);
            string pal = makePalindrome(exact_half);
            if (pal > target) return pal;
        }

        // Case 2: Diverge at position i (from m-1 down to 0)
        for (int i = m - 1; i >= 0; i--) {
            // Recompute available counts for prefix target[0...i-1]
            vector<int> cur_counts = half_freq;
            bool prefix_valid = true;
            for (int j = 0; j < i; j++) {
                int char_idx = target[j] - 'a';
                if (--cur_counts[char_idx] < 0) {
                    prefix_valid = false;
                    break;
                }
            }

            if (!prefix_valid) continue;

            // Try picking a character strictly greater than target[i]
            for (int c = (target[i] - 'a') + 1; c < 26; c++) {
                if (cur_counts[c] > 0) {
                    cur_counts[c]--;
                    string half = target.substr(0, i);
                    half += (char)(c + 'a');
                    half += fillSmallest(cur_counts);
                    return makePalindrome(half);
                }
            }
        }

        return "";
    }
};