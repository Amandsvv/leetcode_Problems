class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int i = 0, far = 0;
        while(i < nums.size() && nums[i] != 1){
            i++;
        }
        i++;
        while(i < nums.size()){
            if(nums[i] == 1){
                if(far < k) return false;
                else far = 0;
            }else{
                far++;
            }
            i++;
        }
        return true;
    }
};