class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int sz = nums.size();
        vector<pair<int, int>> sumPair;

        // matter where to store the sum & indices

        for (int i = 0; i < sz; i++) {
            int num = nums[i];
            int x = nums[i];
            int s = 0;
            while (num) {
                s += num % 10;
                num /= 10;
            }
            sumPair.push_back({x, s});
        }

        sort(sumPair.begin(), sumPair.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 if (a.second != b.second) {
                     return a.second < b.second;
                 }
                 return a.first < b.first;
             });

        unordered_map<int, int> mp;
        for (int i = 0; i < sz; i++) {
            mp[nums[i]] = i;
        }

        vector<int> perm(sz);
        for (int i = 0; i < sz; i++) {
            perm[i] = mp[sumPair[i].first];
        }

        // Count cycles in the permutation
        vector<bool> visited(sz, false);
        int cycles = 0;
        for (int i = 0; i < sz; i++) {
            if (!visited[i]) {
                cycles++;
                int j = i;
                while (!visited[j]) {
                    visited[j] = true;
                    j = perm[j];
                }
            }
        }

        return sz - cycles;

        return 0;
    }
};