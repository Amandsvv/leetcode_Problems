class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row =  grid.size(), col = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        dp[0][0] = grid[0][0];
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                int left = INT_MAX, up = INT_MAX;
                if(i == 0 && j == 0) continue;
                if(i > 0){
                    up = dp[i-1][j] + grid[i][j];
                }
                if(j > 0){
                    left = dp[i][j-1] + grid[i][j];
                }
                dp[i][j] = min(up, left);
            }
        }
        return dp[row-1][col-1];
    }
};