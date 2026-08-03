class Solution {
public:
// We know that:

// The number of piles is always even.
// Alice always plays first.
// The total number of stones is odd, so a tie is impossible.
// On every turn, a player can only take a pile from the beginning or the end.
// Now divide the piles based on their original indices:

// Even indexed piles: 0, 2, 4, ...
// Odd indexed piles: 1, 3, 5, ...
// Because the number of piles is even, Alice can force herself to take either all the even-indexed piles or all the odd-indexed piles.

// She can decide which group she wants based on her first move.

// Since the total number of stones is odd:

// sum(even indexed piles) != sum(odd indexed piles)

// Therefore, one of these two groups must have a larger sum.

// Alice can choose the group with the larger sum and force herself to keep taking piles belonging to that group.

// Hence, Alice is always guaranteed to win.

// So the entire solution can simply be:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = 0;i < n; i++){
            dp[i][i] = piles[i];
        }

        for(int len = 2; len <= n; len++){
            for(int i = 0; i + len - 1 < n; i++){
                int j = i + len - 1;
                int takeLeft = piles[i] - dp[i+1][j];
                int takeRight = piles[j] - dp[i][j-1];

                dp[i][j] = max(takeLeft, takeRight);
            }
        }

        return dp[0][n-1] > 0;
    }
};