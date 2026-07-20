class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int c = m * n;
        k = k%c;

        if(!k) return grid;
        vector<vector<int>> ans(m, vector<int>(n));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // index in 1D array (before rotation)
                int oldIndex = i * n + j;

                // index in 1D array (after rotation)
                int newIndex = (oldIndex + k) % c;

                // changing from 1d back to 2D
                int newRow = newIndex / n;
                int newCol = newIndex % n;

                ans[newRow][newCol] = grid[i][j];
            }
        }
        return ans;
    }
};