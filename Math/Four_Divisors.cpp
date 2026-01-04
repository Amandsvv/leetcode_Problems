#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int sum(int el){
        int s = 1;
        int count = 0;

        for(int  i = 2; i <= el/2; i++){
            if(el % i == 0){
                count++;
                s+=i;
            }
            if(count > 2) return 0;
        }
        return count == 2 ? s+el : 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for(int el : nums){
            ans += sum(el);
        }  
        return ans;
    }
};

int main (){

}