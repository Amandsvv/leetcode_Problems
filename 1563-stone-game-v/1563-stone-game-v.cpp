class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> pref(n + 1, 0);
        for(int i = 0; i < n; i++){
            pref[i+1] = stoneValue[i] + pref[i];
        }
        auto getSum = [&](int i, int j){
            return pref[j+1] - pref[i];
        };

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int len = 2; len <= n; len++){
            for(int i = 0; i <= n - len; i++){
                int j = i + len - 1;
                int maxScore = 0;

                for(int k = i; k < j; k++){
                    int left = getSum(i, k);
                    int right = getSum(k+1, j);
                    if(left < right){
                        maxScore = max(maxScore, left + dp[i][k]);
                    }else if(right < left){
                        maxScore = max(maxScore, right + dp[k+1][j]);
                    }else{
                        maxScore = max({maxScore, left + dp[i][k], right + dp[k+1][j]});
                    }
                }
                dp[i][j] = maxScore;
            }
        }
        return dp[0][n-1];
    }
};