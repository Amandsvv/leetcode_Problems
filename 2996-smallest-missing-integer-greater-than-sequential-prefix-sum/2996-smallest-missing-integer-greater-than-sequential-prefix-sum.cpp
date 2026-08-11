class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        int i = 1;
        while(i < nums.size() && nums[i] == nums[i-1] + 1){
            sum+=nums[i];
            i++;
        }

        unordered_set<int> seen;

        for(int i = 0; i < nums.size(); i++) seen.insert(nums[i]);

        for(int i = sum; ; i++){
            if(seen.find(i) == seen.end()) return i;
        }
        return 0;
    }
};