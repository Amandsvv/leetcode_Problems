class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // sort(costs.begin(), costs.end());
        // int cnt = 0;
        // for(auto & el : costs){
        //     if(coins-el < 0) break;
        //     coins-=el;
        //     cnt++;
        // }
        // return cnt;
        int freq[100001] = {0};
        for(auto & el : costs){
            freq[el]++;
        }

        int cnt = 0;
        int idx = 0;
        while(coins && idx <100001){
            if(coins < idx) break;
            if(freq[idx]){
                cnt++;
                coins -= idx;
                freq[idx]--;
            }else{
                idx++;
            }
        }
        return cnt;
    }
};