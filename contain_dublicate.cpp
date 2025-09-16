// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool isValid(vector<int> &nums){
    sort(nums.begin(),nums.end());

    for(int i = 1; i< nums.size(); i++){
        if(nums[i] == nums[i-1]){
            return true;
        }
    }
    return false;
}

int main(){
    vector<int> A = {1,2,3,4,1};

    cout<<isValid(A);
    return 0;
}