#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int gcdRec(int a, int b){
        if(b == 0) return a;
        return gcdRec(b,a%b);
    } 
    int smallestEvenMultiple(int n) {
        return (2 * n) / gcdRec(2,n);
    }
};
int main (){

}