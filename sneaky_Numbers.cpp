#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> freq;
        for(int el: nums){
            if(freq.find(el) != freq.end()){
                ans.push_back(el);
            }
            freq.insert(el);
            if(ans.size() == 2) break;
        }
        return ans;
    }
};

int main (){

}