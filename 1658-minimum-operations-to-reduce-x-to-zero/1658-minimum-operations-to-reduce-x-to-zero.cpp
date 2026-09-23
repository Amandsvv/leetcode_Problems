class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long sum = 0;
        for(int num: nums){
            sum+=num;
        }
        if(sum < x) return -1;

        int target = sum - x;
        int maxLen = -1;
        int currSum = 0;
        int left = 0;
        int sz = nums.size();

        for(int right = 0; right < sz; right++){
            currSum += nums[right];
            while(currSum > target && right >= left){
                currSum-=nums[left++];
            }
            if(currSum == target){
                maxLen = max(maxLen, right - left + 1);
            }
        }
        return maxLen == -1 ?  -1 : sz - maxLen;
    }
};