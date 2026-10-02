class Solution {
public:
    void helper(vector<string>& ans, int open, int close, int n, string& curr){
        if(open == n && close == n){
            ans.push_back(curr);
            return;
        }

        if(open < n){
            curr.push_back('(');
            helper(ans, open + 1, close, n, curr);
            curr.pop_back();
        }

        if(close < open){ // close only when there is any open brackets
            curr.push_back(')');
            helper(ans, open, close + 1, n, curr);
            curr.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        curr.reserve(2*n);
        helper(ans, 0, 0, n, curr);
        return ans;
    }
};