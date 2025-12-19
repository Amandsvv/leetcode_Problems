#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool valid(int n){
        for(int x = n; x > 0; x/=10){
            int d = x%10;
            if(d == 0 || n % d != 0) return false;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++){
            if(valid(i)) ans.push_back(i);
        }
        return ans;
    }
};
int main (){

}