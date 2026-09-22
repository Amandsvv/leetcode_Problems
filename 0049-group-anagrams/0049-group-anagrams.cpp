class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(const auto &str : strs){
            string s(26, '0');
            for(char ch : str){
                s[ch - 'a']++;
            }
            mp[s].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto & p: mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};