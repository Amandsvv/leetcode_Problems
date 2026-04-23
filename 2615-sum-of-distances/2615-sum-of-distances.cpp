class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<long long>> pos;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }

        vector<long long> ans(n, 0);

        for(auto& [v, vec] : pos){
            vector<long long> origin = vec; 
            long long val = 0;
            
            for(auto& el : vec){
                val += el;
                el = val;
            }

            int k = origin.size();
            for(int i = 0; i < k; i++) {
                long long cur_idx = origin[i];
                
                long long left_sum = (i > 0) ? vec[i-1] : 0;
                long long left_dist = (1LL * i * cur_idx) - left_sum;
                
                long long total_sum = vec[k-1];
                long long right_sum = total_sum - vec[i];
                long long right_dist = right_sum - (1LL * (k - 1 - i) * cur_idx);
                
                ans[cur_idx] = left_dist + right_dist;
            }
        }
        
        return ans;
    }
};