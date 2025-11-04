#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n = nums.size();

        for(int i = 0; i + k <= n; i++){
            unordered_map<int,int> freq;

            //count frequencies
            for(int j = i; j < i+k; j++ ){
                freq[nums[j]]++;
            }

            //store as frequency,value
            vector<pair<int,int>> v;
            for(auto& p : freq){
                v.push_back({p.second,p.first});
            }

            //sort by frequencies descending
            sort(v.begin(),v.end(), [](auto& a, auto& b){
                if(a.first == b.first) return a.second > b.second;
                return a.first > b.first;
            });

            //compute x-sum

            int sum = 0;
            for(int j = 0; j < min(x, (int)v.size()); j++){
                sum+=v[j].first*v[j].second;
            }
            ans.push_back(sum);
        }

        return ans;
    }
};

int main (){
    vector<int> nums = {1,2,2,3,1};
    int k = 3;
    int x = 2;
    auto obj = Solution();
    vector<int> result = obj.findXSum(nums, k, x);
    for(int val : result){
        cout<<val<<" ";
    }
    cout<<endl;
}