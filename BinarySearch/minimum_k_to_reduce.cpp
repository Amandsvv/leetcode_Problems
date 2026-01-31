#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool nonPositive(vector<int>&nums, int k){
        long long op = 0;

        for(int i = 0; i < nums.size(); i++){
            op+=nums[i]/k;
            if(nums[i]%k != 0)op++;

            if(op > (long long)k*k) return false;
        }

        return true;
    }
    int minimumK(vector<int>& nums) {
        long long sum = 0;
        for(int el : nums) sum+=el;
        int i = 1, j = sqrt(sum)+1;
        int ans = 0;
        while(i <= j){
            int k = i + (j-i)/2;
            if(nonPositive(nums,k)){
                ans = k;
                j = k-1;
            }else{
                i = k+1;
            }
        }
        return ans;
    }
};
int main (){

}