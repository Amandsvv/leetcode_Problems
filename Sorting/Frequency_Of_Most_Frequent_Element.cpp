#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Gives TLE with bigger inputs
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int maxF = INT32_MIN;

        sort(nums.begin(), nums.end());

        for(int i = n-1; i >= 0; i--){
            int val = nums[i];
            int count = 1;
            int maxOp = k;

            for( int j = i-1; j >= 0; j--){
                if(nums[j] == val) count++;
                else{
                    int op = val - nums[j];
                    if(op <= maxOp){
                        count++;
                        maxOp-=op;
                    }else{
                        break;
                    }
                }
            }
            maxF = max(maxF, count);
        }
        return maxF;
    }
};

//Optimised version of the code

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        long long sum = 0;
        int ans = 1;

        for(int right = 0; right < nums.size(); right++){
            sum+=nums[right];

            while((long long)nums[right]* (right - left + 1) > sum + k){
                sum-=nums[left];
                left++;
            }
            ans = max(ans, right-left +1);
        }

        return ans;
    }
};
int main (){

}