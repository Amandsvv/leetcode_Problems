#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        // Sort to find consecutive sequences easily
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        
        int maxH = 1, maxV = 1;
        
        // Find longest consecutive sequence in horizontal bars
        int curr = 1;
        for(int i = 1; i < hBars.size(); i++){
            if(hBars[i] == hBars[i-1] + 1) {
                curr++;
            } else {
                curr = 1; // Reset if not consecutive
            }
            maxH = max(maxH, curr);
        }
        
        // Find longest consecutive sequence in vertical bars
        curr = 1;
        for(int i = 1; i < vBars.size(); i++){
            if(vBars[i] == vBars[i-1] + 1) {
                curr++;
            } else {
                curr = 1; // Reset if not consecutive
            }
            maxV = max(maxV, curr);
        }
        
        // Side length is limited by the smaller dimension
        // Add 1 because n consecutive bars create n+1 sized gap
        int length = min(maxH + 1, maxV + 1);
        
        return length * length;
    }
};
int main (){
    int n = 2, m = 1;
    vector<int> hBars = {2,3};
    vector<int> vBars = {2};
    Solution obj;
    cout<<"Area of Square : "<<obj.maximizeSquareHoleArea(n,m,hBars,vBars)<<endl;
    return 0;
}