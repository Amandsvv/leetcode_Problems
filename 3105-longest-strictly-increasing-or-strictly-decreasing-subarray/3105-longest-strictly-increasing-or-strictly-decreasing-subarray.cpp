class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incr = 1, decr = 1;
        int rec = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){
                rec++;
            }else{
                rec = 1;
            }
            incr = max(incr, rec);
        }
        rec = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1]){
                rec++;
            }else{
                rec = 1;
            }
            decr = max(decr, rec);
        }
        return max(incr, decr);
    }
};