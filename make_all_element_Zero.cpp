#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool isValid(vector<int>& arr, int curr, bool dir) {
        vector<int> temp1 = arr;

        while (curr >= 0 && curr < temp1.size()) {
            if (temp1[curr] == 0) {
                if (dir)
                    curr--;
                else
                    curr++;
            } else {
                temp1[curr]--;
                if (dir){
                    dir = false;
                    curr++;
                }
                else{
                    dir = true;
                    curr--;
                }
            }
            cout<<"[";
            for(int el: temp1){
                cout<<el<<",";
            }
            cout<<"]"<<endl;
        }
        cout<<"-----------------------------------------------"<<endl;
        if (temp1.size() == count(temp1.begin(), temp1.end(), 0)) return true;
        else return false;
    }
    int countValidSelections(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if(isValid(nums,i,true)) ans++;
                if(isValid(nums,i,false)) ans++;
            }
        }
        return ans;
    }
};
int main (){
    vector<int> nums = {2,3,4,0,4,1,0};
    auto obj = new Solution();
    cout<<obj->countValidSelections(nums)<<endl;
}