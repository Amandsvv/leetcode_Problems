#include<iostream>
#include<vector>

using namespace std;

int binary_search(vector<int> arr, int target){
    int i = 0,j = arr.size();

    while(i <= j){
        int mid = i + (j-i) /2;
        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] < target){
            i = mid+1;
        }else{
            j = mid-1;
        }
    }

    return -1;
}