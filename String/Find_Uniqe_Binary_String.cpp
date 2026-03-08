#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    void generateBinary(int n, string& current, vector<string>& result) {
        // Base Case: If the string reaches the target length n
        if (current.length() == n) {
            result.push_back(current);
            return;
        }

        // Choice 1: Add '0'
        current.push_back('0');
        generateBinary(n, current, result);
        current.pop_back(); // Backtrack: Remove '0' before trying the next choice

        // Choice 2: Add '1'
        current.push_back('1');
        generateBinary(n, current, result);
        current.pop_back(); // Backtrack: Remove '1'
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        vector<string> result;
        string current = "";
        generateBinary(n,current,result);
        sort(nums.begin(), nums.end());
        sort(result.begin(), result.end());

        int i = 0;
        while(i < n){
            if(result[i] != nums[i]) return result[i];
            i++;
        }
        return result[i];
    }
};
int main (){

}