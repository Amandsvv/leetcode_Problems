class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for( int num : nums){
            vector<long long> newDp(k, 0);
            int numMod = num % k;

            newDp[numMod] = 1;

            for( int r = 0; r < k; r++){
                if(dp[r] == 0) continue;
                int newRem = (1LL * r * numMod) % k;
                newDp[newRem] += dp[r];
            }

            for(int r = 0; r < k; ++r){
                ans[r] += newDp[r];
            }
            dp = std::move(newDp);
        }
        return ans;
    }
};