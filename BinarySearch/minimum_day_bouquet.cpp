#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool valid(int minDay, vector<int>& bloomDay, int m, int k, int n){
        int bouquet = 0, count = 0;
        for(int i = 0; i < n; i++){
            if(bloomDay[i] <= minDay) count++;
            else count = 0;

            if(count == k) {bouquet++; count = 0;}
            if(bouquet == m) break;
        }

        return bouquet == m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(), low = INT32_MAX, high = INT32_MIN;
        for(int el : bloomDay){
            low = min(el,low);
            high = max(el,high);
        }
        int ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(valid(mid,bloomDay,m,k,n)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return ans;
    }
};

int main (){

}