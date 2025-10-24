#include<iostream>
#include<vector>
using namespace std;

bool isFound(vector<int>& nums, int tar){
    int start = 0, end = nums.size()-1;

    while(start <= end){
        int mid = start + (end - start)/2;

        if(nums[mid] == tar){
            return true;
        }

        // Handle duplicates
        if(nums[start] == nums[mid] && nums[end] == nums[mid]){
            start++;
            end--;
            continue;
        }

        if(nums[start] <= nums[mid]){
            if(tar >= nums[start] && tar < nums[mid]){
                end = mid-1;
            }else{
                start= mid+1;
            }
        }else{
            if(tar <= nums[end] && tar > nums[mid]){
                start = mid +1;
            }else{
                end = mid-1;
            }
        }
    }

    return false;
}
int main (){
    vector<int> nums = {2,2,2,2,3,2,2,2};
    int tar = 3;

    if(isFound(nums,tar)){
        cout<<"Found"<<endl;
    }else{
        cout<<"Not Found"<<endl;
    }

}