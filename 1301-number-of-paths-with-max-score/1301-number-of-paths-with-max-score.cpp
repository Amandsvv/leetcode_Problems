#include <vector>
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        long long MOD = 1e9 + 7;
        
        // dp[i][j] = {max_score, count}
        // Initialize with -1 for score (unreachable) and 0 for count
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, 0}));

        // Base Case: Start at 'S' (bottom-right)
        // Score is 0 (S contributes 0), Count is 1
        dp[n-1][n-1] = {0, 1};

        // Iterate from bottom-right to top-left
        // i goes from n-1 down to 0
        // j goes from n-1 down to 0
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                
                // Skip the start cell as it's already set
                if (i == n - 1 && j == n - 1) continue;
                
                // If obstacle, it's unreachable
                if (board[i][j] == 'X') {
                    dp[i][j] = {0, 0}; 
                    continue;
                }

                // Possible previous cells (where we came FROM)
                // Moves allowed: Up, Left, Up-Left
                // So to reach (i, j), we came from:
                // 1. (i+1, j) -> Down relative to current (Up move)
                // 2. (i, j+1) -> Right relative to current (Left move)
                // 3. (i+1, j+1) -> Diagonal (Up-Left move)
                
                int max_prev = -1;
                long long count = 0;
                
                // Check Down (i+1, j)
                if (i + 1 < n && dp[i+1][j].second > 0) {
                    if (dp[i+1][j].first > max_prev) {
                        max_prev = dp[i+1][j].first;
                        count = dp[i+1][j].second;
                    } else if (dp[i+1][j].first == max_prev) {
                        count = (count + dp[i+1][j].second) % MOD;
                    }
                }
                
                // Check Right (i, j+1)
                if (j + 1 < n && dp[i][j+1].second > 0) {
                    if (dp[i][j+1].first > max_prev) {
                        max_prev = dp[i][j+1].first;
                        count = dp[i][j+1].second;
                    } else if (dp[i][j+1].first == max_prev) {
                        count = (count + dp[i][j+1].second) % MOD;
                    }
                }
                
                // Check Diagonal (i+1, j+1)
                if (i + 1 < n && j + 1 < n && dp[i+1][j+1].second > 0) {
                    if (dp[i+1][j+1].first > max_prev) {
                        max_prev = dp[i+1][j+1].first;
                        count = dp[i+1][j+1].second;
                    } else if (dp[i+1][j+1].first == max_prev) {
                        count = (count + dp[i+1][j+1].second) % MOD;
                    }
                }

                // If no path found to this cell
                if (max_prev == -1) {
                    dp[i][j] = {0, 0};
                    continue;
                }

                // Add current cell value
                int current_val = 0;
                if (board[i][j] != 'E') {
                    current_val = board[i][j] - '0';
                }

                dp[i][j] = {max_prev + current_val, (int)count};
            }
        }

        // Result is at Top-Left (0, 0)
        if (dp[0][0].second == 0) return {0, 0};
        return {dp[0][0].first, dp[0][0].second};
    }
};