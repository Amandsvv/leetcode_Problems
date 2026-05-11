class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(auto & el : nums){
            for(auto & c : to_string(el)){
                ans.push_back(c-'0');
            }
        }
        return ans;
    }
};