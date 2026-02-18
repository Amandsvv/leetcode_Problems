#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev =~(n & 1);
        while(n){
            int curr = n & 1;
            if(curr == prev){
                return false;
            }
            prev = curr;
            n >>= 1;
        }
        return true;
    }
};
int main (){

}