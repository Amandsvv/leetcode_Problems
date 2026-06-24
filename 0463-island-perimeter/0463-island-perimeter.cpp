class Solution {
public:
    int islandPerimeter(vector<vector<int>>& adj) {
        int ans = 0;
        int n = adj.size(), m = adj[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(adj[i][j] == 1){
                    int cnt = 0;
                    if(i-1 < 0)cnt++;
                    else if(adj[i-1][j] == 0)cnt++;
                    if(i+1 >= n)cnt++;
                    else if(adj[i+1][j] == 0)cnt++;
                    if(j-1 < 0)cnt++;
                    else if(adj[i][j-1] == 0)cnt++;
                    if(j+1 >= m)cnt++;
                    else if(adj[i][j+1] == 0)cnt++;
                    ans+=cnt;
                }
            }
        }
        return ans;
    }
};