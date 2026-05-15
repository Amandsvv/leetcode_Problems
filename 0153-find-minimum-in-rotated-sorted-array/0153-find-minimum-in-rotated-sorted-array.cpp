class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 1, j = nums.size()-2;

        while(i<=j){
            int mid = i + (j-i)/2;

            if(nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1]){
                return nums[mid];
            }else if(nums[i] <= nums[mid] && nums[j] <= nums[mid]){
                i = mid+1;
            }else{
                j = mid-1;
            }
        }
        return min(nums[0],nums[nums.size()-1]);
    }
};