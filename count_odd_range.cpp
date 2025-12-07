#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int countOdds(int low, int high) {
        int odd = ((high-low) / 2);
        if(high %2 != 0 || low %2 != 0) odd++;
        return odd;
    }
};
int main (){

}