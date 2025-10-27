#include<iostream>
#include<vector>
using namespace std;

int sumArr(vector<int> &nums, int i, int sum){
    if(i == nums.size()) return sum;
    sum+=nums[i];
    sumArr(nums,i+1,sum);
}
int main (){
    vector<int> nums = {1,2,3,4};
    cout<<"Sum : "<<sumArr(nums,0,0);
}