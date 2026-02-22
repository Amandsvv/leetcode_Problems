#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    string binary(int n){
        string bin = "";
        while(n){
            bin += n%2 + '0';
            n/=2;
        }
        reverse(bin.begin(), bin.end());
        return bin;
    }
    int binaryGap(int n) {
        string bin = binary(n);
        int last = -1, ans = 0;

        for(int i = 0; i < bin.size(); i++){
            if(bin[i] == '1'){
                if(last != -1)
                    ans = max(ans, i - last);
                last = i;
            }
        }
        return ans;
    }
};
int main (){

}