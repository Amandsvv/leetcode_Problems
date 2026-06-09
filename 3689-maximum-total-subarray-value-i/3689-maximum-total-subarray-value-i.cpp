class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxEl = 0, minEl = INT_MAX;
        for(int el : nums){
            maxEl = max(maxEl, el);
            minEl = min(minEl, el);
        }
        return (long long)(maxEl - minEl) * k;
    }
};