class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int curr = 0;
        for(auto & el : gain){
            curr+=el;
            ans = max(ans, curr);
        }
        return ans;
    }
};