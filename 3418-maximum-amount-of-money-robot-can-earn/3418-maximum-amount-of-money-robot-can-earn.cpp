class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        int dp[m][n][3];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < 3; k++){
                    dp[i][j][k] = -1e9;
                }
            }
        }
        dp[0][0][0] = coins[0][0];
        if(coins[0][0] < 0){
            dp[0][0][1] = 0;
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < 3; k++){
                    int prevM = -1e9;
                    if(i > 0) prevM = max(prevM, dp[i-1][j][k]);
                    if(j > 0) prevM = max(prevM, dp[i][j-1][k]);
                    if(prevM != -1e9){
                        dp[i][j][k] = max(dp[i][j][k], prevM + coins[i][j]);

                        if(k < 2 && coins[i][j] < 0){
                            dp[i][j][k+1] = max(dp[i][j][k+1], prevM);
                        }
                    }
                }
            }
        }
        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};