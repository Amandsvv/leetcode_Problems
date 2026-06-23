class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> ans(n, 0);
        if(n == 1 && paths.empty()) return {1};
        vector<vector<int>> adj(n+1);
        for(auto vec : paths){
            int a = vec[0], b = vec[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i = 0; i < n ; i++){
            bool used[5] = {false};
            for(int edge : adj[i + 1]){
                used[ans[edge - 1]] = true;
            }
            for(int color = 1; color <= 4; ++color){
                if(!used[color]){
                    ans[i] = color;
                    break;
                }
            }
        }
        return ans;
    }
};