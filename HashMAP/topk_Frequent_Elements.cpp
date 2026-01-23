#include <iostream>
#include <vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        for (int el : nums)
        {
            freq[el]++;
        }
        vector<pair<int, int>> pairFreq(freq.begin(), freq.end());

        sort(pairFreq.begin(), pairFreq.end(), [](const auto &a, const auto &b)
                     {
 return a.second > b.second;
});

         vector<int> ans;
       for (auto [a, b] : pairFreq)
        {
             int n = ans.size();
             if (n == k) break;
             else
            {
                 ans.push_back(a);
                
            }
            
        }
         return ans;
    }
};
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int x : nums)
            freq[x]++;

        // Bucket: Index represents frequency, Value is a list of numbers
        vector<vector<int>> buckets(n + 1);
        for (auto const &[val, count] : freq)
        {
            buckets[count].push_back(val);
        }

        vector<int> ans;
        // Go from the highest possible frequency (n) down to 1
        for (int i = n; i >= 1; i--)
        {
            for (int num : buckets[i])
            {
                ans.push_back(num);
                if (ans.size() == k)
                    return ans;
            }
        }
        return ans;
    }
};

int main()
{
}