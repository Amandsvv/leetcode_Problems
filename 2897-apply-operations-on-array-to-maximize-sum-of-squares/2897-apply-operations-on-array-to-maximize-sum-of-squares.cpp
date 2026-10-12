class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        // t.c = O(n) , O(n.logn)

        // we need to optimally select i,j which can result higher numbers
        // when we need to stop applying further operations
        // sort nums
        //select top k lement -> square it -> add to sum(%MOD)
        //2 -> 8 (diff - 6) 10(2) , 1000(8) -> 10

        int cnt[31] = {0};
        for(int & el : nums){
            int x = el;
            int idx = 30;
            vector<int> temp;
            while(x){
                temp.push_back(x%2);
                x/=2;
            }
            for(int i = temp.size()-1; i >= 0; i--){
                cnt[i] += temp[i];
            }
        }
        long long ans = 0;
        int MOD = 1e9+7;
        for(int i = 0; i < k; i++){
            long long x = 0;
            for(int j = 0; j < 31; j++){
                if(cnt[j] > 0){
                    x |= (1 << j);
                    cnt[j]--;
                }
            }
            ans = (ans + ((x*x) % MOD)) % MOD;
        }

        return (int)ans;
    }
};