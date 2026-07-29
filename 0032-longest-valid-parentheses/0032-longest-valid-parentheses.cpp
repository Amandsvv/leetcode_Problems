class Solution {
public:
    int longestValidParentheses(string s) {
        int lon = 0;
        stack<int> par;
        par.push(-1);

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                par.push(i);
            }else{
                par.pop();
                if(par.empty()){
                    par.push(i);
                }else{
                    int len = i - par.top();
                    lon = max(lon, len);
                }
            }
        }

        return lon;
    }
};