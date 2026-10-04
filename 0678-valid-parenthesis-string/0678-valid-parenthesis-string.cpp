class Solution {
public:
    bool checkValidString(string s) {
        int sz = s.size();
        // if(s[0] == ')' || s[sz-1] == '(') return false;
        // if(s == "(*)") return true;
        // stack<char> stk;

        // for(char ch : s){
        //     if(ch == '('){
        //         stk.push(ch);
        //     }else if( ch == ')'){
        //         if(stk.empty()){
        //             return false;
        //         }
        //         char temp = stk.top();
        //         if(temp == '(' || temp == '*'){
        //             stk.pop();
        //         }
        //     }else{
        //         if(stk.empty()){
        //             stk.push(ch);
        //         }else{
        //             char temp = stk.top();
        //             if(temp == '*'){
        //                 stk.pop();
        //             }else{
        //                 stk.push(ch);
        //             }
        //         }
        //     }
        // }

        // while(!stk.empty()){
        //     char temp = stk.top();
        //     if(temp == '('){
        //         return false;
        //     }
        //     stk.pop();
        // }

        // return stk.empty();

        int openBr = 0, closeBr = 0, star = 0;
        for(int i = 0; i < sz; i++){
            char ch = s[i];
            if(ch == '(') openBr++;
            if(ch == '*') star++;
            if(ch == ')'){
                if(openBr > 0){
                    openBr--;
                }else if(star > 0){
                    star--;
                } else{
                    return false;
                }
            }
        }

        closeBr = 0, star = 0;
        for(int i = sz-1; i >= 0; i--){
            char ch = s[i];
            if(ch == ')') closeBr++;
            if(ch == '*') star++;
            if(ch == '('){
                if(closeBr > 0){
                    closeBr--;
                }else if(star > 0){
                    star--;
                } else{
                    return false;
                }
            }
        }

        return true;

        //Pass 1
        // int balance = 0;
        // for(char ch : s){
        //     if(ch == '(' || ch == '*') balance++;
        //     else balance--;

        //     if(balance < 0) return false;
        // }

        // balance = 0;
        // for(int i = sz-1; i >= 0; i--){
        //     if(s[i] == ')' || s[i] == '*') balance++;
        //     else balance--;

        //     if(balance < 0) return false;
        // }

        // return true;
    }
};