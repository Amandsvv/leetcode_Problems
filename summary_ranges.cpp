#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>

using namespace std;

int main(){
    // string range = to_string(0)+"->" + to_string(1);
    // cout<<range<<endl;
    vector<int> nums = {0,1,1,2,1};
    unordered_map<int,vector<int>> idx;
    for(int i = 0; i < nums.size(); i++){
        idx[nums[i]].push_back(i);
    }

    for(pair<int,vector<int>> pair : idx){
        cout<<pair.first;
        cout<<"[";
        for(int val : pair.second){
            cout<<val<<",";
        }
        cout<<"]"<<endl;
    }
}