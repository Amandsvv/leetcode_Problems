class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxValueOfIdx(n);
        vector<int> minValueOfIdx(n);
        maxValueOfIdx[0] = nums[0];
        for (int i = 1; i < n; i++) {
            maxValueOfIdx[i] = max(maxValueOfIdx[i-1], nums[i]);
            
        }
        minValueOfIdx[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
           minValueOfIdx[i] = min(minValueOfIdx[i+1], nums[i]);
        }

        for (int i = 0; i < n; i++) {
            cout<<maxValueOfIdx[i]<<" "<< minValueOfIdx[i]<<endl;
            if (maxValueOfIdx[i] - minValueOfIdx[i] <= k)
                return i;
        }
        return -1;
    }
};