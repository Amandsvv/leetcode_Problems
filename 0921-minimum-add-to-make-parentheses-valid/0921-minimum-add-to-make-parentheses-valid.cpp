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
                    ans++; // open brackets needed to satisfy the string
                }else{
                    stk.pop();
                }
            }
        }
        return ans + stk.size(); //stk.size() will be the opening brackets which still needs to satisfied by closing one. 
    }
};