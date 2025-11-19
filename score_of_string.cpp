#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxFreqSum(string s) {
        int n = s.size();
        vector<int> freq(26,0);

        for(int i = 0; i < n; i++){
            freq[s[i] - 'a']++;
        }
        int vow = 0, cons = 0;

        for(int i = 0; i < 26; i++){
            if(i == 0 || i == 4 || i == 8 || i == 14 || i == 20){
                vow = max(vow,freq[i]);
            }else{
                cons = max(cons,freq[i]);
            }
        }
        return vow+cons;
    }
};
int main (){
    string s = "aeiaeia";
    auto obj = Solution();
    cout<<obj.maxFreqSum(s)<<endl;

    cout<<abs('e' - 'a')<<endl;
}