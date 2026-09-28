class Solution {
public:
    int maxDepth(string s) {
        stack<char> stk;
        int ans = 0;
        for(char& ch : s){
            if(ch == '('){
                stk.push(ch);
            }else if(ch == ')'){
                stk.pop();
            }
            ans = max(ans, (int)stk.size());
        }
        return ans;
    }
};