#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestBalanced(vector<int> &nums)
{
    unordered_map<int, int> el;
    int even = 0, odd = 0;
    for (int val : nums)
    {
        if(el.find(val) == el.end()){
            if (val % 2 == 0)
            {
                even++;
            }
            else
            {
                odd++;
            }
        }
        el[val]++;
    }

    int i = 0, j = nums.size() - 1;
    while (even != odd)
    {
        if (odd > even)
        {
            if (nums[i] % 2 != 0)
            {
                if(el[nums[i]] == 1){
                    odd--;
                    el[nums[i]]--;
                }
                i++;
            }
            else if (nums[j] % 2 != 0)
            {
                if(el[nums[j]] == 1){
                    odd--;
                    el[nums[j]]--;
                }
                j--;
            }
            else
            {
                if (nums[i] != nums[j])
                {
                    if(el[nums[i]] == 1){
                        even--;
                        el[nums[i]]--;
                    }else if(el[nums[j]] == 1){
                        even--;
                        el[nums[j]]--;
                    }
                }else{
                    el[nums[i]]--;
                    i++;
                }
            }
        }
        else
        {
            if (nums[i] % 2 == 0)
            {
                if(el[nums[i]] == 1){
                    even--;
                    el[nums[i]]--;
                }
                i++;
            }
            else if (nums[j] % 2 == 0)
            {
                if(el[nums[j]] == 1){
                    even--;
                    el[nums[j]]--;
                }
                j--;
            }
            else
            {
                if (nums[i] != nums[j])
                {
                    if(el[nums[i]] == 1){
                        odd--;
                        el[nums[i]]--;
                    }else if(el[nums[j]] == 1){
                        odd--;
                        el[nums[j]]--;
                    }
                }else{
                    el[nums[i]]--;
                    i++; 
                }
            }
        }
    }
    return j - i + 1;
}

int main()
{
    vector<int> nums = {1, 2, 3, 2};
    cout << "Longest balances subaaraay = " << longestBalanced(nums) << endl;
    return 0;
}