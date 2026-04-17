class Solution {
public:
    int reverse(int x){
        int rev = 0;
        while(x){
            rev = rev *10 + (x%10);
            x/=10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> reversed;
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(reversed.count(nums[i])){
                ans = min(abs(reversed[nums[i]] - i), ans);
            }
            reversed[reverse(nums[i])] = i;
        }  
        return ans == INT_MAX ? -1 : ans;
    }
};