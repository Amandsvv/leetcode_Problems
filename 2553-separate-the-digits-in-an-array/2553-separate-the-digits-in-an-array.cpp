class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(auto & el : nums){
            vector<int> temp;
            while(el){
                temp.push_back(el%10);
                el/=10;
            }
            reverse(temp.begin(), temp.end());
            ans.insert(ans.end(), temp.begin(), temp.end());
        }
        return ans;
    }
};