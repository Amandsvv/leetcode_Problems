class Solution {
public:
    bool rec(vector<int>& nums,int i,int j,long long pl1,long long pl2, int turn){
        if(i > j){
           return pl1 >= pl2;
        }
        if(turn == 0){
            return rec(nums, i+1, j, pl1 + nums[i], pl2, 1) || rec(nums, i, j-1, pl1 + nums[j], pl2, 1);
        }else{
            return rec(nums, i+1, j, pl1, pl2 + nums[i], 0) && rec(nums, i, j-1, pl1 , pl2 + nums[j], 0);
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int i = 0, j = nums.size() -1;
        return rec(nums, i, j, 0, 0, 0);
    }
};