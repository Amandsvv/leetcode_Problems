class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        for(char ch : s){
            if(!stk.empty()){
                if(ch == stk.top()){
                    stk.pop();
                    continue;
                }
            }
            stk.push(ch);
        }
        string ans = "";
        while(!stk.empty()){
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};