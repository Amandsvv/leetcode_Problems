#include<iostream>
#include<vector>

using namespace std;

  vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<int> freq(n*n,0);
    vector<int> ans = {0,0};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            freq[grid[i][j]-1]++;
        }
    }

    for(int i = 0 ; i < n*n; i++){
        cout<<i+1<<" freq : "<<freq[i]<<endl;
    }
    return ans;
}
int main(){
    vector<vector<int>> nums = {{9,1,7}, {8,9,2}, {3,4,6}};
    vector<int> ans = findMissingAndRepeatedValues(nums);

    for(int el : ans){
        cout<<el<<" ";
    }
    cout<<endl;
}