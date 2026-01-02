#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int el : nums){
            freq[el]++;
            if(freq[el] == nums.size()/2) return el;
        }
        return 0;
    }
};
int main (){

}