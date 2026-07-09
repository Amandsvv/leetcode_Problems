class Solution {
public:
    // int path(int m, int n) {
    //     if (m < 0 || n < 0)
    //         return 0;
    //     if (m == 0 && n == 0)
    //         return dp[m][n] = 1;
    //     if (dp[m][n] != -1)
    //         return dp[m][n];
    //     return dp[m][n] = path(m, n - 1) + path(m - 1, n);
    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,
                               vector<int>(n, 1)); // Fill first row/col with 1

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};