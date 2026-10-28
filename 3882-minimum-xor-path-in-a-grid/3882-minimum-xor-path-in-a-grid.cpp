class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<unordered_set<int>>> dp(m, vector<unordered_set<int>>(n));

        dp[0][0].insert(grid[0][0]);


        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(dp[i][j].empty()) continue;
                if(j+1 < n){
                    for(int val: dp[i][j]){
                        dp[i][j+1].insert(val ^ grid[i][j+1]);
                    }
                }
                if(i+1 < m){
                    for(int val: dp[i][j]){
                        dp[i+1][j].insert(val ^ grid[i+1][j]);
                    }
                }

            }
        }
        int ans = INT_MAX;
        for(int el: dp[m-1][n-1]){
            ans = min(ans, el);
        }

        return ans;
    }

    // void helper(vector<vector<int>>& grid, int i, int j, int m, int n, int cost, vector<vector<unordered_set<int>>>& memo) {
    //     if(i > 0 || j > 0){
    //         if(memo[i][j].count(cost)) return;
    //     }
    //     memo[i][j].insert(cost);

    //     if (i == m - 1 && j == n - 1) {
    //         return;
    //     }

    //     if(i < m-1) helper(grid, i + 1, j, m, n, cost ^ grid[i+1][j], memo);
    //     if(j < n-1) helper(grid, i, j+1, m, n, cost ^ grid[i][j+1], memo);
    // }
};