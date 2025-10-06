#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    int n = intervals.size();
    vector<vector<int>> ans;
    
    int low = intervals[0][0];
    int high = intervals[0][1];

    for(int i = 1; i < n ; i++){
        if(intervals[i][0] > high){
            ans.push_back({low,intervals[i-1][1]});
            low = intervals[i][0];
            high = intervals[i][1];
        }else{
            high = max(high, intervals[i][1]);
        }
    }
    ans.push_back({low,high});
    
    return ans;
}

int main(){
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>> ans = merge(intervals);

    for(vector<int> nums : ans){
        for(int el : nums){
            cout<<el<<" ";
        }
        cout<<endl;
    }

    return 0;
}