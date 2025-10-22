#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int>& boards, int n, int m, int minTime){
    int painters = 1, currTime = 0;

    for(int i = 0; i < n; i++){
        if(boards[i] > minTime){
            return false;
        }

        if(currTime + boards[i] <= minTime){
            currTime += boards[i];
        }else{
            painters++;
            currTime = boards[i];
        }
    }

    return painters <= m ? true: false;
}
int findMinTime(vector<int>& boards, int n, int m){
    int maxVal = INT32_MIN, sum = 0;

    for(int el: boards){
        maxVal  = max(maxVal, el);
        sum += el;
    }

    int start = maxVal, end = sum, ans = -1;
    cout<<"here"<<endl;
    while(start <= end){
        int mid = start + (end- start) / 2;
        cout<<mid<<endl;
        if(isValid(boards,n,m,mid)){
            ans = mid;
            end = mid -1;
        }else{
            start = mid+1;
        }
    }

    return ans;
}
int main (){
    vector<int> boards = {10,10,10,10};
    int n = 4, m = 2;
    cout<<findMinTime(boards,n,m)<<endl;
}