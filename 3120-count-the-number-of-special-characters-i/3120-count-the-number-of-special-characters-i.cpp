class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> seen;
        for(char & ch : word){
            seen.insert(ch);
        }
        int ans = 0;
        for(char ch : seen){
            if(ch >= 'a' && ch <= 'z' && seen.count(ch - 32)){
                ans ++;
            }
       }
       return ans;
    }
};