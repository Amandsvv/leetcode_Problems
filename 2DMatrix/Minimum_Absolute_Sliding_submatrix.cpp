#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1, 0));

        for(int i1 = 0; i1 <= n - k; i1++) {
            for(int j1 = 0; j1 <= m - k; j1++) {
                int i2 = i1 + k;
                int j2 = j1 + k;
                
                set<int> unique;
                for(int i = i1; i < i2; i++) {
                    for(int j = j1; j < j2; j++) {
                        unique.insert(grid[i] [j]);
                    }
                }
                
                if(unique.size() == 1) {
                    ans[i1] [j1] = 0;
                    continue;
                }
                
                vector<int> nums(unique.begin(), unique.end());
                int minAbs = INT32_MAX;
                for(int i = 1; i < nums.size(); i++) {
                    minAbs = min(minAbs, abs(nums[i] - nums[i-1]));
                }
                ans[i1] [j1] = minAbs;
            }
        }

        return ans;
    }
};
int main (){
    
}