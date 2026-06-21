class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int cnt = 0;
        for(auto & el : costs){
            if(coins-el < 0) break;
            coins-=el;
            cnt++;
        }
        return cnt;
    }
};