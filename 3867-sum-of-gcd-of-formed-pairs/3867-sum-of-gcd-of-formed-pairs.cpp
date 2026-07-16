class Solution {
public:
    int gcd(int a , int b){
        if(b == 0) return a;
        return gcd(b, a%b);
    }
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd;
        int mx = nums[0];
        for(int i = 0; i < nums.size(); i++){
            mx = max(nums[i], mx);
            prefixGcd.push_back(gcd(nums[i], mx));
        }
        sort(prefixGcd.begin(), prefixGcd.end());

        int i = 0, j = prefixGcd.size() - 1;
        long long ans = 0;

        while(i < j){
            ans += gcd(prefixGcd[i++], prefixGcd[j--]);
        }
        return ans;
    }
};