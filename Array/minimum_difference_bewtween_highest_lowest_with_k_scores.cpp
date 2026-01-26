#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int i = 0, j = k -1;
        int minDiff = INT32_MAX;

        while(j < nums.size()){
            minDiff = min(minDiff, nums[j] - nums[i]);
            i++;j++;
        }
        return minDiff;
    }
};
int main (){

}