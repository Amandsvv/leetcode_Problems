// 3349. Adjacent Increasing Subarrays Detection I

// Given an array nums of n integers and an integer k, determine whether there exist two adjacent subarrays
//  of length k such that both subarrays are strictly increasing. Specifically, check if there are two subarrays
//   starting at indices a and b (a < b), where:

// Both subarrays nums[a..a + k - 1] and nums[b..b + k - 1] are strictly increasing.
// The subarrays must be adjacent, meaning b = a + k.
// Return true if it is possible to find two such subarrays, and false otherwise.

#include <iostream>
#include <vector>

using namespace std;

bool hasIncreasingSubarrays(vector<int> &nums, int k)
{
    int n = nums.size();

    for (int i = 0; i + 2 * k <= n; i++)
    {
        bool firstInc = true, secondInc = true;

        // Check first subarray [i .. i+k-1]
        for (int j = i + 1; j < i + k; j++)
        {
            if (nums[j] <= nums[j - 1])
            {
                firstInc = false;
                break;
            }
        }

        if (!firstInc)
            continue; // no need to check second if first fails

        // Check second subarray [i+k .. i+2k-1]
        for (int j = i + k + 1; j < i + 2 * k; j++)
        {
            if (nums[j] <= nums[j - 1])
            {
                secondInc = false;
                break;
            }
        }

        if (firstInc && secondInc)
            return true;
    }

    return false;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int k = 3;

    cout<<hasIncreasingSubarrays(nums,k)<<endl;
}