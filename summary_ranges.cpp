#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>

using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    int i = 0, j = 0;
    vector<string> ans;

    while(j < nums.size()){
        string range = ""; j++;
        while(j < nums.size() && (nums[j] == nums[j-1] + 1 || nums[j] == nums[j-1])){
            j++;
        }
        if(i == j-1 || nums[i] == nums[j-1]){
            range = to_string(nums[i]);
        }else{
            range = to_string(nums[i])+"->" + to_string(nums[j-1]);
        }
        ans.push_back(range);
        i = j;
    }

    return ans;
}

int main(){
    vector<int> nums = {1,2,4,5,7};

    vector<string> ans = summaryRanges(nums);

    for(string str : ans){
        cout<<str<<" ";
    }
    cout<<endl;
}