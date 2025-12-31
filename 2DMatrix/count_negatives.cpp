#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) { 
        int count = 0; 

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] < 0) count++;
            }
        }
        return count;
    }
};
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0, m = grid.size(), n = grid[0].size();

        int i = m-1, j = 0;
        while(i >= 0 && j < n){
            int val = grid[i][j];
            if(val < 0){
                count+= n-j;
                i--;
            }else{
                j++;
            }
        }  
        return count; 
    }
};
int main (){

}