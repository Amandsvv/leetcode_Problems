// 162. Find Peak Element

// A peak element is an element that is strictly greater than its neighbors.

// Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

// You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

// You must write an algorithm that runs in O(log n) time.

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findPeakElement(vector<int>& nums) {
    int i = 1, j = nums.size()-2;

    while(i <= j){
        int mid = i + (j -i)/2;
        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid +1]){
            return mid;
        }else if(nums[mid+1] < nums[mid-1]){
            j = mid -1;
        }else{
            i = mid+1;
        }
    }
    return nums[0] > nums[nums.size()-1] ? 0:nums.size()-1;
}

int main(){
    vector<int> nums = {1,2,3,2,1};
    cout<<"Peak index is : "<<findPeakElement(nums)<<endl;
    return 0;
}