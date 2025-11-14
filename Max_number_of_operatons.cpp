#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxOperations(string s) {
        int ones = 0, ans = 0;
        int n = s.size();

        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                ones++;
            }else{
                if(i+ 1 == n || s[i+1] == '1'){
                    ans+=ones;
                }
            }
        }
        return ans;
    }
};
int main (){
    string s = "101101";
    auto obj = Solution();
    cout<<obj.maxOperations(s)<<endl;
    return 0;
}