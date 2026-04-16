class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int q : queries) {
            auto &vec = mp[nums[q]];

            if (vec.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            // Binary search to find position of q
            int pos = lower_bound(vec.begin(), vec.end(), q) - vec.begin();

            int m = vec.size();

            int left = vec[(pos - 1 + m) % m];
            int right = vec[(pos + 1) % m];

            // circular distance
            int d1 = abs(q - left);
            d1 = min(d1, n - d1);

            int d2 = abs(q - right);
            d2 = min(d2, n - d2);

            ans.push_back(min(d1, d2));
        }

        return ans;
    }
};