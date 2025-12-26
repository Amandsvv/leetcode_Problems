#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int bestClosingTime(string cust) {
        int n = cust.size();
        vector<int> prefixY(n,0);
        vector<int> prefixN(n,0);
        int sumY = 0, sumN = 0;

        for(int i = 0; i < n; i++){
            if(cust[i] == 'Y'){
                sumY++;
            } else {
                sumN++;
            }
            prefixY[i] = sumY;
            prefixN[i] = sumN;
        }

        int minPenality = INT32_MAX, j = 0;

        for(int i = 0; i < n; i++){
            int penality;
            if(i == 0){
                penality = prefixY[n-1];
            } else {
                penality = prefixN[i-1] + (prefixY[n-1] - prefixY[i-1]);
            }
            if(penality < minPenality){
                minPenality = penality;
                j = i;
            }
        }

        // Case when shop remains open for all hours
        if(prefixN[n-1] < minPenality) j = n;

        return j;
    }
};

int main (){
    Solution obj;
    cout<<"Best closing time is : "<<obj.bestClosingTime("YYNY")<<endl;
    return 0;
}