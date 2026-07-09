class Solution {
public:
    vector<vector<int>> dp = vector<vector<int>>(101, vector<int>(101, -1));
    int path(int m, int n){
        if(m < 0 || n < 0) return 0;
        if(m == 0 && n == 0) return dp[m][n] = 1;
        if(dp[m][n] != -1) return dp[m][n];
        return dp[m][n] = path(m, n-1) + path(m-1, n);
    }
    int uniquePaths(int m, int n) {
        return path(m-1, n-1);
    }
};