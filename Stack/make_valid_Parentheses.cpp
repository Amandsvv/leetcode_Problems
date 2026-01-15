#include<iostream>
#include<vector>
#include<stack>

using namespace std;
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        for(char ch : s){
            if(ch == '('){
                stk.push(ch);
            }else{
                if(!stk.empty() && stk.top() != ')') stk.pop();
                else stk.push(ch);
            }
        }
        return stk.size();
    }
};
int main (){
    Solution obj;
    string s = "(())))";
    cout<<"Minimum insertion required : "<<obj.minAddToMakeValid(s)<<endl;
    return 0;
}