class Solution {
public:
    int scoreOfParentheses(string s) {
        int sz = s.size(), i = 0;

        stack<int> stk; // stores open bracket idx

        while (i < sz) {
            if (s[i] == '(') {
                stk.push(0);
            } else {
                int inside = stk.top();
                stk.pop();

                int top = 0;
                if (!stk.empty()) {
                    top = stk.top();
                    stk.pop();
                }
                if (inside == 0) {
                    stk.push(top + 1);
                } else {
                    stk.push(top + 2 * inside);
                }
            }
            i++;
        }
        return stk.top();
    }
};