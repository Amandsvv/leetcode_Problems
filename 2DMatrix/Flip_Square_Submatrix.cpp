#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int idx = x + k -1;

        while(x < idx){
            for(int j = y; j < y + k; j++){
                swap(grid[x][j], grid[idx][j]);
            }
            x++; idx--;
        }
        return grid;
    }
};
int main (){

}