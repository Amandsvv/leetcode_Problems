class Solution {
public:
    void helper(vector<string>& ans, int open, int close, int n, string curr){
        if(open == n && close == n){
            ans.push_back(curr);
            return;
        }

        if(open < n){
            helper(ans, open + 1, close, n, curr + '(');
        }

        if(close < open){
            helper(ans, open, close + 1, n, curr + ')');
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans, 0, 0, n, "");
        return ans;
    }
};