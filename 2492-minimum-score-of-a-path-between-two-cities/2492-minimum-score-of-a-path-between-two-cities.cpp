class Solution {
private:
    int min_weight = INT_MAX;
    void dfs(vector<vector<pair<int, int>>>& adj, vector<bool>& vis, int src){
        if(vis[src]) return;
        vis[src] = true;
        for(auto & p : adj[src]){
            int edge = p.first, weight = p.second;
            min_weight = min(min_weight, weight);
            if(!vis[edge]){
                dfs(adj, vis, edge);
            }
        }
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto & vec : roads){
            int u = vec[0], v = vec[1], w = vec[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<bool> vis(n+1, false);
        dfs(adj,vis, 1);
        return min_weight;
    }
};