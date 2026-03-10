#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return -1;

        const long long MAX_SUM = 100000000000000LL;
        const long long CAP = MAX_SUM +  7;

        vector<long long> suffix_products(n);
        long long prod = 1;

        for(int i = n-1; i >= 0; --i){
            suffix_products[i] = prod;
            if(nums[i] == 0) prod = 0;
            else if(prod > CAP/nums[i]) prod = CAP;
            else prod*=nums[i];
        }
        long long sum = 0;
        for(int i = 0; i< n; i++){
            if(sum == suffix_products[i]) return i;
            sum+=nums[i];
        }
        return -1;
    }
};
int main (){

}