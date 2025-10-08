// 219. Contains Duplicate II

// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

// unordered_map<int,vector<int>> idx;
// for(int i = 0; i < nums.size(); i++){
//     idx[nums[i]].push_back(i);
// }

// for(auto& pair : idx){
//     vector<int> arr = pair.second;
//     if(arr.size() > 1){
//         for(int i = 1; i < arr.size(); i++){
//             if(abs(arr[i] - arr[i-1]) <= k){
//                 return true;
//             }
//         }
//     }
// }

#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int,int> freq;

    for(int i = 0; i < nums.size(); i++){
        if(freq.find(nums[i]) != freq.end() && abs(i - freq[nums[i]]) <= k){
            return true;
        }
        freq[nums[i]] = i;
    }
    return false;
}

int main(){
    vector<int> nums = {0,1,1,2,1};
    int k = 2;

    if(containsNearbyDuplicate(nums,k)){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
}