class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> freq(51, 0);
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }
        if (n == k) {
            for (int i = 50; i >= 0; i--) {
                if (freq[i] >= 1)
                    return i;
            }
        } else if (k == 1) {
            for (int i = 50; i >= 0; i--) {
                if (freq[i] == 1)
                    return i;
            }
        }else{
            int fst = nums[0], lst = nums[n-1];
            if(fst > lst){
                if(freq[fst] == 1) return fst;
                else if(freq[lst] == 1)return lst;
                return -1;
            }else{
                if(freq[lst] == 1) return lst;
                else if(freq[fst] == 1)return fst;
                return -1;
            }
        }
        return -1;
    }
};