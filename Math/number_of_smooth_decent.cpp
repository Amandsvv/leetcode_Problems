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
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long i = 0, count = 0, n = prices.size();
        long long st = 0, end = 1;
        while(i < n-1){
            while(i < n-1 && prices[i] - prices[i+1] == 1){
                i++;
                end++;
            }
            long long total = end - st;
            count+= ((total*(total+1))/2);
            i++;
            st = end;
            end++;
        }
        return i == n?count:count+1;
    }
};
int main (){
    vector<int> prices = {3,2,1,4};
    Solution obj;
    cout<<"Descent period : "<<obj.getDescentPeriods(prices)<<endl;
    return 0;
}