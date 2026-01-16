#include <iostream>
#include<vector>


using namespace std;

class Solution {
public:
    bool rot(int i, int j, vector<vector<int>>& grid){
        bool flag = false;
        if(i+1 < grid.size()){
            if(grid[i+1][j] == 1) {
                grid[i+1][j] = 2;
                flag = true;
            }
        }
        if(j+1 < grid[0].size()){
            if(grid[i][j+1] == 1){
                grid[i][j+1] = 2;
                flag = true;
            }
        }
        if(i-1 >= 0){
            if(grid[i-1][j] == 1) {
                grid[i-1][j] = 2;
                flag = true;
            }
        }
        if(j-1 >= 0){
            if(grid[i][j-1] == 1){
                grid[i][j-1] = 2;
                flag = true;
            }
        }
        return flag;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = 0 ,m = grid.size(), n = grid[0].size();
        
        while(true){
            vector<pair<int,int>> rotten;
            bool changed = false;
            int fresh = 0;

            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(grid[i][j] == 2) rotten.push_back({i,j});
                    else if(grid[i][j] == 1) fresh++;
                }
            }

            if(fresh == 0) return minutes;

            for(pair<int,int> pair : rotten){
                if(rot(pair.first,pair.second,grid)) changed = true;
            }

            if(!changed) return -1;
            minutes++;
        }
        return minutes;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> grid = {{2,1,0},{1,1,0},{0,1,1}};
    cout<<obj.orangesRotting(grid)<<endl;
    
    return 0;
}