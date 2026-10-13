class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int&el:nums){
            if(el < 0){
                el = -el;
            }
        }
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        long long ans = 0;
        while(i < j){
            ans += ((nums[j] * nums[j]) - (nums[i] * nums[i]));
            j--; i++;
        }
        if(i == j){
            ans += nums[i] * nums[i];
        }
        return ans;
    }
};