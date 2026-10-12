class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int cnt[31] = {0};
        for(int & el : nums){
            int x = el;
            for(int i = 0; i < 31; ++i){
                if(x & (1 << i)) cnt[i]++;
            }
        }
        long long ans = 0;
        int MOD = 1e9+7;
        while(k--){
            long long x = 0;
            for(int i = 0; i < 31; i++){
                if(cnt[i] > 0){
                    x |= (1 << i);
                    cnt[i]--;
                }
            }
            ans = (ans + x*x) % MOD;
        }

        return (int)ans;
    }
};