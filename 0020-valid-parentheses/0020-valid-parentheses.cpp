class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char& ch : s){
            if(ch == '(' || ch == '[' || ch == '{') stk.push(ch);
            else{
                if(stk.empty()) return false;
                char c = stk.top();
                if(ch == ')' && c != '(') return false;
                else if (ch == ']' && c != '[') return false;
                else if(ch == '}' && c != '{') return false;
                stk.pop();
            }
        }

        return stk.empty();
    }
};