class Solution {
public:
    int edge = 0, m = 0;
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[node] = true;
        m++;
        edge+=adj[node].size();
        for (auto& neigh : adj[node]) {
            if (!vis[neigh]) {
                dfs(neigh, adj, vis);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto vec : edges) {
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                edge = 0;
                m = 0;
                dfs(i, adj, vis);
                if (edge == (m * (m - 1)))
                    ans++;
            }
        }
        return ans;
    }
};