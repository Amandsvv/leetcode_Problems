// 283. Move Zeroes
// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int> &nums)
{
    int count = 0;

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 0){
            count++;
            nums.erase(nums.begin()+i);
            i--;
        }
    }

    while(count){
        nums.push_back(0);
        count--;
    }
}

int main()
{
    vector<int> A = {0, 1, 2, 0, 3};
    moveZeroes(A);
    return 0;
}