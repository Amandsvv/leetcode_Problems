#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        pair<int,int> p = {0,INT32_MAX};
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int first = nums[i];
            int st = i+1, end = n - 1;
            while(st < end){
                int sum = first + nums[st] + nums[end];
                if(sum == target){
                    return sum;
                }

                int diff = 0;
                if( sum >-1 && target >-1){
                    diff = sum > target ? sum - target: target - sum;
                }else{
                    diff = sum > target ? sum + abs(target): target + abs(sum);
                }

                if(p.second > diff){
                    p.first = sum;
                    p.second = diff;
                }
                if(sum < target){  
                    st++;
                }
                else{
                    end--;
                }
            }
        }
        return p.first;
    }
};
int main (){
    vector<int> nums = {1,-1,2,4};
    int tar = 1;
    auto obj = Solution();
    cout<<obj.threeSumClosest(nums,tar);
    return 0;
}