class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int idx = nums.size() / 2;
        int midEl = nums[idx];

        int res = 0;
        for(auto & el : nums){
            res += abs(el - midEl);
        }
        return res;
    }
};