// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

// You can either start from the step with index 0, or the step with index 1.

// Return the minimum cost to reach the top of the floor.

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minCost(vector<int> & A){
    int n = A.size();
    vector<int> dp(n);

    dp[0] = A[0];
    dp[1] = A[1];

    for(int i = 2; i < n; i++){
        dp[i] = A[i] + min(dp[i-1],dp[i-2]);
    }

    return min(dp[n-1], dp[n-2]);
}

int main(){
    vector<int> costs = {1,0,2,1};

    cout<<minCost(costs);
    return 0;

}