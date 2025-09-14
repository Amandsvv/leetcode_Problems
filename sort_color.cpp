// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Brute force Approch

void sortColors(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int pivot = i;

        for (int j = i; j < nums.size(); j++)
        {
            if (nums[pivot] > nums[j])
            {
                pivot = j;
            }
        }

        int temp = nums[i];
        nums[i] = nums[pivot];
        nums[pivot] = temp;
    }
}

//Optimised version having Time complexity = O(n)

void sortColor1(vector<int> nums){

    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    for(int i = 0; i<nums.size() ; i++){
        if(nums[i] == 0){
            count0++;
        }else if(nums[i] == 1){
            count1++;
        }else{
            count2++;
        }
    }

    int i = 0;
    while(count0>0){
        nums[i++] = 0;
        count0--;
    }
    while(count1>0){
        nums[i++] = 1;
        count1--;
    }
    while(count2 > 0){
        nums[i++] = 2;
        count2--;
    }
        
}

// Using Dutch National Flag Algorithm (in single pass)

void sortColorUsingDutchAlgo(vector<int> nums){

    int mid = 0,low = 0, high = nums.size()-1;

    while(mid <= high){
        if(nums[mid] == 2){
            swap(nums[mid],nums[high]);
            high--;
        }else if(nums[mid] == 1){
            mid++;
        }else{
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }
    }
}
int main(){
    vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);
    return 0;
}