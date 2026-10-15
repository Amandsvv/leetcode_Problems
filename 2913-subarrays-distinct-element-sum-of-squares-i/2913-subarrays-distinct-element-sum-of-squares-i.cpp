class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sz = nums.size();
        int finalAns = 0;
        for(int i = 0; i < sz; i++){
            bool seen[101] = {false};
            int cnt = 0;
            for(int j = i; j < sz; j++){
                int num = nums[j];
                if(!seen[num]){
                    cnt++;
                    seen[num] = true;
                }
                finalAns += (cnt * cnt);
            }
        }
        return finalAns;
    }
};