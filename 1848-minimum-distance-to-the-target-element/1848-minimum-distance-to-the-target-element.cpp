class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int x = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                if(x == -1) x = abs(i -start);
                else x = min(abs(i- start), x);
            }
        }
        return x;
    }
};