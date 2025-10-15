// 3712. Sum of Elements With Frequency Divisible by K

// You are given an integer array nums and an integer k.

// Return an integer denoting the sum of all elements in nums whose frequency is divisible by k, or 0 if there are no such elements.

// Note: An element is included in the sum exactly as many times as it appears in the array if its total frequency is divisible by k.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int sumDivisibleByK(vector<int> &nums, int k)
{
    unordered_map<int, int> freq;

    for (int el : nums)
    {
        freq[el]++;
    }
    int sum = 0;
    for (auto pair : freq)
    {
        if (pair.second % k == 0)
        {
            sum += (pair.first * pair.second);
        }
    }

    return sum;
}
int main()
{
    vector<int> nums = {1, 2, 2, 3, 3, 3, 3, 5};
    int k = 2;
    cout<<"Sum : "<<sumDivisibleByK(nums,k)<<endl;

    return 0;
}