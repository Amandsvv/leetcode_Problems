#include <iostream>
#include <vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

int findLHS(vector<int> &nums)
{
    unordered_map<int, int> freq;
    int ans = 0;

    for (int num : nums)
    {
        freq[num]++;
    }

    for (auto [key, val] : freq)
    {
        if (freq.count(key + 1))
        {
            ans = max(ans, val + freq[key + 1]);
        }
    }

    return ans;
}
int main()
{
    vector<int> nums = {1, 3, 2, 2, 5, 2, 4};
    cout<<findLHS(nums)<<endl;
}