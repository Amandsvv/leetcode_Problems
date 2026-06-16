class Solution {
public:
    string processStr(string str) {
        string s = "";
        for(char ch : str){
            if(ch == '*'){
                if(!s.empty()){
                    s.pop_back();
                }
            }else if(ch == '#'){
                s+=s;
            }else if(ch == '%'){
                reverse(s.begin(), s.end());
            }else{
                s+=ch;
            }
        }
        return s;
    }
};