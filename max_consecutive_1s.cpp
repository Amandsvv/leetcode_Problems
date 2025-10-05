#include<iostream>
#include<vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0, maxC = 0;

    int i = 0;
    while(i < nums.size()){
        while(i < nums.size() && nums[i] != 0){
            count++;
            i++;
        }
        maxC = max (maxC , count);
        while(i < nums.size() && nums[i] == 0){
            i++;
        }
        count = 0;
    }

    return maxC;
}

int main(){
    vector<int> nums = {1,1,0,1,1,1};
    cout<< "Max Consecutive 1s is : "<< findMaxConsecutiveOnes(nums)<<endl;
    return 0;

}