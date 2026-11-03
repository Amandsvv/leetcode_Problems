class Solution {
public:
    int minMoves(vector<int>& nums) {
       int maxel = *(max_element(nums.begin(), nums.end()));
       int res = 0;
       for(auto & el : nums) res += maxel - el;
       return res; 
    }
};