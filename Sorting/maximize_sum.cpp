#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end(), greater<int>());
        int neg = 0;
        long long ans = 0;
        for(int i = 0; i < k; i++){
            long long di = happiness[i]-neg;
            if(di < 0) break;
            ans += di;
            neg++;
        }
        return ans;
    }
};

int main (){

}