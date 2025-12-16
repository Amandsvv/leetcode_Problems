#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& nums) {
        long long count = 1;
        long long len = 1;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1] -1){
                len++;
            }else{
                len = 1;
            }
            count += len;
        }
        return count;
    }
};

int main (){
    vector<int> prices = {3,2,1,4};
    Solution obj;
    cout<<"Descent period : "<<obj.getDescentPeriods(prices)<<endl;
    return 0;
}