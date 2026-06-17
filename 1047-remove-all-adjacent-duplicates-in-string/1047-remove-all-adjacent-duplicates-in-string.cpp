class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";

        for(char ch : s){
            int n = ans.size();
            if(n > 0){
                if(ch == ans[n-1]) {
                    ans.pop_back();
                    continue;
                }
            }
            ans.push_back(ch);
        }

        return ans;
    }
};