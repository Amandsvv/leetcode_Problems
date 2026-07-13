class Solution {
public:
    int rec(int i, int j, string& text1, string& text2, vector<vector<int>>& dp){
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int equals = 0, notequals = 0;
        if(text1[i] == text2[j]){
                equals = 1 + rec(i-1, j-1, text1, text2, dp); 
        }else{
            notequals = max(rec(i-1, j, text1, text2, dp), rec(i, j-1, text1, text2, dp));
        }
        return dp[i][j] = max(equals, notequals);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        // return rec(n-1, m-1, text1, text2, dp);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(text1[i] == text2[j]){
                    if(i > 0 && j > 0){
                        dp[i][j] = dp[i-1][j-1] + 1;
                        continue;
                    }
                    dp[i][j] = dp[i][j] + 1;
                }else{
                    int left = 0, up = 0;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                    dp[i][j] = max(up, left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};