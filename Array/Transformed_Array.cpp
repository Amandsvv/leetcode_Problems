#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,0);

        for(int i = 0;i <n ; i++){
            int idx;
            if(nums[i] > 0){
                idx = (i + nums[i]) % n;
            }else if(nums[i] < 0){
                idx = ((i - abs(nums[i])) % n + n) % n;
            }else{
                idx= i;
            }
            result[i] = nums[idx];
        }
        return result;
    }
};
int main (){

}