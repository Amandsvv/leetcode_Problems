// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void sortColors(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int pivot = i;

        for (int j = i; j < nums.size(); j++)
        {
            if (nums[pivot] > nums[j])
            {
                pivot = j;
            }
        }

        int temp = nums[i];
        nums[i] = nums[pivot];
        nums[pivot] = temp;
    }
}

int main(){
    vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);
    return 0;
}