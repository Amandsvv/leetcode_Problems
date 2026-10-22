class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;

        int idx = -1;
        for(int i = 0; i < n ; ++i){
            if(nums[i] == 0){
                idx = i;
                break;
            }
        }

        bool isNormal = true;
        for(int i = 0; i < n; ++i){
            if(nums[(i + 1) % n] != (nums[i] + 1 ) % n){
                isNormal = false;
                break;
            }
        }

        if(isNormal){
            int cost1 = idx;
            int cost2 = (idx > 0) ? (2 + (n - idx)) : INT_MAX;
            return min(cost1, cost2);
        }

        bool isReversed = true;
        for(int i = 0; i < n; ++i){
            if(nums[i] != (nums[(i + 1) % n] + 1) % n){
                isReversed = false;
                break;
            }
        }

        if(isReversed){
            int cost3 = n - idx;
            int cost4 = ((idx + 1) % n) + 1;
            return min(cost3, cost4);
        }

        return -1;
    }
};