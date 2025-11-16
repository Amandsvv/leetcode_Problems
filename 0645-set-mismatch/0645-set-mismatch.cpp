class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1,0);

        for(int el : nums){
            freq[el]++;
        }
        int dup = 0, miss = 0;

        for(int i = 1; i <= n; i++){
            if(freq[i] == 0) miss = i;
            if(freq[i] > 1) dup = i;
        }

        return {dup, miss};
    }
};