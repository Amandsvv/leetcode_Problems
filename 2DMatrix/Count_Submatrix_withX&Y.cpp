#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> sum(n, vector<int>(m,0)), countX(n, vector<int>(m,0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int val = 0;
                char ch = grid[i][j];

                if(ch == 'X') val = 1;
                else if(ch == 'Y') val = -1;

                sum[i][j] = val;
                countX[i][j] = (ch == 'X');

                if(i > 0){
                    sum[i][j] += sum[i-1][j];
                    countX[i][j] += countX[i-1][j];
                }
                if(j > 0){
                    sum[i][j] = sum[i][j-1] + sum[i][j];
                    countX[i][j] = countX[i][j-1] + countX[i][j];
                }
                if(i > 0 && j > 0){
                    sum[i][j] -= sum[i-1][j-1];
                    countX[i][j] -= countX[i-1][j-1];
                }
            }
        }

        int ans = 0;
        for(int i =0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(sum[i][j] == 0 && countX[i][j] > 0){
                    ans++;
                }
            }
        }

        return ans;
    }
};
int main (){

}