#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int prefix = 0;

        for (int bit : nums) {
            prefix = (prefix * 2 + bit) % 5;
            ans.push_back(prefix == 0);
        }
        return ans;
    }
};

int main (){
    Solution obj;
    vector<int> nums = {0,1,1};
    vector<bool> ans = obj.prefixesDivBy5(nums);
}