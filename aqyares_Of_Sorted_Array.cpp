#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int st = 0, end = nums.size()-1;
        while(st <= end){
            if(abs(nums[st]) > abs(nums[end])){
                ans.push_back(nums[st] * nums[st]);
                st++;
            }else{
                ans.push_back(nums[end] *nums[end]);
                end--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
int main (){
    vector<int> nums = {-4,-3,0,1,2,10};
    auto obj = Solution();
    vector<int> ans = obj.sortedSquares(nums);

    for(int el : ans){
        cout<<el<<" ";
    }
    cout<<endl;
    return 0;
}