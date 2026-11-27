class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    ans = max(ans, rec(grid, vis, i, j));
                }
            }
        }
        return ans;
    }
    int rec(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i,
            int j) {
        if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size()) {
            return 0;
        } else {
            if (!vis[i][j] && grid[i][j] != 0) {
                vis[i][j] = true;
                int up = rec(grid, vis, i + 1, j);
                int down = rec(grid, vis, i - 1, j);
                int left = rec(grid, vis, i, j - 1);
                int right = rec(grid, vis, i, j + 1);

                int mxx = max({up, down, left, right});
                vis[i][j] = false;
                return mxx + grid[i][j];
            }
        }
        return 0;
    }
};