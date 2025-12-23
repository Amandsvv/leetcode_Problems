#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        vector<vector<int>> ans;
        for(int j = 0; j < mat[0].size(); j++){
            vector<int> rowData = {};
            for(int i = 0; i< mat.size(); i++){
                rowData.push_back(mat[i][j]);
            }
            ans.push_back(rowData);
        }
        return ans;
    }
};
int main (){

}