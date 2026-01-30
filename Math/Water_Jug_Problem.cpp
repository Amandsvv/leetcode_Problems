#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int gcdRec(int a, int b){
        if(b == 0) return a;
        return gcdRec(b,a%b);
    }
    bool canMeasureWater(int x, int y, int target) {
        if(target == 0) return true;
        if(x + y < target) return false;
        return target % gcdRec(x,y) == 0;
    }
};

int main (){

}