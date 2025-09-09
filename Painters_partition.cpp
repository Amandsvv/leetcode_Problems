// Given an array arr[] where each element denotes the length of a board, and an integer k representing the number of painters available. Each painter takes 1 unit of time to paint 1 unit length of a board.

// Determine the minimum amount of time required to paint all the boards, under the constraint that each painter can paint only a contiguous sequence of boards (no skipping or splitting allowed).

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int> boards, int n, int m, int mid){
    int painters = 1, time = 0;

    for(int i = 0; i<n; i++){
        if(time + boards[i] <= mid){
            time += boards[i];
        }else{
            painters++;
            time = boards[i];
        }
    }

    return painters<= m? true:false;
}

int minTime(vector<int> nums, int n, int m){
    auto max_it = max_element(nums.begin(),nums.end());
    int max_value = *max_it;

    int sum =0;
    for(int el: nums){
        sum+=el;
    }

    int st = max_value, end = sum, ans = -1;

    if(m == n) return max_value;

    while(st <= end){
        int mid = st + (end-st) /2;

        if(isPossible(nums,n,m,mid)){
            ans = mid;
            end = mid -1;
        }
        else{
            st = mid +1;
        }
    }

    return ans;
}

int main(){
    vector<int> nums = {15,17,20};
    int m =2;
    int n = nums.size();

    cout<<minTime(nums,n,m);
}