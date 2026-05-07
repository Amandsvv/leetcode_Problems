class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<char>> box (n, vector<char>(m));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                box[j][m-1-i] = grid[i][j]; 
            }
        }
        for(int j = 0; j < m; j++){
            int empty = n-1;
            for(int i = n-1; i >= 0; i--){
                if(box[i][j] == '*'){
                    empty = i-1;
                }
                else if(box[i][j] == '#'){
                    if(i != empty){
                        box[empty][j] = '#';
                        box[i][j] = '.';
                    }
                    empty--;
                }
            }
        }
        return box;
    }
};