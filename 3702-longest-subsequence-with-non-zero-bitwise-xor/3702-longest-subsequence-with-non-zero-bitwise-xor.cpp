class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int count0 = nums[0] == 0 ? 1: 0;
        int xorv = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] == 0) count0++;
            xorv^=nums[i];
        }

        if(count0 == n) return 0;
        if(xorv == 0) return n-1;
        return n;
    }
};