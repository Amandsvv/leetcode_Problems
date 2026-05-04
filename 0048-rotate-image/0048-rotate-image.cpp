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
        for(int i = 0; i<n; i++){
            reverse(mat[i].begin(),mat[i].end());
        }
    }
};