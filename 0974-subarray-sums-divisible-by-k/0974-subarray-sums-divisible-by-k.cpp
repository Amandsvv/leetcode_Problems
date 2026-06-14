class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt = 0, pre = 0;
        unordered_map<int, int> seen;
        seen[0] = 1;

        for(int & el : nums){
            pre += el;
            int rem = ((pre % k) + k) % k;
            if(seen.find(rem) != seen.end()) cnt+=seen[rem];
            seen[rem]++;
        }
        return cnt;
    }
};