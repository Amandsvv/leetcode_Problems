class Solution {
public:
    int memo[1001][1501] = {-1};
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        // int factor[1501] = {};

        // for(auto & it: items){
        //     int fac = it[0];
        //     for(int f = 1; f <= 1500; f++){
        //         if(fac % f == 0) factor[f]++;
        //     }
        // }

        // vector<int> dp(budget+1, 0);
        // for(auto & it : items){
        //     int f = it[0], p = it[1];
        //     vector<int> ndp = dp;
        //     // update the ndp by taking this current one
        //     for(int b = budget; b >= p; --b){
        //         ndp[b] = max(ndp[b], dp[b - p] + factor[f]);
        //     }
        //     for(int b = p; b <= budget; b++){
        //         ndp[b] = max(ndp[b], ndp[b - p] + 1);
        //     }
        //     dp = move(ndp);
        // }
        // return *max_element(dp.begin(), dp.end());
        int n = items.size();

        vector<int> factor(n, 0);
        int cheapest = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cheapest = min(cheapest, items[i][1]);
                if (i != j && items[j][0] % items[i][0] == 0)
                    factor[i]++;
            }
        }
        memset(memo, -1, sizeof(memo));
        return solve(items, factor, n - 1, budget, cheapest);
    }
    int solve(vector<vector<int>>& items, vector<int>& factor, int n,
              int budget, int c) {
        if (n < 0) {
            return budget / c;
        }
        if(memo[n][budget] != -1){
            return memo[n][budget];
        }
        int take = 0, leave = 0, price = items[n][1];
        if (price <= budget)
            take =
                solve(items, factor, n - 1, budget - price, c) + factor[n] + 1;
        leave = solve(items, factor, n - 1 , budget, c);

        return memo[n][budget] = max(take, leave);
    }
};