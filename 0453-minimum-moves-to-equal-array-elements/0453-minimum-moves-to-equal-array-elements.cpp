class Solution {
public:
    int minMoves(vector<int>& nums) {
        // 1  2  3
        /*
            koi bhi equal ho jaye

            3 5 6

        */

        int minVal = INT_MAX;
        for(int val: nums){
            minVal = min(minVal, val);
        }

        int ans = 0;
        for(int val: nums){
            ans += val - minVal;
        }

        return ans;
    }

};