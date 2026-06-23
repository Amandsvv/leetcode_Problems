class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int val = r - l + 1;
        int MOD = 1e9 + 7;
        vector<int> dp(val, 1);
        for(int i = 2; i <= n; i++){
            reverse(dp.begin(), dp.end());
            int sum = 0;
            for(auto & d : dp){
                sum = (sum + exchange(d, sum)) % MOD;
            }
        }

        return ((accumulate(dp.begin(), dp.end(), 0LL) % MOD) << 1) % MOD;

    }
};