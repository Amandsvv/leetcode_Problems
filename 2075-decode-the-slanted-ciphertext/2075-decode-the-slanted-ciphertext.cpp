class Solution {
public:
    string decodeCiphertext(string en, int rows) {
        if (rows == 1 || en == "")
            return en;
        int column = en.size() / rows;
        vector<vector<char>> mat(rows, vector<char>(column, ' '));
        int k = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < column; j++) {
                mat[i][j] = en[k++];
            }
        }
        string ans = "";
        for(int j = 0; j < column; j++){
            for(int i = 0, k = j; i < rows && k < column; k++, i++){
                ans += mat[i][k];
            }
        }

        int n = ans.size()-1; 
        while(ans[n] == ' ') {ans.pop_back(); n--;};
    
        return ans;
    }
};