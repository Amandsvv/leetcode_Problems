class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int balance = 0;
        for (char& ch : s) {
            if (ch == '(') {
                balance++;
                if(balance > 1) res.push_back(ch);
            } else {
                if(balance > 1) res.push_back(ch);
                balance--;
            }
        }
        return res;
    }
};