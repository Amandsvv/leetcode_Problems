class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int ans = 0, i = 0, n = cost.size();
        while(i + 2 < n){
            ans += cost[i];
            ans += cost[i + 1];
            i+=3;
        }
        int rem = n - i;
        if(rem == 2){
            ans += cost[i];
            ans += cost[i+1];
        }else if(rem == 1){
            ans += cost[i];
        }
        return ans;
    }
};