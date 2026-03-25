#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<long long> horizontalPrefixSum(m, 0);
        vector<long long> verticalPrefixSum(n, 0);
        long long sum = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                sum += grid[i][j];
            }
            horizontalPrefixSum[i] = sum;
        }
        sum = 0;
        for(int j = 0; j < n; j++){
            for(int i = 0; i < m; i++){
                sum += grid[i][j];
            }
            verticalPrefixSum[j] = sum;
        }

        for(int i = 0; i < m; i++){
            if(horizontalPrefixSum[i] == horizontalPrefixSum[m-1] - horizontalPrefixSum[i]) return true;
        }

        for(int j = 0; j < n; j++){
            if(verticalPrefixSum[j] == verticalPrefixSum[n-1] - verticalPrefixSum[j]) return true;
        }
        return false;
    }
};
int main (){

}