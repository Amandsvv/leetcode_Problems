class Solution {
public:
    int minAddToMakeValid(string s) {
        // )))(())))(()
        stack<char> stk;
        int ans = 0; // moves needed
        for(char& ch : s){
            if(ch == '('){
                stk.push(ch);
            }else{
                if(stk.empty()){
                    ans++;
                }else{
                    stk.pop();
                }
            }
        }
        return ans + stk.size();
    }
};