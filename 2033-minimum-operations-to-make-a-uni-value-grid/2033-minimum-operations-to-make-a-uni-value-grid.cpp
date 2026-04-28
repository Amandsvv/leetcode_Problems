class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        int rem = grid[0][0] % x;
        for(auto & vec : grid){
            for(auto & el : vec){
                if(el % x != rem) return -1;
                arr.push_back(el);
            }
        }

        sort(arr.begin(), arr.end());
        int val = arr[arr.size() / 2], cnt = 0;

        for(int el : arr){
            cnt += abs(el - val) / x;
        }
        return cnt;
    }
};