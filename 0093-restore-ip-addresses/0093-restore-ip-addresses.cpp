class Solution {
public:
    void helper(vector<string>& ans, string s, string curr, int dots, int idx) {
        if (dots == 4) {
            if (idx == s.size()) {
                curr.pop_back();
                ans.push_back(curr);
                return;
            }
        }

        for (int len = 1; len <= 3 && idx + len <= s.size(); len++) {
            string part = s.substr(idx, len);

            if (len > 1 && part[0] == '0')
                break;

            int val = stoi(part);
            if (val > 255)
                break;

            helper(ans, s, curr + part + '.', dots + 1, idx + len);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12)
            return {};
        vector<string> ans;
        helper(ans, s, "", 0, 0);
        return ans;
    }
};