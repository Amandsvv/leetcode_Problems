class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;
        for(char ch : s){
            if(ch == '*') len = max(0LL, len - 1);
            else if(ch == '#') len = (len * 2);
            else if(ch == '%') continue;
            else len++;
        }

        if(k >= len) return '.';

        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == '*') len++;
            else if(s[i] == '#'){
                long long half = len/2;
                if(k >= half){
                    k-=half;
                }
                len = half;
            }
            else if(s[i] == '%'){
                k = len - k - 1;
            }else{
                if( k == len - 1){
                    return s[i];
                }
                len --;
            }
        }
        return '.';
    }
};