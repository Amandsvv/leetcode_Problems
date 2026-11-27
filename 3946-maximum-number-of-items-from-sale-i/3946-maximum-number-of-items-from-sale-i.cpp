class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int factor[1501] = {};

        for(auto & it: items){
            int fac = it[0];
            for(int f = 1; f <= 1500; f++){
                if(fac % f == 0) factor[f]++;
            }
        }

        vector<int> dp(budget+1, 0);
        for(auto & it : items){
            int f = it[0], p = it[1];
            vector<int> ndp = dp;
            // update the ndp by taking this current one
            for(int b = budget; b >= p; --b){
                ndp[b] = max(ndp[b], dp[b - p] + factor[f]);
            }
            for(int b = p; b <= budget; b++){
                ndp[b] = max(ndp[b], ndp[b - p] + 1);
            }
            dp = move(ndp);
        }
        return *max_element(dp.begin(), dp.end());
    }
};