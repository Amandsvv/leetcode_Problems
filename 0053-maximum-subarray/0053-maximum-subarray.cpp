class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum = 0, lar_sum = INT_MIN;
        for(int val : nums){
            curr_sum += val;
            lar_sum  = max(lar_sum, curr_sum);

            if(curr_sum < 0){
                curr_sum = 0;
            }
        }
        return lar_sum;
    }
};