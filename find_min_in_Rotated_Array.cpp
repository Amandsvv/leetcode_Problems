// 153. Find Minimum in Rotated Sorted Array

// Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

// [4,5,6,7,0,1,2] if it was rotated 4 times.
// [0,1,2,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

// Given the sorted rotated array nums of unique elements, return the minimum element of this array.

// You must write an algorithm that runs in O(log n) time.

#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int> &nums)
{
    int i = 1, j = nums.size() - 2;

    while (i <= j)
    {
        int mid = i + (j - i) / 2;

        if (nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1])
        {
            return nums[mid];
        }
        else if (nums[i] <= nums[mid] && nums[j] <= nums[mid])
        {
            i = mid + 1;
        }
        else
        {
            j = mid - 1;
        }
    }
    return min(nums[0], nums[nums.size() - 1]);
}

int main()
{
    vector<int> nums = {3,4,5,6,1,2};
    cout<<"Minimum : "<<findMin(nums)<<endl;
    return 0;
}