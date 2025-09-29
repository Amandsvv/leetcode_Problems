#include<iostream>
#include<vector>

using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    int maxN = nums[0], idx = 0;
    int maxN2 = INT16_MIN;
    int i = 1;

    if (k == 1)
        return nums;

    while (i < k)
    {
        if (nums[i] > maxN && nums[i] > maxN2)
        {
            maxN2 = maxN;
            maxN = nums[i];
            idx = i;
        }
        else if (nums[i] < maxN && nums[i] > maxN2)
        {
            maxN2 = nums[i];
        }
        i++;
    }
    ans.push_back(maxN);

    if (idx == 0)
    {
        maxN = maxN2;
    }

    while (i < nums.size())
    {
        maxN = max(maxN, nums[i++]);
        ans.push_back(maxN);
    }

    return ans;
}

int main(){
    vector<int> nums = {1};
    int k =1;
    vector<int> ans = maxSlidingWindow(nums,k);
    return 0;
}