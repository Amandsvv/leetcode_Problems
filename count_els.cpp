#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int maxFrequencyElements(vector<int> &nums)
{
    unordered_map<int, int> um;

    for (int el : nums)
    {
        um.emplace(el, um[el] += 1);
    }
    int count = 0, maxN = INT32_MIN;

    for (auto p : um)
    {
        maxN = max(maxN, p.second);
    }
    for (auto p : um)
    {
        if (p.second == maxN)
            count++;
    }
    return count * maxN;
}
int main()
{
    vector<int> A = {1,2,2,3,4};
    cout<<maxFrequencyElements(A);
    return 0;
}
