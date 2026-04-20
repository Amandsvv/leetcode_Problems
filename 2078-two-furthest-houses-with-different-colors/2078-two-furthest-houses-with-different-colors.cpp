class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            int j = n - 1;
            while(j > i && colors[j] == colors[i]){
                j--;
            }
            ans = max(abs(j-i), ans);
        }
        return ans;
    }
};