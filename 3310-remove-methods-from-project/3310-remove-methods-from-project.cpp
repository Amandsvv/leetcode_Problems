class Solution {
public:
    void dfs(int edge, vector<bool>& vis, vector<vector<int>>& adj) {
        vis[edge] = true;
        for (auto& neigh : adj[edge]) {
            if (!vis[neigh]) {
                dfs(neigh, vis, adj);
            }
        }
    }
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        for (auto& vec : invocations) {
            auto& u = vec[0];
            auto& v = vec[1];
            adj[u].push_back(v);
        }

        vector<bool> vis(n, false);

        dfs(k, vis, adj);

        bool canRemove = true;
        for (auto& vec : invocations) {
            auto& u = vec[0];
            auto& v = vec[1];
            if (!vis[u] && vis[v]) {
                canRemove = false;
                break;
            }
        }

        vector<int> ans;
        if (canRemove) {
            for (int i = 0; i < n; i++) {
                if (!vis[i])
                    ans.push_back(i);
            }
        } else {
            for(int i = 0; i < n; i++) ans.push_back(i);
        }
        return ans;
    }
};