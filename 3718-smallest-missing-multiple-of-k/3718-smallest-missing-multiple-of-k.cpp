class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mul = 1;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > k*mul){
                return k*mul;
            }else if(nums[i] == k*mul){
                mul++;
            }else{
                continue;
            }
        }
        return k*mul;
    }
};