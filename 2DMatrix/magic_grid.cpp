#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int m, int n) {
        unordered_set<int> seen;
        vector<int> rowSum(3, 0), colSum(3, 0);
        int dia1 = 0, dia2 = 0;
        for (int i = m; i < m + 3; i++) {
            for (int j = n; j < n + 3; j++) {
                int val = grid[i][j];
                if (val < 1 || val > 9 || seen.find(val) != seen.end())
                    return false;
                seen.insert(val);

                rowSum[i - m] += grid[i][j];
                colSum[j - n] += grid[i][j];

                if (i - m == j - n)
                    dia1 += val;
                if (i - m + j - n == 2)
                    dia2 += val;
            }
        }

        int target = rowSum[0];

        for (int i = 0; i < 3; i++) {
            if (rowSum[i] != target || colSum[i] != target)
                return false;
        }

        return dia1 == target && dia2 == target;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), count = 0;
        for (int i = 0; i <= m - 3; i++) {
            for (int j = 0; j <= n - 3; j++) {
                if (isValid(grid, i, j))
                    count++;
            }
        }
        return count;
    }
};
int main (){

}