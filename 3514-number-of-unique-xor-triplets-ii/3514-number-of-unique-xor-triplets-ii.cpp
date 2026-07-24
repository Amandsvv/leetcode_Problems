class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> seen;
        int n = nums.size(), cnt = 0;
        for (int j = 0; j < n; j++) {
            for (int k = j; k < n; k++) {
                int a = nums[j] ^ nums[k];
                if (seen.find(a) == seen.end()) {
                    seen.insert(a);
                }
            }
        }
        unordered_set<int> saw;
        for(int i = 0; i < n; i++){
            for(auto & el : seen){
                int a = nums[i] ^ el;
                if(saw.find(a) == saw.end()){
                    saw.insert(a);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};