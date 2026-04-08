class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int MOD = 1e9+7;
        for(auto& vec : queries){
            int idx = vec[0];
            while(idx <= vec[1]){
                long long val = ((long long)nums[idx] * vec[3]) % MOD;
                nums[idx] = val;
                idx+=vec[2];
            }
        }
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans^=nums[i];
        }
        return ans;
    }
};