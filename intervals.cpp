// 57. Insert Interval
// Solved
// Medium

// You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

// Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

// Return intervals after the insertion.

// Note that you don't need to modify intervals in-place. You can make a new array and return it.

 
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ans;

    int i = 0, n = intervals.size();
    if(n == 0) return {newInterval};
    while(i < n){
        if(newInterval.size() && newInterval[0] < intervals[i][0]){
            int low = newInterval[0], high = newInterval[1];
            if(i > 0 && low <= ans[i-1][1]){
                low = ans[i-1][0];
                high = max(high, ans[i-1][1]);
                ans.pop_back();
            }
            while(i < n && high >= intervals[i][0]){
                high = max(high,intervals[i][1]);
                i++;
            }
            ans.push_back({low,high});
            newInterval.pop_back();
            newInterval.pop_back();
        }
        if(i < n){
            ans.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }
    }

    if(newInterval.size()){
        int low = newInterval[0], high = newInterval[1];
        if(newInterval[0] <= ans[i-1][1]){
            low = ans[i-1][0];
            high = max(high,ans[i-1][1]);
            ans.pop_back();
        }
        ans.push_back({low,high});
    }
    return ans;
}
int main(){
    vector<vector<int>> intervals = {{1,2},{3,6},{8,12}};
    vector<int> newInterval = {4,5};

    vector<vector<int>> ans = insert(intervals,newInterval);

    for(auto arr : ans){
        for(int val: arr){
            cout<<val<<" ";
        }
        cout<<endl;
    }
}