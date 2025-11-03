#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        //Get Transpose of matrix
        for(int i = 0; i <n; i++){
            for(int j = 0; j < n; j++){
                if(i != j && i < j){
                    int temp = mat[i][j];
                    mat[i][j] = mat[j][i];
                    mat[j][i] = temp;
                }
            }
        }

        //Now reverse the transposed maatrix
        
    }
};
int main (){
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    auto obj = Solution();
    obj.rotate(mat);
    for(auto vec : mat){
        for(int el : vec){
            cout<<el<<" ";
        }
        cout<<endl;
    }
}