#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool valid(int i, int j, vector<vector<char>>& grid){
        if(i < 0 || i > grid.size()-1 || j < 0 || j > grid[0].size()-1 || grid[i][j] != '1') return false;

        grid[i][j] = '0';

        valid(i+1, j, grid);
        valid(i-1, j, grid);
        valid(i, j+1, grid);
        valid(i, j-1, grid);

        return true;
    }
    int numIslands(vector<vector<char>>& grid) {
        int numberOfIslands = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(valid(i,j,grid)) numberOfIslands++;
            }
        }
        return numberOfIslands;
    }
};
int main (){

}