class Solution {
public:
    bool helper(string& s, string& d) {
        if (s.size() != d.size())
            return false;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != d[i])
                cnt++;
            if (cnt > 2)
                return false;
        }
        return true;
    }
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        vector<string> ans;
        for (auto& s : queries) {
            for (auto& d : dictionary) {
                if (helper(s, d)) {
                    ans.push_back(s);
                    break;
                }
            }
        }
        return ans;
    }
};