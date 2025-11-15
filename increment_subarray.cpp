#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n, vector<int>(n,0));
        for(vector<int> query : queries){
            for(int i = query[0]; i <= query[2]; i++){
                for(int j = query[1] ; j <= query[3]; j++){
                    mat[i][j]++;
                }
            }
        }
        return mat;
    }
};
int main (){

}