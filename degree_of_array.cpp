#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int degree = 0;
        unordered_map<int,int> freq;
        unordered_map<int,int> end;

        for(int i = 0; i<nums.size(); i++){
            freq[nums[i]]++;
            degree = max(degree,freq[nums[i]]);
            end[nums[i]] = i;
        }
        cout<<"Degree : "<<degree<<endl;
        cout<<"End of 2 : "<<end[2]<<endl;
        int dis = INT32_MAX;
        for(auto val : freq){
            if(val.second == degree){
                int start = find(nums.begin(),nums.end(),val.first) - nums.begin();
                cout<<"Value : "<<val.first<<" START : "<<start<<" END : "<<end[val.first]<<endl;
                dis = min(dis,((end[val.first] - (start - 1)) + 1));
                cout<<"DISTANCE : "<<dis<<endl;
            }
        }
        return dis;

    }
};
int main (){
    vector<int> nums = {1,1,2,2,2,1};
    auto obj = Solution();
    cout<<obj.findShortestSubArray(nums)<<endl;
    return 0;
}