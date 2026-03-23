#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<long long>> maxP(m, vector<long long>(n, 0)),
            minP(m, vector<long long>(n, 0));

        maxP[0][0] = minP[0][0] = grid[0][0];

        // first column
        for (int i = 1; i < m; i++) {
            maxP[i][0] = minP[i][0] = maxP[i - 1][0] * grid[i][0];
        }
        // First Row
        for (int j = 1; j < n; j++) {
            maxP[0][j] = minP[0][j] = maxP[0][j-1] * grid[0][j];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                long long x = grid[i][j];

                long long a = maxP[i - 1][j] * x;
                long long b = minP[i - 1][j] * x;
                long long c = maxP[i][j - 1] * x;
                long long d = minP[i][j - 1] * x;

                maxP[i][j] = max({a,b,c,d});
                minP[i][j] = min({a,b,c,d});
            }
        }
        long long ans = maxP[m-1][n-1];
        if(ans < 0) return -1;
        long long MOD = 1e9+7;
        return ans % MOD;
    }
};

int main (){

}