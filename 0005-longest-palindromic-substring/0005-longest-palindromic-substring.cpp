class Solution {
public:
void expand(string s, int left, int r, int& st, int& mL){
    while(left >= 0 && r < s.size() && s[left] == s[r]){
        int curr = r - left + 1;
        if(curr > mL){
            mL = curr;
            st = left;
        }
        left--;
        r++;
    }
}
    string longestPalindrome(string s) {
        int n = s.size();
        int st = 0, mL= 0;
        for(int i = 0; i < n; i++){
            expand(s,i,i,st,mL);
            expand(s,i,i+1,st,mL);
        }
        return s.substr(st, mL);
    }
};