// 747. Largest Number At Least Twice of Others

// You are given an integer array nums where the largest integer is unique.

// Determine whether the largest element in the array is at least twice as much as every other number
//  in the array. If it is, return the index of the largest element, or return -1 otherwise.

#include <iostream>
#include <vector>
using namespace std;

int dominantIndex(vector<int> &nums)
{
    int idx = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > nums[idx])
        {
            idx = i;
        }
    }
    bool isTwice = true;
    for (int el : nums)
    {
        if (el != nums[idx] && el * 2 > nums[idx])
        {
            isTwice = false;
            break;
        }
    }

    return isTwice ? idx : -1;
}

int main()
{
    vector<int> nums = {0,1,2,6,};

    int idx = dominantIndex(nums);
    cout<< idx<<endl;
}