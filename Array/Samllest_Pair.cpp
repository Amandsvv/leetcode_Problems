#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>

using namespace std;


class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int,int> freq;
        if(nums.size() < 2) return {-1,-1};
        for(int el : nums) freq[el]++;

        vector<int> vals;
        for(auto &p: freq) vals.push_back(p.first);

        sort(vals.begin(), vals.end());

        vector<int> ans = {-1,-1};

        for(int i = 0; i < vals.size(); i++){
            for(int j = i+1; j < vals.size(); j++){
                int x = vals[i];
                int y = vals[j];

                if(freq[x] == freq[y]) continue;

                if(ans[0] == -1 || x < ans[0] || (x == ans[0] && y < ans[1])) ans = {x,y};
            }
        }
       
        return ans;
    }
};

vector<int> optimisedVersion(vector<int> & nums){
    map<int,int> freq;
    for(int el : nums) freq[el]++;

    for(auto &p1 : freq){
        for(auto &p2 :freq){
            if(p1.first != p2.first && p1.second != p2.second){
                return {p1.first, p2.first};
            }
        }
    }
    return {-1,-1};
    
}
int main (){

}