// Write an algorithm to determine if a number n is happy.

// A happy number is a number defined by the following process:

// Starting with any positive integer, replace the number by the sum of the squares of its digits.
// Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
// Those numbers for which this process ends in 1 are happy.
// Return true if n is a happy number, and false if not.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isFound(vector<int> &nums, int n)
{
    sort(nums.begin(), nums.end());
    int i = 0, j = nums.size() - 1;

    while (i <= j)
    {
        int mid = i + (j - i) / 2;

        if (nums[mid] == n)
        {
            return true;
        }
        else if (nums[mid] > n)
        {
            j = mid - 1;
        }
        else
        {
            i = mid + 1;
        }
    }
    return false;
}
bool isHappy(int n)
{
    vector<int> ans;
    ans.push_back(n);

    bool valid = true;

    while (valid)
    {
        int val = 0;

        while (n)
        {
            int di = n % 10;
            val += (di * di);
            n /= 10;
        }

        if (val == 1)
        {
            return true;
        }

        if (!isFound(ans, val))
        {
            ans.push_back(val);
            n = val;
        }
        else
        {
            valid = false;
            return false;
        }
    }
    return false;
}

int main(){
    
    cout<< isHappy(19);
    return 0;
}