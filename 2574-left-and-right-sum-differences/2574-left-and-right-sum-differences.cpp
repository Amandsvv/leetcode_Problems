class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        if(1 == n) return {0};

        int totalSum = 0;
        for(int el : nums) totalSum += el;

        vector<int> ans;
        ans.reserve(n);

        int leftSum = 0;
        for(int el : nums){
            ans.push_back(abs(leftSum - (totalSum -= el)));
            leftSum+=el;
        }
        return ans;
    }
};