class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(int & el : nums){
            string s = to_string(el);
            int sum = 0;
            for(char & ch : s){
                sum += (ch - '0');
            }
            ans = min(ans, sum);
        }
        return ans;
    }
};