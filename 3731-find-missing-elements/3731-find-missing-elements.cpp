class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<bool> present(101, false);
        int start = INT_MAX, end = INT_MIN;
        for(auto & el : nums) {
            present[el] = true;
            start = min(el, start);
            end = max(end, el);
        }
        vector<int> ans;
        for(int i = start+1 ; i < end; i++) {
            if(!present[i]) ans.push_back(i);
        }

        return ans;
    }
};