class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> layers;
        int m = grid.size(), n = grid[0].size();
        int sRow = 0, sCol = 0, eRow = m - 1, eCol = n - 1;

        while (sRow <= eRow && sCol <= eCol) {
            vector<int> vec;
            // Move Top
            for (int j = sCol; j <= eCol; j++) {
                vec.push_back(grid[sRow][j]);
            }
            // Move Right
            for (int i = sRow + 1; i <= eRow; i++) {
                vec.push_back(grid[i][eCol]);
            }

            // Move Bottom
            for (int j = eCol - 1; j >= sCol; j--) {
                if (sRow == eRow)
                    break;
                vec.push_back(grid[eRow][j]);
            }
            // Move Left
            for (int i = eRow - 1; i > sRow; i--) {
                if (sCol == eCol)
                    break;
                vec.push_back(grid[i][sCol]);
            }
            sRow++;
            sCol++;
            eRow--;
            eCol--;
            layers.push_back(vec);
        }

        sRow = 0, sCol = 0, eRow = m - 1, eCol = n - 1;

        for (auto& vec : layers) {
            int a = k % vec.size();
            rotate(vec.begin(), vec.begin() + a, vec.end());
            int l = 0;
            for (int j = sCol; j <= eCol; j++) {
                grid[sRow][j] = vec[l];
                l++;
            }
            // Move Right
            for (int i = sRow + 1; i <= eRow; i++) {
                grid[i][eCol] = vec[l];
                l++;
            }

            // Move Bottom
            for (int j = eCol - 1; j >= sCol; j--) {
                if (sRow == eRow)
                    break;
                grid[eRow][j] = vec[l]; l++;
            }
            // Move Left
            for (int i = eRow - 1; i > sRow; i--) {
                if (sCol == eCol)
                    break;
                grid[i][sCol] = vec[l]; l++;
            }
            sRow++;
            sCol++;
            eRow--;
            eCol--;
        }
        return grid;
    }
};