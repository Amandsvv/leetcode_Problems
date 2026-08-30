class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) { 
        int sz = nums.size();

        int low = 0,sum = 0, ans = INT_MAX;

        for(int high = 0; high < sz; high++){
            sum+= nums[high];
            while(sum >= target){
                ans = min(ans, high - low + 1);
                sum-= nums[low];
                low++;
            }
        } 
        if(ans == INT_MAX) return 0;
        return ans;
    }
};