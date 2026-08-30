class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0;
        for(char ch : t){
            if(ch == s[idx]) idx++;
        }
        return idx == s.size();
    }
};