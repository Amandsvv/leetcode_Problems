class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> unionPath(n);
        for(int i = 0; i < n; i++){
            unionPath[i] = i;
        }
        for(int i = 0; i < n-1 ; i++){
            if(abs(nums[i+1] - nums[i]) <= maxDiff){
                unionPath[i+1] = unionPath[i];
            }
        }
        for(auto & el : unionPath)cout<<el;
        vector<bool> ans;
        for(auto & vec: queries){
            ans.push_back(unionPath[vec[0]] == unionPath[vec[1]]);
        }
        return ans;
    }
};