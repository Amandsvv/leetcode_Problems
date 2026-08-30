class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 1) return 1;
        int minIdx = 0, maxIdx = 0;

        for(int i = 0; i < sz; i++){
            if(nums[i] < nums[minIdx]){
                minIdx = i;
            }
            if(nums[i] > nums[maxIdx]){
                maxIdx = i;
            }
        }

        int dltfrontMIN = minIdx + 1;
        int dltfrontMAX = maxIdx + 1;
        int dltbackMIN = sz - minIdx;
        int dltbackMAX = sz - maxIdx;

        return min({max(dltfrontMIN , dltfrontMAX), dltfrontMIN + dltbackMAX,  dltfrontMAX + dltbackMIN,max(dltbackMAX, dltbackMIN)});
    }
};