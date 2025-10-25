#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int>& stalls, int n, int c, int minAllowedDis){
    int cow = 1, currDis = 0;
    
    for(int i = 1; i <n; i++){
        int dis = stalls[i] - stalls[i-1];
        currDis+=dis;
        if(currDis >= minAllowedDis){
            cow++;
            currDis = 0;
        }
    }

    return cow == c? true: false;
}
int maxDistance(vector<int>& stalls, int n, int c){

    if(n < c) return -1;
    sort(stalls.begin(), stalls.end());     
    int start = 1, end = stalls[n-1] - stalls[0], ans = -1;

    while(start <= end){
        int mid = start + (end - start) /2;

        if(isPossible(stalls,n,c,mid)){
            ans = mid;
            start = mid+1;
        }else{
            end = mid-1;
        }
    }

    return ans;
}
int main (){
    vector<int> stalls = {1,2,8,4,9};
    int n = 5, c = 3;
    cout<<maxDistance(stalls,n,c);
}