class Solution {
public:
    bool canForm(int i, int j, vector<vector<char>>& board, string word, int idx){
        if(idx == word.size()-1) return true;

        bool found = false;
        char temp = board[i][j];
        board[i][j] = '#';

        if(i > 0 && board[i-1][j] == word[idx+1]){
            found = canForm(i-1, j, board, word, idx+1);
        }

        if(!found && i < board.size() - 1 && board[i+1][j] == word[idx+1]){
            found = canForm(i+1, j, board, word, idx+1);
        }

        if(!found && j > 0 && board[i][j-1] == word[idx+1]){
            found = canForm(i, j-1, board, word, idx+1);
        }

        if(!found && j < board[0].size() - 1 && board[i][j+1] == word[idx+1]){
            found = canForm(i, j+1, board, word, idx+1);
        }

        board[i][j] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char ch = board[i][j];
                if (ch == word[0]) {
                    bool exist = canForm(i, j, board, word, 0);
                    if(exist) return true;
                }
            }
        }
        return false;
    }
};