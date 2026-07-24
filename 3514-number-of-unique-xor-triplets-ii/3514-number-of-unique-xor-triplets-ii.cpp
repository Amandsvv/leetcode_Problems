class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        // unordered_set<int> seen;
        int n = nums.size(), cnt = 0;
        // for (int j = 0; j < n; j++) {
        //     for (int k = j; k < n; k++) {
        //         int a = nums[j] ^ nums[k];
        //         if (seen.find(a) == seen.end()) {
        //             seen.insert(a);
        //         }
        //     }
        // }
        // unordered_set<int> saw;
        // for(int i = 0; i < n; i++){
        //     for(auto & el : seen){
        //         int a = nums[i] ^ el;
        //         if(saw.find(a) == saw.end()){
        //             saw.insert(a);
        //             cnt++;
        //         }
        //     }
        // }

        static constexpr int MAXEXPR = (1 << 11);
        vector<bool> uniq(MAXEXPR, false);
        vector<bool> ans( MAXEXPR, false);

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                uniq[nums[i] ^ nums[j]] = 1;
            }
        }

        for(int i = 0; i < MAXEXPR; i++){
            if(uniq[i]){
                for(auto & n : nums){
                    ans[i ^ n] = 1;
                }
            }
        }

        for(int i = 0; i < MAXEXPR; i++){
            if(ans[i]) cnt++;
        }
        return cnt;
    }
};