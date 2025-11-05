#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() < 3) return true;
        int i = 0, n = nums.size();
        bool isInc = false;
        bool isDec = false;
        while(i < n && nums[0] == nums[i]){
            i++;
        }
        int j = i;
        while(j < n && nums[i] == nums[j]){
            j++;
        }

        if(j == n) return true;

        if(nums[i] > nums[0] && nums[i] < nums[j]){
            isInc = true;
        }else if(nums[i] < nums[0] && nums[i] > nums[j]){
            isDec = true;
        }else{
            return false;
        }
        if(isInc){
            for(int i = j+1; i < n; i++){
                if(nums[i] < nums[i-1]){
                    return false;
                }
            }
        }else{
            for(int i = j+1; i < n; i++){
                if(nums[i] > nums[i-1]){
                    return false;
                }
            } 
        }
        
        return true;
    }
};

int main (){
    vector<int> ans = {1,2,3,4};
    auto obj = Solution(); 
    if(obj.isMonotonic(ans)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

    return 0;
}