#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int i = 0;
        int maxLen = 0;
        
        for (int j = 0; j < n; j++) {
            while ((long long)nums[j] > (long long)k * nums[i]) {
                i++;  // shrink window from left
            }
            maxLen = max(maxLen, j - i + 1);
        }
        
        return n - maxLen;
    }
};
int main(){
}
