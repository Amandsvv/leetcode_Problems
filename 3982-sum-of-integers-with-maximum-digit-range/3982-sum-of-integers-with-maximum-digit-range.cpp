class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();
        vector<int>sums(n, 0);
        int i = 0;
        int max_sum = INT_MIN;
        for(auto num : nums){
            int mn = INT_MAX;
            int mx = INT_MIN;
            int x = num;
            while(x){
                int dig = x%10;
                mn = min(dig, mn);
                mx = max(dig, mx);
                x/=10;
            }
            sums[i] = mx - mn;
            max_sum = max(max_sum, sums[i]);
            i++;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(sums[i] == max_sum){
                ans+=nums[i];
            }
        }
        return ans;
    }
};