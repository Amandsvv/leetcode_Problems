class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long, int> seen;
        for (auto& el : nums) {
            seen[el]++;
        }

        int maxLen = 0;

        if (seen.find(1) != seen.end()) {
            int cnt = seen[1];
            maxLen = cnt % 2 == 0 ? cnt - 1 : cnt;
        }

        for (auto& [num, cnt] : seen) {
            int currLen = 0;
            long long val = num;
            if (num == 1)
                continue;
            auto it = seen.find(val);
            int freq = (it == seen.end()) ? 0 : it->second;
            while (freq > 0) {
                if (freq >= 2)
                    currLen += 2;
                else {
                    maxLen = max(currLen + 1, maxLen);
                    break;
                }
                val *= val;

                auto it = seen.find(val);
                freq = (it == seen.end()) ? 0 : it->second;
            }
            if (freq == 0) {
                maxLen = max(maxLen, currLen - 1);
            }
        }

        return maxLen;
    }
};