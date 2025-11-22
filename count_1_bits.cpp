#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp (n+1,0);
        int sub = 1;

        for(int i = 1; i<= n ; i++){
            if(sub * 2 == i){
                sub = i;
            }

            dp[i] = dp[i - sub] + 1;
        }

        return dp;
    }
};
int main (){
    auto obj = Solution();
    vector<int> ans = obj.countBits(5);
    for(int el : ans){
        cout<<el<<" ";
    }
    cout<<endl;
    return 0;
}