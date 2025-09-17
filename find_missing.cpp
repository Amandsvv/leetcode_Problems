// 268. Missing Number
// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int missingNumber(vector<int> &nums)
{
    bool isFound0 = false;
    int sum = 0;
    int x = nums[0];

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0) isFound0 = true;

        sum += nums[i];
        x = max(x, nums[i]);
    }

    if (!isFound0) return 0;

    int sumNnatural = (x * (x + 1)) / 2;
    if (sum == sumNnatural)
    {
        return x + 1;
    }
    else
    {
        return sumNnatural - sum;
    }

    return -1;
}

int missingNumber2(vector<int>& nums){
    sort(nums.begin(),nums.end());

    if(nums[0] != 0) return 0;

    for(int i =1; i<nums.size(); i++){
        if(nums[i] != nums[i-1] +1){
            return nums[i] -1;
        }
    }

    return nums[nums.size()-1] +1;
}
int main()
{
    vector<int> A = {0,3,1};
    cout<<missingNumber(A);
}