#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int arrangeCoins(int n) {
        long long fact = 1;
        int row = 0;
        while(true){
            if(fact <= n) row++;
            else break;
            fact+=row+1;
        }
        return row;
    }
};
int main (){

}