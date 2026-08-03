class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n+1, 0);
        dp[n] = 0;

        for(int i = n-1;i >= 0; i--){
            int stones = 0;
            int mxStone = INT_MIN;
            for(int k = 1; k <= 3; k++){
                if(i+k > n)  break;
                stones += stoneValue[i+k-1];
                mxStone = max(stones - dp[i+k], mxStone);
            }
            dp[i] = mxStone;
        }
        if(dp[0] == 0) return "Tie";
        else if(dp[0] < 0) return "Bob";
        return "Alice";

    }
};