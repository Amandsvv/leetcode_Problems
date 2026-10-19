class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> result;
        int lessThanTar = 0;
        int tar = 0;
        for(const auto & el: nums){
            if(el < target) lessThanTar++;
            else if(el == target) tar++;
        }
        for(int i = lessThanTar; i < lessThanTar + tar; i++){
            result.push_back(i);
        }
        return result;
    }
};