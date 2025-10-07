// 152. Maximum Product Subarray

// Given an integer array nums, find a subarray that has the largest product, and return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.

#include<iostream>
#include<vector>

using namespace std;

int maxProduct(vector<int>& nums) {
    int maxP = INT32_MIN;
    int pro = nums[0];

    for(int i = 1; i < nums.size(); i++){
        if(nums[i] * pro > pro){
            pro*=nums[i];
        }else{
            maxP = max(maxP, pro);
            pro = nums[i];
        }
    }
    maxP = max(maxP, pro);

    return maxP;
}

int main(){
    vector<int> nums = {1,2,3};
    cout << "maximum Product Subarray is : "<<maxProduct(nums)<<endl;
    return 0;
}
