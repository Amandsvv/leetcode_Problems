class Solution {
public:
    vector<vector<int>> ans;
    void rec(vector<int>& cand, vector<int>& temp,int idx, int tar, int sum){
        if(sum == tar){
            ans.push_back(temp);
            return;
        }else if(sum > tar){
            return;
        }else{
            for(int i = idx; i < cand.size(); i++){
                temp.push_back(cand[i]);
                rec(cand, temp, i, tar, sum + cand[i]);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        rec(candidates, temp, 0, target, 0);
        return ans;
    }
};