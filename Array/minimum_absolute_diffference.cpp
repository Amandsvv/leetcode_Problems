#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;

        int minDiff = arr[1] - arr[0];
        for(int i = 2; i < arr.size(); i++){
            if(arr[i] - arr[i-1] < minDiff){
                minDiff = arr[i] - arr[i-1];
            }
        }
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] - arr[i-1] == minDiff){
               ans.push_back({arr[i-1], arr[i]});
            }
        }


        return ans;
    }
};

int main (){

}