class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,int> nums1, nums2;
        int ans = -1, n = nums.size();
        for(int i = 0; i < n; i++){
            int val = nums[i];
            if(nums1.count(val) && nums2.count(val)){
                int x = abs(nums1[val] - nums2[val]) + abs(nums2[val] - i) + abs(nums1[val] - i);
                if(ans == -1){
                    ans = abs(x);
                }else ans = min(ans, abs(x));

                nums1[val] = nums2[val];
                nums2[val] = i;
            }else if(nums1.count(val)){
                nums2[val] = i;
            }else{
                nums1[val] = i;
            }
        }
        return ans;
    }
};