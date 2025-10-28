#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans;
        int sRow = 0, eRow = m-1, sCol = 0, eCol = n-1;

        while(sRow <= eRow && sCol <= eCol){
            //top
            for(int j = sCol; j <= eCol; j++){
                ans.push_back(mat[sRow][j]);
            }
            //Right
            for(int i = sRow +1; i <= eRow; i++){
                ans.push_back(mat[i][eCol]);
            }

            //Bottom
            for(int j = eCol -1; j >= sCol; j--){
                if(sRow == eRow){
                    break;
                }
                ans.push_back(mat[eRow][j]);
            }

            //left
            for(int i = eRow-1; i>= sRow+1; i--){
                if(sCol == eCol){
                    break;
                }
                ans.push_back(mat[i][sCol]);
            }
            sRow++; eRow--; sCol++; eCol--;
        }
        return ans;
    }
};
int main (){
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    auto obj = new Solution();
    vector<int> ans = obj->spiralOrder(matrix);

    for(int el : ans){
        cout<<el<<" ";
    }
    cout<<endl;
    return 0;
}