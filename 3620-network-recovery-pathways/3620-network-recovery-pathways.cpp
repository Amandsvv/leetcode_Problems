class Solution {
private:
    bool check(long long mid, int n, const vector<vector<pair<int, int>>>& adj, 
               const vector<bool>& online, long long k, const vector<int>& topo_order) {
        vector<long long> dp(n, LLONG_MAX);
        dp[0] = 0;

        for (int u : topo_order) {
            // If we can't reach u, we can't go further from u
            if (dp[u] == LLONG_MAX) continue;

            // If u is an intermediate node and it's offline, skip processing its outgoing edges
            // (Start and End are always online per problem statement)
            if (u != 0 && u != n - 1 && !online[u]) continue;

            for (auto & edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;

                // ✅ CRITICAL FIX: Only consider edges with weight >= mid
                if (w < mid) continue;

                // Check if v is a valid node to visit
                // v is valid if it's the destination OR it's online
                if (v == n - 1 || online[v]) {
                    if (dp[u] + w < dp[v]) {
                        dp[v] = dp[u] + w;
                    }
                }
            }
        }

        return dp[n - 1] <= k;
    }

public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        // int m = edges.size(); // unused

        vector<vector<pair<int, int>>> adj(n);
        vector<int> inDegree(n, 0);

        for (auto & e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            inDegree[v]++;
        }

        // Topological Sort (Kahn's Algorithm)
        vector<int> topo_order;
        topo_order.reserve(n);
        queue<int> q;

        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo_order.push_back(u);
            for (auto & edge : adj[u]) {
                int v = edge.first;
                inDegree[v]--;
                if (inDegree[v] == 0) q.push(v);
            }
        }

        // Binary Search on the answer
        long long low = 0, high = 1e9; // Max edge cost
        int ans = -1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            // Optimization: If mid is 0, it's always possible if a path exists (cost >= 0)
            // But the logic holds for mid=0 too.
            
            if (check(mid, n, adj, online, k, topo_order)) {
                ans = (int)mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};